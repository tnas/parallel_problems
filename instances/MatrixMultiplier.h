#ifndef MATRIXMULTIPLIER_H
#define MATRIXMULTIPLIER_H

#include "Matrix.h"

class MatrixMultiplier
{
	Matrix* stMatrix;
	Matrix* ndMatrix;
	Matrix* product;
public:
	MatrixMultiplier(Matrix* stMatrix, Matrix* ndMatrix);
	~MatrixMultiplier();
	void multiply();
	Matrix* getProduct();
};

#endif // MATRIXMULTIPLIER_H
