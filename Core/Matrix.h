#ifndef Matrix_h
#define Matrix_h

#include <memory>
#include "Array.h"

class Matrix{
private:
	std::shared_ptr<Array<double>> data;
public:
	virtual Matrix& operator+ (Matrix&);
	virtual Matrix& operator- (Matrix&);
	virtual Matrix& operator* (Matrix&);
	virtual Matrix& Transpose();
	virtual Matrix& GetRow();
	virtual Matrix& GetColumn();
};

#endif