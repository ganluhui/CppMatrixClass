// AbstractArray.cpp
//
// Base class for Array storage structure.
// A size_t is used for indexing. Indexing starts at 0.
//

/*
#ifndef __AbstractArray_cpp__
#define __AbstractArray_cpp__

#include "AbstractArray.h"

// Selectors
template <class V>
const V& AbstractArray<V>::Element(size_t index) const
{ // Get element at position

	// Use the subscript operator in derived classes
	return ((*this)[index]);

}

template <class V>
size_t AbstractArray<V>::MinIndex() const
{ // Return the minimum index

	// Always ONE
	return 1;
}

template <class V>
size_t AbstractArray<V>::MaxIndex() const
{ // Return the maximum index


	return Size();
}

// Modifiers
template <class V>
void AbstractArray<V>::Element(size_t index, const V& val)
{ // Change element at position

	// Use the subscript operator in derived classes
	(*this)[index] = val;
}

template <class V>
AbstractArray<V>& AbstractArray<V>::operator = (const AbstractArray<V>& source)
{ // Assignment operator

	return *this;
}

#endif
*/