#include <iostream>
#include <algorithm>
#include <math.h>
#include "vectoroperator.h"

using namespace std;

const long VectorOperator::SIZE_VECTOR = pow(2, 27);


VectorOperator::VectorOperator()
{
	st_vector = new int[SIZE_VECTOR];
	nd_vector = new int[SIZE_VECTOR];
	result    = new int[SIZE_VECTOR];
	
	for (int pos = 0; pos < SIZE_VECTOR; ++pos)
	{
		st_vector[pos] = nd_vector[pos] = 1;
		result[pos]    = 0;
	}
}

VectorOperator::~VectorOperator()
{
	delete(st_vector);
	delete(nd_vector);
	delete(result);
}


void VectorOperator::sum()
{
	for (int pos = 0; pos < SIZE_VECTOR; ++pos)
	{
		result[pos] = st_vector[pos] + nd_vector[pos];
	}
}


void VectorOperator::print_result(long size)
{
	int limit = min(SIZE_VECTOR, size);

	for (int pos = 0; pos < limit; ++pos)
	{
		cout << result[pos] << " ";
	}
	
	cout << endl;
}




