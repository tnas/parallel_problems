#include "Matrix.h"
#include <iostream>

using namespace std;

const int Matrix::DEFAULT_SIZE = 1500;


Matrix::Matrix()
{
	this->dimension = DEFAULT_SIZE;
	this->init();
}


Matrix::Matrix(unsigned int dim)
{
	this->dimension = dim;
	this->init();
}


void Matrix::init()
{
	this->sumElements = 0;
	
	elements = new double*[dimension];
	
	for (int row = 0; row < dimension; ++row)
	{
		elements[row] = new double[dimension];
		
		for (int col = 0; col < dimension; ++col)
		{
			elements[row][col] = 0;
		}
	}
}


void Matrix::loadDefaultElements()
{
	for (int row = 0; row < dimension; ++row)
	{
		elements[row] = new double[dimension];
		
		for (int col = 0; col < dimension; ++col)
		{
			elements[row][col] = row + col;
		}
	}
}



void Matrix::setElement(const int row, const int col, double val)
{
	this->elements[row][col] = val;
}


double Matrix::getElement(const int row, const int col)
{
	return this->elements[row][col];
}


void Matrix::print()
{
	cout << "Dimension: " << this->dimension << endl;
	
	for (int row = 0; row < dimension; ++row)
	{
		for (int col = 0; col < dimension; ++col)
		{
			cout << elements[row][col] << " ";
		}
		
		cout << endl;
	}
}


unsigned int Matrix::getDimension()
{
	return this->dimension;
}


double Matrix::getSumOfElements()
{
	this->sumElements = 0;
	
	for (int row = 0; row < dimension; ++row)
	{
		for (int col = 0; col < dimension; ++col)
		{
			sumElements += elements[row][col];
		}
	}
	
	return this->sumElements;
}


void Matrix::printSumOfElements()
{
	cout << "Sum of all elements: " << 
		this->getSumOfElements() << endl;
}


Matrix::~Matrix()
{
	for (int row = 0; row < this->dimension; ++row)
	{
		delete(elements[row]);
	}
}





