// Template class for a non-sparse arrays.

#ifndef RegularArray_cpp
#define RegularArray_cpp

#include "RegularArray.h"

// Constructors & destructor
template <class V, class TA>
RegularArray<V, TA>::RegularArray() : ArrayStorage<V>()
{ // Default constructor

	m_vector = std::vector<V, TA>(1);	// vector object with 1 element
}

template <class V, class TA>
RegularArray<V, TA>::RegularArray(size_t size) : ArrayStorage<V>()
{ // Constructor with size

	m_vector = std::vector<V, TA>(size);
}

template <class V, class TA>
RegularArray<V, TA>::RegularArray(const RegularArray<V, TA>& source) : ArrayStorage<V>(source)
{ // Copy constructor

	m_vector = source.m_vector;
}

template <class V, class TA>
RegularArray<V, TA>::~RegularArray()
{ // Destructor
}

// Selectors
template <class V, class TA>
size_t RegularArray<V, TA>::Size() const
{ // Size of the array

	return m_vector.size();
}


// Modifiers

// Operators
template <class V, class TA>
V& RegularArray<V, TA>::operator[] (size_t index)
{ // Subscripting operator


	return m_vector[index - 1];
}

template <class V, class TA>
const V& RegularArray<V, TA>::operator[] (size_t index) const
{ // Subscripting operator


	return m_vector[index - 1];
}

template <class V, class TA>
RegularArray<V, TA>& RegularArray<V, TA>::operator = (const RegularArray<V, TA>& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source) return *this;

	// Call base class constructor
	ArrayStructure<V>::operator = (source);

	// Copy the embedded vector
	m_vector = source.m_vector;

	return *this;
}


#endif