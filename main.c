#include "samples/sum_vector.h"

int main(int argc, char **argv) {

	int num_threads = 4;
	double elapsed_time;
	
	init_operator();
	elapsed_time = sum_vector(num_threads);
	printf("Number of threads: %d - Elapsed Time: %lf\n", num_threads, elapsed_time);
	destroy_operator();
    
    return 0;
}
