#include "RegularMatrix.h"
#include "Array.h"
#include "RegularArray.h"
#include "Utility.h"
#include <memory>

RegularMatrix::RegularMatrix(double value, size_t nrow, size_t ncol) :
data(new RegularArray<double>(value, nrow, ncol));
