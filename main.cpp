#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "samples/problems.h"
// #include "samples/sum_vector.h"
// #include "samples/stencil.h"
#include "instances/Matrix.h"
#include "instances/MatrixMultiplier.h"

using namespace std;

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
// 		case SUM_VECTOR :
// 			init_operator();
// 			elapsed_time = sum_vector(num_threads);
// 			printf("[Sum of Vector] Threads: %d - Elapsed Time: %lf\n", num_threads, elapsed_time);
// 			destroy_operator();
// 			break;
// 			
// 		case STENCIL :
// 			init_stencil();
// 			elapsed_time = run_stencil(num_threads);
// 			printf("[Stencil] Threads: %d - Elapsed Time: %lf\n", num_threads, elapsed_time);
// 			destroy_stencil();
// 			break;
			
		case MATRIX_MULTIPLICATION :
			
			Matrix* stMatrix = new Matrix();
			stMatrix->init();
			stMatrix->loadDefaultElements();
			
			Matrix* ndMatrix = new Matrix();
			ndMatrix->init();
			ndMatrix->loadDefaultElements();
			
			MatrixMultiplier multiplier = 
				MatrixMultiplier(stMatrix, ndMatrix);
			
			elapsed_time = multiplier.multiply(num_threads);
			
			Matrix* product = multiplier.getProduct();
			
			product->printSumOfElements();
			cout << "Elapsed time: " << elapsed_time << endl;
			
			stMatrix->~Matrix();
			ndMatrix->~Matrix();
				
			break;
	}
	
    
	return 0;
}
