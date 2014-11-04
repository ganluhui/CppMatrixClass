#include "Matrix.h"

Matrix::Matrix() : data(nullptr) {};

Matrix::Matrix(double value, size_t nrow, size_t ncol) : data(new RegularArray<double>(value, nrow, ncol)){
	std::cout << "\n\nconstructor of RegularArray is called" << std::endl;
	(*data).Print();
}

Matrix::Matrix(size_t nrow, size_t ncol) : data(new RegularArray<double>(nrow, ncol)){
	std::cout << "\n\nconstructor of RegularArray is called" << std::endl;
	(*data).Print();
}

Matrix::~Matrix(){}

Matrix Matrix::operator+ (Matrix& param){
	Matrix temp((param.data)->RowSize(), (param.data)->ColSize());
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		for (size_t col_index = 1; col_index <= (data->ColSize()); col_index++){
			(temp.data)->Change((*data)(row_index, col_index) + (*(param.data))(row_index, col_index), row_index, col_index);
		}
	}
	(temp.data)->Print();
	return temp;

}

void Matrix::Print(){
	data->Print();
}

void Matrix::Change(double value, size_t row, size_t col){
	data->Change(value, row, col);
}