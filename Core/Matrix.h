#ifndef Matrix_h
#define Matrix_h

#include <memory>
#include <cstdlib>
#include "Array.h"
#include "RegularArray.h"

class Matrix{
protected:
	std::shared_ptr<Array<double>> data;

public:
	// constructor
	Matrix(double, size_t, size_t); 
	Matrix(size_t, size_t);
	Matrix();
	~Matrix();
	
	Matrix operator+ (Matrix&);
	Matrix operator- (Matrix&);
	Matrix operator* (Matrix&);
	virtual Matrix Transpose();
	virtual Matrix GetRow(size_t);
	virtual Matrix GetColumn(size_t);
	virtual double operator() (size_t, size_t);
	virtual void Change(double, size_t, size_t);
	virtual const size_t RowSize() const;
	virtual const size_t ColSize() const;

	virtual void Print();
};






#endif