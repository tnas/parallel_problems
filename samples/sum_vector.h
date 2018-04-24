/* inclusion guard */
#ifndef __SUM_VECTOR_H__
#define __SUM_VECTOR_H__
#include <math.h>
#include <stdint.h>
#include "stdlib.h"
#include "pthread.h"
#include "stdio.h"
#include "time.h"

#define VECTOR_SIZE pow(2, 27)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct  
{
	int block_size;
	int* st_vector;
	int* nd_vector;
	int* result;
} vector_operator;

static vector_operator vec_operator;

void 	init_operator	();
void 	destroy_operator();
double	sum_vector	(int nthreads);
void	print_vector	(long int size);

#ifdef __cplusplus
}
#endif

#endif /* __SUM_VECTOR_H__ */

