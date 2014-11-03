#include "Matrix.h"
#include "RegularMatrix.h"
#include "Array.h"
#include "RegularArray.h"
#include "Utility.h"
#include <memory>


RegularMatrix::RegularMatrix(double value, size_t nrow, size_t ncol){
	std::shared_ptr<Array<double>> newdata(new RegularArray<double>(value, nrow, ncol));
	data = newdata;
}
