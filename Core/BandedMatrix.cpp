#include "BandedMatrix.h"
#include "BandedArray.h"
#include <memory>

BandedMatrix::BandedMatrix(double value, size_t dim, size_t up, size_t low){
	std::shared_ptr<BandedArray<double>> newdata(new BandedArray<double>(value, dim, up, low));
	data = newdata;
}