#ifndef Matrix_h
#define Matrix_h

#include <memory>
#include <cstdlib>
#include "Array.h"
#include "RegularArray.h"

using namespace std;

class Matrix{
protected:
	std::shared_ptr<Array<double>> data;

public:
	// constructor
	Matrix(double, size_t, size_t); 
	Matrix(size_t, size_t);
	Matrix();
	~Matrix();
	
	virtual shared_ptr<Matrix> operator+ (Matrix&);
	virtual shared_ptr<Matrix> operator- (Matrix&);
	virtual shared_ptr<Matrix> operator* (Matrix&);
	virtual shared_ptr<Matrix> Transpose();
	virtual shared_ptr<Matrix> GetRow(size_t);
	virtual shared_ptr<Matrix> GetColumn(size_t);
	virtual double operator() (size_t, size_t);
	virtual void Change(double, size_t, size_t);
	virtual const size_t RowSize() const;
	virtual const size_t ColSize() const;

	virtual void Print();
};






#endif