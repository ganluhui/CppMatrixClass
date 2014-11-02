//
//  BandedArray.h
//  BandMatrix
//
//  Created by Luhui Gan on 2014-11-01.
//  Copyright (c) 2014 Luhui Gan. All rights reserved.
//

#ifndef BandedArray_BandedArray_h
#define BandedArray_BandedArray_h
#include <vector>
#include <cstdlib>
#include <iostream>

template<class T>
class BandedArray{
private:
	size_t dimension;
	size_t upper;
	size_t lower;
	std::vector<T> elements;
public:
	// constructor & destructor
	BandedArray<T>(T, size_t, size_t, size_t);
	//BandedArray<T>(size_t, size_t, size_t);

	// selector
	T operator() (size_t, size_t);

	// change element
	void Change(T, size_t, size_t);

	// prsize_t
	void Print();

	// size
	size_t RowSize();
	size_t ColumnSize();
};

template<class T>
BandedArray<T>::BandedArray(T value, size_t dim, size_t up, size_t low) : dimension(dim), upper(up), lower(low){
	if (upper >= dimension || lower >= dimension)
		std::cout << "Warning: degrees of off-diagonal cannot exceed dimension!" << std::endl;
	size_t dim2 = upper + lower + 1;
	std::vector<T> elements0(dimension*dim2);
	for (size_t d = 0; d<dimension; d++){
		for (size_t i = 0; i < dim2; i++){
			if ((d + i) >= lower && (d + i) < (dimension + lower)) elements0[d*dim2 + i] = value;
		}
	}
	elements = elements0;
}

template<class T>
T BandedArray<T>::operator() (size_t i, size_t j){
	if (j > i + upper || j + lower < i) return 0;
	else { return elements[(i - 1)*(upper + lower + 1) + j - i + lower]; }
}

template<class T>
void BandedArray<T>::Change(T value, size_t i, size_t j){
	if (j <= i + upper && j >= i - lower){
		elements[(i - 1)*(upper + lower + 1) + j - i + lower] = value;
	}
}

template<class T>
void BandedArray<T>::Print(){
	for (size_t i = 1; i <= dimension; i++){
		for (size_t j = 1; j <= dimension; j++){
			std::cout << this->operator() (i, j) << " ";
		}
		std::cout << std::endl;
	}
}

template<class T>
size_t BandedArray<T>::RowSize(){
	return dimension;
}

template<class T>
size_t BandedArray<T>::ColumnSize(){
	return dimension;
}

#endif
