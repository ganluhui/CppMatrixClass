#ifndef BANDEDMATRIX_h
#define BANDEDMATRIX_h

#include "Matrix.h"

class BandedMatrix : public Matrix{
public:
	// constructor
	BandedMatrix(double, size_t, size_t, size_t);
};


#endif