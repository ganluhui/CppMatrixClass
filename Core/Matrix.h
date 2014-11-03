#ifndef Matrix_h
#define Matrix_h

#include <memory>
#include "Array.h"
#include <cstdlib>

class Matrix{
protected:
	//Array<double>* data;
	std::shared_ptr<Array<double>> data;
public:
	// constructor
	//Matrix(double, size_t, size_t);

	// operator
	//virtual Matrix& operator+ (Matrix&);
	//virtual Matrix& operator- (Matrix&);
	//virtual Matrix& operator* (Matrix&);
	//// other functions
	//virtual Matrix& transpose();
	//virtual Matrix& getrow();
	//virtual Matrix& getcolumn();
};

#endif