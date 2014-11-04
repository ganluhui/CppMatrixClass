#include "BandedMatrix.h"
#include "BandedArray.h"
#include <memory>
#include <iostream>

BandedMatrix::BandedMatrix(double value, size_t dim, size_t up, size_t low){
	std::shared_ptr<BandedArray<double>> newdata(new BandedArray<double>(value, dim, up, low));
	data = newdata;
}

BandedMatrix::BandedMatrix(size_t dim, size_t up, size_t low) : BandedMatrix(1.0, dim, up, low){};

Matrix BandedMatrix::operator+ (Matrix& source){
	if (typeid(source).name() == typeid(BandedMatrix).name()){
		std::cout << "Input is a BandedMatrix";
		BandedMatrix temp = dynamic_cast<BandedMatrix&> (source);
	}
	else 
		std::cout << "Input is not a BandedMatrix" << std::endl;
	
	return(this->Matrix::operator+ (source));
}

size_t BandedMatrix::Upper() { 
	std::shared_ptr<BandedArray<double>> data2 = dynamic_cast<BandedArray<double>&>(data);
	return data->Upper(); 
}