#include "Matrix.h"

Matrix::Matrix(double value, size_t nrow, size_t ncol) : data(new RegularArray<double>(value, nrow, ncol)){
	//std::cout << "\n\nconstructor of RegularArray is called" << std::endl;
	//(*data).Print();
}

Matrix::Matrix(size_t nrow, size_t ncol) : data(new RegularArray<double>(nrow, ncol)){
	//std::cout << "\n\nconstructor of RegularArray is called" << std::endl;
	//(*data).Print();
}

Matrix::Matrix() : data(nullptr) {};

Matrix::~Matrix(){ std::cout << "\n\ndestructor of Matrix is called" << std::endl; }

Matrix& Matrix::operator+ (Matrix& param){
	Matrix temp((param.data)->RowSize(), (param.data)->ColSize());
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		for (size_t col_index = 1; col_index <= (data->ColSize()); col_index++){
			(temp.data)->Change((*data)(row_index, col_index) + (*(param.data))(row_index, col_index), row_index, col_index);
		}
	}
	(temp.data)->Print();
	return temp;

}

Matrix& Matrix::operator- (Matrix& param){
	Matrix temp((param.data)->RowSize(), (param.data)->ColSize());
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		for (size_t col_index = 1; col_index <= (data->ColSize()); col_index++){
			(temp.data)->Change((*data)(row_index, col_index) - (*(param.data))(row_index, col_index), row_index, col_index);
		}
	}
	(temp.data)->Print();
	return temp;
}

Matrix& Matrix::operator* (Matrix& param){
	Matrix temp(data->RowSize(), (param.data)->ColSize());
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		for (size_t col_index = 1; col_index <= ((param.data)->ColSize()); col_index++){
			for (size_t inner = 1; inner <= data->ColSize(); inner++) {
				//(*(temp.data))(row_index, col_index) += (*data)(row_index, inner) * (*(param.data))(inner, col_index);
				(temp.data)->Change((*(temp.data))(row_index, col_index) +
					(*data)(row_index, inner) * (*(param.data))(inner, col_index),
					row_index, col_index);
			}
		}
	}
	(temp.data)->Print();
	return temp;
}

Matrix& Matrix::Transpose(){
	Matrix temp(data->ColSize(), data->RowSize());
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		for (size_t col_index = 1; col_index <= (data->ColSize()); col_index++){
			(temp.data)->Change((*data)(row_index, col_index), col_index, row_index);
		}
	}
	(temp.data)->Print();
	return temp;
}

Matrix& Matrix::GetRow(size_t row){
	Matrix temp(1, data->ColSize());
	for (size_t col_index = 1; col_index <= (data->ColSize()); col_index++){
		(temp.data)->Change((*data)(row, col_index), 1, col_index);

	}
	(temp.data)->Print();
	return temp;
}

Matrix& Matrix::GetColumn(size_t col){
	Matrix temp(data->RowSize(), 1);
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		(temp.data)->Change((*data)(row_index, col), row_index, 1);

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
