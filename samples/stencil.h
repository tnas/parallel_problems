/* inclusion guard */
#ifndef __STENCIL_H__
#define __STENCIL_H__

#include <stdio.h>
#include <stdlib.h>

#define MESH_DIMENSION 10
#define STENCIL_DIMENSION 3

typedef int** mesh_t;
typedef int stencil_t[STENCIL_DIMENSION][STENCIL_DIMENSION];

static mesh_t mesh;
static stencil_t stencil;

void 	init_stencil();
double	run_stencil(int nthreads);
void 	destroy_stencil();
void	print_stencil();


#endif /* __STENCIL_H__ */
