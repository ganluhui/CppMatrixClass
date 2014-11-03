#ifndef REGULARMATRIX_h
#define REGULARMATRIX_h

#include "Matrix.h"

class RegularMatrix : public Matrix{
public:
	RegularMatrix(double, size_t, size_t);
	void Print();
};

#endif