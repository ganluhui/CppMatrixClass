#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(double value, size_t nrow, size_t ncol) : data(new RegularArray<double>(value, nrow, ncol)){

}

Matrix::Matrix(size_t nrow, size_t ncol) : data(new RegularArray<double>(nrow, ncol)){

}

Matrix::Matrix() : data(nullptr) {};

Matrix::~Matrix(){ std::cout << "\n\ndestructor of Matrix is called" << std::endl; }

shared_ptr<Matrix> Matrix::operator+ (Matrix& param){
	//Matrix temp(param.RowSize(), param.ColSize());
	shared_ptr<Matrix> temp(new Matrix(param.RowSize(), param.ColSize()));
	if (param.RowSize() == (*this).RowSize() && param.ColSize() == (*this).ColSize()){
		for (size_t row_index = 1; row_index <= (*this).RowSize(); row_index++){
			for (size_t col_index = 1; col_index <= (*this).ColSize(); col_index++){
				temp->Change((*this)(row_index, col_index) + param(row_index, col_index), row_index, col_index);
			}
		}
		cout << "Matrix + Matrix is called." << endl;
		return temp;
	
	}
	else{
		std::cout << "\nThe size of matrices must match!!!\n" << std::endl;
		return nullptr;
	}
	
}

shared_ptr<Matrix> Matrix::operator- (Matrix& param){
	shared_ptr<Matrix> temp(new Matrix(param.RowSize(), param.ColSize()));
	if (param.RowSize() == (*this).RowSize() && param.ColSize() == (*this).ColSize()){
		for (size_t row_index = 1; row_index <= (*this).RowSize(); row_index++){
			for (size_t col_index = 1; col_index <= (*this).ColSize(); col_index++){
				temp->Change((*this)(row_index, col_index) - param(row_index, col_index), row_index, col_index);
			}
		}
		cout << "Matrix - Matrix is called." << endl;
		return temp;

	}
	else{
		std::cout << "\nThe size of matrices must match!!!\n" << std::endl;
		return nullptr;
	}

}

shared_ptr<Matrix> Matrix::operator* (Matrix& param){
	//Matrix temp((*this).RowSize(), param.ColSize());
	shared_ptr<Matrix> temp(new Matrix(this->RowSize(), param.ColSize()));
	if ((*this).ColSize() == param.RowSize()){
		for (size_t row_index = 1; row_index <= (*this).RowSize(); row_index++){
			for (size_t col_index = 1; col_index <= param.ColSize(); col_index++){
				for (size_t inner = 1; inner <= (*this).ColSize(); inner++) {
					temp->Change((*temp)(row_index, col_index) +
						(*this)(row_index, inner) * param(inner, col_index),
						row_index, col_index);
				}
			}
		}
		cout << "Matrix*Matrix is called." << endl;
		return temp;

	}
	else{
		std::cout << "\nThe column size of the first matrix should be the same as the row size of the second matrix!!!\n" << std::endl;
	}
	
}

shared_ptr<Matrix> Matrix::Transpose(){
	//Matrix temp(data->ColSize(), data->RowSize());
	shared_ptr<Matrix> temp(new Matrix(this->ColSize(), this->RowSize()));
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		for (size_t col_index = 1; col_index <= (data->ColSize()); col_index++){
			temp->Change((*data)(row_index, col_index), col_index, row_index);
		}
	}
	cout << "Matrix transpose is called." << endl;
	return temp;
}

shared_ptr<Matrix> Matrix::GetRow(size_t row){
	//Matrix temp(1, data->ColSize());
	shared_ptr<Matrix> temp(new Matrix(1, this->ColSize()));
	for (size_t col_index = 1; col_index <= (data->ColSize()); col_index++){
		temp->Change((*data)(row, col_index), 1, col_index);

	}
	cout << "Matrix row returned." << endl;
	return temp;
}

shared_ptr<Matrix> Matrix::GetColumn(size_t col){
	//Matrix temp(data->RowSize(), 1);
	shared_ptr<Matrix> temp(new Matrix(this->RowSize(), 1));
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		temp->Change((*data)(row_index, col), row_index, 1);

	}
	cout << "Matrix column returned." << endl;
	return temp;
}

double Matrix::operator() (size_t nr, size_t nc){
	return data->operator()(nr,nc);

}

void Matrix::Print(){
	data->Print();
}

void Matrix::Change(double value, size_t row, size_t col){
	data->Change(value, row, col);
}

const size_t Matrix::RowSize() const{
	return data->RowSize();
}

const size_t Matrix::ColSize() const{
	return data->ColSize();
}