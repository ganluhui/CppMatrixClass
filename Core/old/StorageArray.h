#ifndef __AbstractArray_h__
#define __AbstractArray_h__

#include<iostream>
#include<cstdlib>
#include<vector>

template <class T>
class AbstractArray
{

public:
	//constructor, destructor
	//StorageArray();
	//StorageArray(const StorageArray &);
	//StorageArray & operator= (const StorageArray &);
	//~StorageArray();

	//selector
	virtual const std::size_t Size() const = 0;

	//modifier
	virtual void Change(const T, std::size_t, std::size_t) = 0;

	//operator
	virtual T& operator() (std::size_t,std::size_t) = 0;

};

#endif