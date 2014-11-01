// Array.cpp
//
// Array class. It is used as actual storage of Array.
// This class acts like a kind of adapter since it defines a common interface
// for different array structures like normal arrays and sparse arrays.
// The array structure to use is given as template argument.

#ifndef Array_cpp
#define Array_cpp

#include "Array.h"

// Constructors & destructor
template <class V, class I, class S>
Array<V, I, S>::Array()
{ // Default constructor

	m_structure = S();
	m_start = 1;
}

template <class V, class I, class S>
Array<V, I, S>::Array(size_t size)
{ // Constructor with size. Start index=1.

	m_structure = S(size);
	m_start = 1;
}

template <class V, class I, class S>
Array<V, I, S>::Array(size_t size, I start)
{ // Constructor with size & start index

	m_structure = S(size);
	m_start = start;
}

template <class V, class I, class S>
Array<V, I, S>::Array(size_t size, I start, const V& value)
{ // Constructor with size & start index

	m_structure = S(size);
	m_start = start;

	// Initialise array elements
	for (I i = MinIndex(); i <= MaxIndex(); i++) (*this)[i] = value;
}


template <class V, class I, class S>
Array<V, I, S>::Array(const Array<V, I, S>& source)
{ // Copy constructor

	m_structure = source.m_structure;
	m_start = source.m_start;
}

template <class V, class I, class S>
Array<V, I, S>::~Array()
{ // Destructor
}

// Selectors
template <class V, class I, class S>
I Array<V, I, S>::MinIndex() const
{ // Return the minimum index

	return m_start;
}

template <class V, class I, class S>
I Array<V, I, S>::MaxIndex() const
{ // Return the maximum index

	return m_start + Size() - 1;
}

template <class V, class I, class S>
size_t Array<V, I, S>::Size() const
{ // The size of the array

	return m_structure.Size();
}



// Operators
template <class V, class I, class S>
V& Array<V, I, S>::operator [] (I index)
{ // Subscripting operator

	return m_structure[index - m_start + 1];
}

template <class V, class I, class S>
const V& Array<V, I, S>::operator [] (I index) const
{ // Subscripting operator

	return m_structure[index - m_start + 1];
}

template <class V, class I, class S>
Array<V, I, S>& Array<V, I, S>::operator = (const Array<V, I, S>& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source) return *this;

	m_structure = source.m_structure;
	m_start = source.m_start;

	return *this;
}


#endif