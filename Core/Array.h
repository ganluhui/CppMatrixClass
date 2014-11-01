// Array.h
//
// Array class. It is used for the actual storage of an Array.
// This class acts like a kind of adapter class since it defines a common 
// interface for different array structures like normal arrays and
// sparse arrays. The array structure to use is given as template argument.

#ifndef Array_h
#define Array_h

#include "ArrayStorage.h"
#include "RegularArray.cpp"

// Default structure is RegularArray with default allocator. Default integral type is int.
template <class V, class I = int, class S = RegularArray<V> >
class Array
{
private:
	S m_structure;			// The array structure
	I m_start;				// The start index

public:
	// Constructors & destructor
	Array();							// Default constructor
	Array(size_t size);					// Constructor with size. Start index=1.
	Array(size_t size, I start);		// Constructor with size & start index
	Array(size_t size, I start, const V& value);	// Size, start and value
	Array(const Array<V, I, S>& source);		// Copy constructor
	virtual ~Array();					// Destructor

	// Selectors
	I MinIndex() const;								// Return the minimum index
	I MaxIndex() const;								// Return the maximum index
	size_t Size() const;							// The size of the array

	// Operators
	virtual V& operator [] (I index);				// Subscripting operator
	virtual const V& operator [] (I index) const;	// Subscripting operator

	Array<V, I, S>& operator = (const Array<V, I, S>& source);
};

#endif