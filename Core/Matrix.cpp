#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(double value, size_t nrow, size_t ncol) : data(new RegularArray<double>(value, nrow, ncol)){

}

Matrix::Matrix(size_t nrow, size_t ncol) : data(new RegularArray<double>(nrow, ncol)){

}

Matrix::Matrix() : data(nullptr) {};

Matrix::~Matrix(){}

shared_ptr<Matrix> Matrix::operator+ (Matrix& param){
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
	shared_ptr<Matrix> temp(new Matrix((*this).ColSize(), (*this).RowSize()));
	for (size_t row_index = 1; row_index <= ((*this).RowSize()); row_index++){
		for (size_t col_index = 1; col_index <= ((*this).ColSize()); col_index++){
			temp->Change((*this)(row_index, col_index), col_index, row_index);
		}
	}
	cout << "Matrix transpose is called." << endl;
	return temp;
}

shared_ptr<Matrix> Matrix::GetRow(size_t row){
	shared_ptr<Matrix> temp(new Matrix(1, (*this).ColSize()));
	for (size_t col_index = 1; col_index <= ((*this).ColSize()); col_index++){
		temp->Change((*this)(row, col_index), 1, col_index);

	}
	cout << "Matrix row returned." << endl;
	return temp;
}

shared_ptr<Matrix> Matrix::GetColumn(size_t col){
	shared_ptr<Matrix> temp(new Matrix((*this).RowSize(), 1));
	for (size_t row_index = 1; row_index <= ((*this).RowSize()); row_index++){
		temp->Change((*this)(row_index, col), row_index, 1);

	}
	cout << "Matrix column returned." << endl;
	return temp;
}

double Matrix::operator() (size_t nr, size_t nc){
	return data->operator()(nr,nc);

}

void Matrix::Print(){
	cout << typeid(*this).name() << endl;
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