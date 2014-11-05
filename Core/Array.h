// Abstract class provide interface with specific shape of arrays, e.g. regular, banded, sparse...
#ifndef __Array_h__
#define __Array_h__

#include<iostream>
#include<cstdlib>
#include<vector>
#include<numeric>
#include<algorithm>

template <class T>
class Array
{

public:

	//selector
	virtual const std::size_t RowSize() const = 0; // get row size of array
	virtual const std::size_t ColSize() const = 0; // get column size of array

	//modifier
	virtual void Change(T, std::size_t, std::size_t) = 0; // modify array element at specific location

	//operator
	virtual T operator() (std::size_t,std::size_t) = 0; // element query

	// Print
	virtual void Print() = 0; // print the array

};

#endif