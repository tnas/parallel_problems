#include "sum_vector.h"

#ifdef __cplusplus
extern "C" {
#endif

void init_operator()
{
	vec_operator.st_vector = malloc(VECTOR_SIZE * sizeof(int));
	vec_operator.nd_vector = malloc(VECTOR_SIZE * sizeof(int));
	vec_operator.result    = malloc(VECTOR_SIZE * sizeof(int));
	
	for (int pos = 0; pos < VECTOR_SIZE; ++pos)
	{
		vec_operator.st_vector[pos] = vec_operator.nd_vector[pos] = 1;
		vec_operator.result[pos]    = 0;
	}
}


void* sum(void *arg) 
{
	int seq_tid = (intptr_t) arg;
	int th_ini_block = vec_operator.block_size * seq_tid;
	int th_end_block = th_ini_block + vec_operator.block_size;
	th_end_block = th_end_block > VECTOR_SIZE ? VECTOR_SIZE : th_end_block;
	
	for (int pos = th_ini_block; pos < th_end_block; ++pos)
	{
		vec_operator.result[pos] = 
			vec_operator.st_vector[pos] + vec_operator.nd_vector[pos];
	}
}


double sum_vector(int nthreads)
{
	struct timespec start, finish;
	double elapsed;
	pthread_t threads[nthreads];
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	
	vec_operator.block_size = VECTOR_SIZE / nthreads;
	
	for (int nth = 0; nth < nthreads; ++nth)
	{
		pthread_create(&threads[nth], NULL, sum, (void *) (intptr_t) nth);
	}
	
	for (int nth = 0; nth < nthreads; ++nth)
	{
		pthread_join(threads[nth], NULL);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &finish);
	
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	
	return elapsed;
}


void print_vector(long int size)
{
	int limit = size < VECTOR_SIZE ? size : VECTOR_SIZE;

	for (int pos = 0; pos < limit; ++pos)
	{
		printf("%d ", vec_operator.result[pos]);
	}
	
	printf("\n");
}


void destroy_operator()
{
	free(vec_operator.st_vector);
	free(vec_operator.nd_vector);
	free(vec_operator.result);
}

#ifdef __cplusplus
}
#endif
