#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "problems.h"
#include "pthreads/sum_vector.h"
#include "pthreads/stencil.h"
#include "openmp/Matrix.h"
#include "openmp/MatrixMultiplier.h"

using namespace std;


/* *****************************************************
 * Program Parameters:
 * 
 * -p <algorithm>:
 * 	0: Sum of vectors
 * 	1: Stencil
 * 	2: Matrix Multiplication
 * 
 * -t <number of threads>
 * 
 * *****************************************************
 */

int main(int argc, char **argv) {

	int opt, num_threads, problem;
	double elapsed_time;
	
	while ((opt = getopt(argc, argv, "t:p:")) != -1)
	{
		switch (opt)
		{
			case 'p' :
				problem = atoi(optarg);
				break;		
				
			case 't':
				num_threads = atoi(optarg);
				break;
		}
	}
	
	switch (problem)
	{
		case SUM_VECTOR :
			init_operator();
			elapsed_time = sum_vector(num_threads);
			printf("[Sum of Vector] Threads: %d - Elapsed Time: %lf\n", num_threads, elapsed_time);
			destroy_operator();
			break;
			
		case STENCIL :
			init_stencil();
			elapsed_time = run_stencil(num_threads);
			printf("[Stencil] Threads: %d - Elapsed Time: %lf\n", num_threads, elapsed_time);
			destroy_stencil();
			break;
			
		case MATRIX_MULTIPLICATION :
			
			Matrix* stMatrix = new Matrix();
			stMatrix->loadDefaultElements();
			
			Matrix* ndMatrix = new Matrix();
			ndMatrix->loadDefaultElements();
			
			MatrixMultiplier multiplier = 
				MatrixMultiplier(stMatrix, ndMatrix);
			
			elapsed_time = multiplier.multiply(num_threads);
			Matrix* product = multiplier.getProduct();
			product->printSumOfElements();
			printf("Elapsed time: %.6lf secs\n\n", elapsed_time);
			
			elapsed_time = multiplier.optimizedMultiply(num_threads);
			product = multiplier.getProduct();
			product->printSumOfElements();
			printf("Elapsed time (optimized): %.6lf secs", elapsed_time);
			
			stMatrix->~Matrix();
			ndMatrix->~Matrix();
				
			break;
	}
    
	return 0;
}
