#ifndef VECTOROPERATOR_H
#define VECTOROPERATOR_H

class VectorOperator
{
	int* st_vector;
	int* nd_vector;
	int* result;
	
public:
	static const long SIZE_VECTOR;
	
	VectorOperator();
	~VectorOperator();
	void sum();
	void print_result(long int size);
};



#endif // VECTOROPERATOR_H
