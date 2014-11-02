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
	virtual const std::size_t RowSize() const = 0;
	virtual const std::size_t ColSize() const = 0;

	//modifier
	virtual void Change(T, std::size_t, std::size_t) = 0;

	//operator
	virtual T& operator() (std::size_t,std::size_t) = 0;

};

#endif