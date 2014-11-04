#include "Array.h"
#include "Matrix.h"
#include "BandedMatrix.h"
#include "BandedArray.h"
#include <memory>
#include <iostream>

using namespace std;

BandedMatrix::BandedMatrix(double value, size_t dim, size_t up, size_t low){
	std::shared_ptr<BandedArray<double>> newdata(new BandedArray<double>(value, dim, up, low));
	data = newdata;
}

BandedMatrix::BandedMatrix(size_t dim, size_t up, size_t low) : BandedMatrix(1.0, dim, up, low){};

Matrix& BandedMatrix::operator+ (Matrix& source){
	if (typeid(source).name() == typeid(BandedMatrix).name()){
		std::cout << "Input is a BandedMatrix";
		BandedMatrix temp = dynamic_cast<BandedMatrix&> (source);
		
		size_t dimension = temp.data->RowSize();
		size_t upper = max(temp.Upper(), this->Upper());
		size_t lower = max(temp.Lower(), this->Lower());
		
		/*BandedMatrix lhs(dimension, upper, lower);
		for (int i = 1; i <= dimension; i++){
			for (int j = 1; j <= upper + lower + 1; j++){
				size_t j_mat = i - lower + j;
				if (j_mat > 0 && j_mat <= dimension) lhs.Change()
			}
		}*/

	}
	else 
		std::cout << "Input is not a BandedMatrix" << std::endl;
	
	return(this->Matrix::operator+ (source));
}

size_t BandedMatrix::Upper() { 
	std::shared_ptr<BandedArray<double>> data2;
	data2 = std::dynamic_pointer_cast<BandedArray<double>>(data);
	return data2->Upper(); 
}

size_t BandedMatrix::Lower() {
	std::shared_ptr<BandedArray<double>> data2;
	data2 = std::dynamic_pointer_cast<BandedArray<double>>(data);
	return data2->Upper();
}