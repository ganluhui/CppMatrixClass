// Template class for a non-sparse arrays.

/*
#ifndef RegularArrayContainer_cpp
#define RegularArrayContainer_cpp

#include "RegularArrayContainer.h"

// Constructors & destructor
template <class V, class TA>
RegularArrayContainer<V, TA>::RegularArrayContainer() : AbstractArray<V>()
{ // Default constructor

	m_vector = std::vector<V, TA>(1);	// vector object with 1 element
}

template <class V, class TA>
RegularArrayContainer<V, TA>::RegularArrayContainer(size_t size) : AbstractArray<V>()
{ // Constructor with size

	m_vector = std::vector<V, TA>(size);
}

template <class V, class TA>
RegularArrayContainer<V, TA>::RegularArrayContainer(const RegularArrayContainer<V, TA>& source) : AbstractArray<V>(source)
{ // Copy constructor

	m_vector = source.m_vector;
}

template <class V, class TA>
RegularArrayContainer<V, TA>::~RegularArrayContainer()
{ // Destructor
}

// Selectors
template <class V, class TA>
size_t RegularArrayContainer<V, TA>::Size() const
{ // Size of the array

	return m_vector.size();
}


// Modifiers

// Operators
template <class V, class TA>
V& RegularArrayContainer<V, TA>::operator[] (size_t index)
{ // Subscripting operator


	return m_vector[index - 1];
}

template <class V, class TA>
const V& RegularArrayContainer<V, TA>::operator[] (size_t index) const
{ // Subscripting operator


	return m_vector[index - 1];
}

template <class V, class TA>
RegularArrayContainer<V, TA>& RegularArrayContainer<V, TA>::operator = (const RegularArrayContainer<V, TA>& source)
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
*/