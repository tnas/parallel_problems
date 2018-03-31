#include "samples/sum_vector.h"
#include "samples/stencil.h"

int main(int argc, char **argv) {

	int num_threads = 4;
	double elapsed_time;
	
// 	init_operator();
// 	elapsed_time = sum_vector(num_threads);
// 	printf("[Sum of Vector] Threads: %d - Elapsed Time: %lf\n", num_threads, elapsed_time);
// 	destroy_operator();
	
	init_stencil();
	elapsed_time = run_stencil(num_threads);
	printf("[Stencil] Threads: %d - Elapsed Time: %lf\n", num_threads, elapsed_time);
	print_stencil();
	destroy_stencil();
    
    return 0;
}
