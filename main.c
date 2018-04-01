#include <unistd.h>
#include "samples/problems.h"
#include "samples/sum_vector.h"
#include "samples/stencil.h"


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
	}
	
    
	return 0;
}
