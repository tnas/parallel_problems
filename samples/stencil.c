#include "stencil.h"

void init_stencil()
{
	stencil[0][0] = stencil[0][2] =
	stencil[2][0] = stencil[2][2] = 2;
	stencil[1][0] = stencil[1][1] = 
	stencil[1][2] = 1;
	stencil[0][1] = stencil[2][1] = 0;
	
	mesh = malloc(MESH_DIMENSION * sizeof(int*));
	for (int row = 0; row < MESH_DIMENSION; ++row)
	{
		mesh[row] = malloc(MESH_DIMENSION * sizeof(int));
		
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


double run_stencil(int nthreads)
{

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
			printf("%d ", mesh[row][col]);
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


