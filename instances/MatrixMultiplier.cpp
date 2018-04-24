#include "MatrixMultiplier.h"
#include <stdio.h>

MatrixMultiplier::MatrixMultiplier(Matrix* stMatrix, Matrix* ndMatrix)
{
	this->stMatrix = stMatrix;
	this->ndMatrix = ndMatrix;
	this->product = new Matrix(stMatrix->getDimension());
	this->product->init();
}


MatrixMultiplier::~MatrixMultiplier()
{
	product->~Matrix();
}


void MatrixMultiplier::multiply()
{
	unsigned int dim = this->product->getDimension();
	double elementVal;
	
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
}

Matrix* MatrixMultiplier::getProduct()
{
	return this->product;
}

