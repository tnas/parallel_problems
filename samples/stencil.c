#include "stencil.h"

void init_stencil()
{
	stencil[0][0] = stencil[0][2] =
	stencil[2][0] = stencil[2][2] = 2;
	stencil[1][0] = stencil[1][1] = 
	stencil[1][2] = 1;
	stencil[0][1] = stencil[2][1] = 0;
	
	stencil_operator.weighted_divisor = 0;
	for (int row = 0; row < STENCIL_DIMENSION; ++row)
	{
		for (int col = 0; col < STENCIL_DIMENSION; ++col)
		{
			stencil_operator.weighted_divisor +=
				stencil[row][col];
		}
	}
	
	mesh = malloc(MESH_DIMENSION * sizeof(double*));
	for (int row = 0; row < MESH_DIMENSION; ++row)
	{
		mesh[row] = malloc(MESH_DIMENSION * sizeof(double));
		
		for (int col = 0; col < MESH_DIMENSION; ++col) 
		{
			mesh[row][col] = 0;
		}
	}
	
	for (int col = 0; col < MESH_DIMENSION; ++col) 
	{
		mesh[0][col] = 100;
	}
}


double get_element(const int mesh_row, const int mesh_col)
{
	double element = 0;
	
	for (int row = 0; row < STENCIL_DIMENSION; ++row)
	{
		for (int col = 0; col < STENCIL_DIMENSION; ++col)
		{
			element += stencil[row][col] * 
				mesh[mesh_row - 1 + row][mesh_col - 1 + col];
		}
	}
	
	return element / stencil_operator.weighted_divisor;
}


void* create_element(void* arg)
{
	int seq_tid = (intptr_t) arg;
	
	int th_ini_block = stencil_operator.th_block_size * seq_tid;
	th_ini_block = th_ini_block == 0 ? 1 : th_ini_block;
	
	int th_end_block = th_ini_block + stencil_operator.th_block_size;
	th_end_block = th_end_block >= MESH_DIMENSION ? MESH_DIMENSION - 1 : th_end_block;
	
	
	for (int row = th_ini_block; row < th_end_block; ++row)
	{
		for (int col = 1; col < MESH_DIMENSION - 1; ++col)
		{
			mesh[row][col] = get_element(row, col);
		}
	}
}


double run_stencil(int nthreads)
{
	struct timespec start, finish;
	double elapsed;
	pthread_t threads[nthreads];
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	
	stencil_operator.th_block_size = MESH_DIMENSION / nthreads;
	
	for (int nth = 0; nth < nthreads; ++nth)
	{
		pthread_create(&threads[nth], NULL, create_element, (void *) (intptr_t) nth);
	}
	
	for (int nth = 0; nth < nthreads; ++nth)
	{
		pthread_join(threads[nth], NULL);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &finish);
	
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

}


void print_stencil()
{
	printf("Stencil Matrix:\n");
	for (int row = 0; row < STENCIL_DIMENSION; ++row)
	{
		for (int col = 0; col < STENCIL_DIMENSION; ++col)
		{
			printf("%d ", stencil[row][col]);
		}
		printf("\n");
	}
	
	printf("Mesh Matrix:\n");
	for (int row = 0; row < MESH_DIMENSION; ++row)
	{
		for (int col = 0; col < MESH_DIMENSION; ++col)
		{
			printf("%lf ", mesh[row][col]);
		}
		printf("\n");
	}

}


void destroy_stencil()
{
	for (int row = 0; row < MESH_DIMENSION; ++row)
	{
		free(mesh[row]);
	}
	
	free(mesh);
}


