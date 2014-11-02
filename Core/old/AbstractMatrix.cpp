// Base class for matrix storage structure.
// A size_t is used for indexing. Indexing starts at 1.

/*
#ifndef AbstractMatrix_cpp
#define AbstractMatrix_cpp

#include "AbstractMatrix.h"


// Constructors & destructor
template <class V>
AbstractMatrix<V>::AbstractMatrix()
{ // Default constructor
}

template <class V>
AbstractMatrix<V>::AbstractMatrix(const AbstractMatrix<V>& source)
{ // Copy constructor
}

template <class V>
AbstractMatrix<V>::~AbstractMatrix()
{ // Destructor
}

// Selectors
template <class V>
const V& AbstractMatrix<V>::Element(size_t row, size_t column) const
{ // Get element at position

	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

template <class V>
size_t AbstractMatrix<V>::MinRowIndex() const
{ // Return the minimum row index

	// Always ONE
	return 1;
}

template <class V>
size_t AbstractMatrix<V>::MaxRowIndex() const
{ // Return the maximum row index

	// Always row size . use the Rows() function of derived classes
	return Rows();
}

template <class V>
size_t AbstractMatrix<V>::MinColumnIndex() const
{ // Return the minimum column index

	// Always ONE
	return 1;
}

template <class V>
size_t AbstractMatrix<V>::MaxColumnIndex() const
{ // Return the maximum column index

	// Always column size. use the Columns() function of derived classes
	return Columns();
}

// Modifiers
template <class V>
void AbstractMatrix<V>::Element(size_t row, size_t column, const V& val)
{ // Change element at position


	// Use the subscripting operator of derived class
	(*this)[row][column] = val;
}

// Operators
template <class V>
AbstractMatrix<V>& AbstractMatrix<V>::operator = (const AbstractMatrix<V>& source)
{ // Assignment operator

	return *this;
}

template <class V>
V& AbstractMatrix<V>::operator () (size_t row, size_t column)
{ // Get element at position


	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

template <class V>
const V& AbstractMatrix<V>::operator () (size_t row, size_t column) const
{ // Get element at position


	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

#endif
*/