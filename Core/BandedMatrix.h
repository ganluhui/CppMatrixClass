#ifndef BANDEDMATRIX_h
#define BANDEDMATRIX_h
#include "Matrix.h"

class BandedMatrix : public Matrix{
public:
	// constructor
	BandedMatrix(double, size_t, size_t, size_t); 
	BandedMatrix(size_t, size_t, size_t); // default value is 1

	// override operator "+" in the base class Matrix
	virtual Matrix operator+ (Matrix&); // override "+" in base class Matrix

	// return upper and lower in its data (BandedArray)
	size_t Upper();
	size_t Lower();
};
#endif