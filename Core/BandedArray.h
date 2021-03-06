//
//  BandedArray.h
//
//  Created by Luhui Gan on 2014-11-01.
//  Copyright (c) 2014 Luhui Gan. All rights reserved.
//

#ifndef BandedArray_BandedArray_h
#define BandedArray_BandedArray_h
#include <vector>
#include <cstdlib>
#include <iostream>
#include "Array.h"

template<class T>
class BandedArray: public Array<T>{
private:
	size_t dimension;
	size_t upper;
	size_t lower;
	std::vector<T> elements;
public:
	// constructor & destructor
	BandedArray<T>(T, size_t, size_t, size_t);

	// override selector
	T operator() (size_t, size_t);

	// override change element
	void Change(T, size_t, size_t);

	// override base fucntion to print
	void Print();

	// override base function for row size and column size
	const size_t RowSize() const;
	const size_t ColSize() const;

	// return upper and lower
	size_t Upper();
	size_t Lower();
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
	std::cout << "Row Size:" << this->RowSize() << std::endl;
	std::cout << "Column Size:" << this->ColSize() << std::endl;
	for (size_t i = 1; i <= dimension; i++){
		std::cout << "Row" << i << " (";
		for (size_t j = 1; j <= dimension; j++){
			std::cout << this->operator() (i, j);
			if (j < dimension) std::cout << ", ";
		}
		std::cout << ")";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<class T>
const size_t BandedArray<T>::RowSize() const{
	return dimension;
}

template<class T>
const size_t BandedArray<T>::ColSize() const{
	return dimension;
}

template<class T>
size_t BandedArray<T>::Upper() {
	return upper;
}

template<class T>
size_t BandedArray<T>::Lower() {
	return lower;
}

#endif
