#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
	static const int DEFAULT_SIZE;
	
	unsigned int dimension;
	double** elements;
	double sumElements;
	
public:
	Matrix();
	Matrix(unsigned int dim);
	~Matrix();
	void init();
	void loadDefaultElements();
	void setElement(const int row, const int col, double val);
	double getElement(const int row, const int col);
	double getSumOfElements();
	unsigned int getDimension();
	void print();
	void printSumOfElements();
};

#endif // MATRIX_H
