#include "MatrixMultiplier.h"
#include <stdio.h>
#include <omp.h>

MatrixMultiplier::MatrixMultiplier(Matrix* stMatrix, Matrix* ndMatrix)
{
	this->stMatrix = stMatrix;
	this->ndMatrix = ndMatrix;
	this->product = new Matrix(stMatrix->getDimension());
}


MatrixMultiplier::~MatrixMultiplier()
{
	product->~Matrix();
}


double MatrixMultiplier::multiply(int num_threads)
{
	unsigned int dim = this->product->getDimension();
	double elementVal;
	double init_time;

	omp_set_num_threads(num_threads);
	
	init_time = omp_get_wtime();
	
	#pragma omp parallel for private(elementVal)
	for (int row = 0; row < dim; ++row)
	{
		for (int col = 0; col < dim; ++col)
		{
			elementVal = 0;
			
			for (int prd = 0; prd < dim; ++prd)
			{
				elementVal += stMatrix->getElement(row, prd) *
					ndMatrix->getElement(prd, col);
			}
			
			product->setElement(row, col, elementVal);
		}
	}
	
	return omp_get_wtime() - init_time;
}


double MatrixMultiplier::optimizedMultiply(int num_threads)
{
	unsigned int j, dim = this->product->getDimension();
	double elementVal, fixed;
	double init_time;

	omp_set_num_threads(num_threads);
	
	init_time = omp_get_wtime();
	
	#pragma omp parallel for private(elementVal,fixed,j)
	for (unsigned int i = 0; i < dim; ++i)
	{
		for (unsigned int k = 0; k < dim; ++k)
		{
			elementVal = 0;
			fixed      = stMatrix->getElement(i, k);
			
			for (j = 0; j < dim; ++j)
			{
				elementVal += fixed * ndMatrix->getElement(k, j);
			}
			
			product->setElement(i, j, elementVal);
		}
	}
	
	return omp_get_wtime() - init_time;
}


Matrix* MatrixMultiplier::getProduct()
{
	return this->product;
}

