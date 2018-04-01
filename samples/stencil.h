/* inclusion guard */
#ifndef __STENCIL_H__
#define __STENCIL_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MESH_DIMENSION 10000
#define STENCIL_DIMENSION 3

typedef double** mesh_t;
typedef int stencil_t[STENCIL_DIMENSION][STENCIL_DIMENSION];
typedef struct 
{
	int th_block_size;
	int weighted_divisor;
} stencil_operator_t;

static mesh_t mesh;
static stencil_t stencil;
static stencil_operator_t stencil_operator;

void 	init_stencil();
double	run_stencil(int nthreads);
void 	destroy_stencil();
void	print_stencil();


#endif /* __STENCIL_H__ */
