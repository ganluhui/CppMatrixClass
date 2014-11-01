#ifndef __StorageArray_h__
#define __StorageArray_h__
#include<cstdlib>

class StorageArray
{

public:
	//constructor, destructor
	StorageArray();
	StorageArray(const StorageArray &);
	StorageArray & operator= (const StorageArray &);
	~StorageArray();

	//selector
	virtual const std::size_t Size() const = 0;
	virtual const double Element(std::size_t, double) const = 0;

	//modifier
	virtual void Element(std::size_t,const double) = 0;

	//operator
	virtual double& operator() (std::size_t,std::size_t) = 0;

};



#endif