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
	double multiply(int num_threads);
	Matrix* getProduct();
};

#endif // MATRIXMULTIPLIER_H
