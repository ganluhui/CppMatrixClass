// ArrayStorage.cpp
//
// Base class for Array storage structure.
// A size_t is used for indexing. Indexing starts at 0.
//

#ifndef __ArrayStorage_cpp__
#define __ArrayStorage_cpp__

#include "ArrayStorage.h"

// Selectors
template <class V>
const V& ArrayStorage<V>::Element(size_t index) const
{ // Get element at position

	// Use the subscript operator in derived classes
	return ((*this)[index]);

}

template <class V>
size_t ArrayStorage<V>::MinIndex() const
{ // Return the minimum index

	// Always ONE
	return 1;
}

template <class V>
size_t ArrayStorage<V>::MaxIndex() const
{ // Return the maximum index


	return Size();
}

// Modifiers
template <class V>
void ArrayStorage<V>::Element(size_t index, const V& val)
{ // Change element at position

	// Use the subscript operator in derived classes
	(*this)[index] = val;
}

template <class V>
ArrayStorage<V>& ArrayStorage<V>::operator = (const ArrayStorage<V>& source)
{ // Assignment operator

	return *this;
}

#endif
