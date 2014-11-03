#ifndef Matrix_h
#define Matrix_h

#include <memory>
#include "Array.h"

class Matrix{
protected:
	std::shared_ptr<Array<double>> data;
public:
	virtual Matrix& operator+ (Matrix&);
	virtual Matrix& operator- (Matrix&);
	virtual Matrix& operator* (Matrix&);
	virtual Matrix& transpose();
	virtual Matrix& getrow();
	virtual Matrix& getcolumn();
};

#endif