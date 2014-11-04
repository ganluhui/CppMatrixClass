#ifndef Matrix_h
#define Matrix_h

#include <memory>
#include <cstdlib>
#include "Array.h"
#include "RegularArray.h"

class Matrix{
protected:
	std::shared_ptr<Array<double>> data;

public:
	// constructor
	Matrix(double, size_t, size_t); 
	Matrix(size_t, size_t);
	~Matrix();
	
	virtual Matrix operator+ (Matrix&);
	//virtual Matrix operator- (Matrix&);
	//virtual Matrix operator* (Matrix&);
	//virtual Matrix Transpose();
	//virtual Matrix& GetRow();
	//virtual Matrix& GetColumn();
};

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
	Matrix temp((param.data)->RowSize(),(param.data)->ColSize());
	for (size_t row_index = 1; row_index <= (data->RowSize()); row_index++){
		for (size_t col_index = 1; col_index <= (data->ColSize()); col_index++){
			(temp.data)->Change((*data)(row_index, col_index) + (*(param.data))(row_index, col_index), row_index, col_index);
		}
	}
	(temp.data)->Print();
	return temp;
	
}

/*
Matrix Matrix::operator- (Matrix& param){
	Matrix temp;
	for (size_t row_index = 1; row_index <= (*data).RowSize(); row_index++){
		for (size_t col_index = 1; col_index <= (*data).ColSize(); col_index++){
			(*(temp.data))(row_index, col_index) = (*data)(row_index, col_index) - (*(param.data))(row_index, col_index);
		}
	}
	return temp;
}

Matrix Matrix::operator* (Matrix& param){
	Matrix temp;
	for (size_t row_index = 1; row_index <= (*data).RowSize(); row_index++){
		for (size_t col_index = 1; col_index <= (*data).ColSize(); col_index++){
			for (size_t inner = 1; inner <= (*data).RowSize(); inner++) {
				(*(temp.data))(row_index, col_index) += (*data)(row_index, inner) * (*(param.data))(inner, col_index);
			}
		}
	}
	return temp;
}

Matrix Matrix::Transpose(){
	Matrix temp;
	for (size_t row_index = 1; row_index <= (*data).RowSize(); row_index++){
		for (size_t col_index = 1; col_index <= (*data).ColSize(); col_index++){
			(*(temp.data))(col_index, row_index) = (*data)(row_index, col_index);
		}
	}
	return temp;
}
*/

#endif