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

BandedMatrix BandedMatrix::operator+ (BandedMatrix& source){
	cout << "BandedMatrix + BandedMatrix is called." << endl;
	BandedMatrix temp = dynamic_cast<BandedMatrix&> (source);

	int dimension = temp.RowSize();
	int upper = max(temp.Upper(), this->Upper());
	int lower = max(temp.Lower(), this->Lower());

	BandedMatrix lhs(dimension, upper, lower);

	int j_mat;
	for (int i = 1; i <= dimension; i++){
		for (int j = 1; j <= upper + lower + 1; j++){
			j_mat = i - lower + j;
			if (j_mat > 0 && j_mat <= dimension)
				lhs.Change(temp(i, j_mat) + this->operator()(i, j_mat), i, j_mat);
		}
	}
	return lhs;
}

Matrix BandedMatrix::operator+ (Matrix& rhs){
	cout << "BandedMatrix + Matrix is called" << endl;
	return this->Matrix::operator+ (rhs);
}

BandedMatrix BandedMatrix::operator- (BandedMatrix& source){
	cout << "BandedMatrix - BandedMatrix is called." << endl;
	BandedMatrix temp = dynamic_cast<BandedMatrix&> (source);

	int dimension = temp.RowSize();
	int upper = max(temp.Upper(), this->Upper());
	int lower = max(temp.Lower(), this->Lower());

	BandedMatrix lhs(dimension, upper, lower);

	int j_mat;
	for (int i = 1; i <= dimension; i++){
		for (int j = 1; j <= upper + lower + 1; j++){
			j_mat = i - lower + j;
			if (j_mat > 0 && j_mat <= dimension)
				lhs.Change(temp(i, j_mat) - this->operator()(i, j_mat), i, j_mat);
		}
	}
	return lhs;
}

Matrix BandedMatrix::operator- (Matrix& rhs){
	cout << "BandedMatrix - Matrix is called" << endl;
	return this->Matrix::operator- (rhs);
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