// Base class for matrix storage structure.
// A size_t is used for indexing. Indexing starts at 1.

#ifndef MatrixStorage_cpp
#define MatrixStorage_cpp

#include "MatrixStorage.h"


// Constructors & destructor
template <class V>
MatrixStorage<V>::MatrixStorage()
{ // Default constructor
}

template <class V>
MatrixStorage<V>::MatrixStorage(const MatrixStorage<V>& source)
{ // Copy constructor
}

template <class V>
MatrixStorage<V>::~MatrixStorage()
{ // Destructor
}

// Selectors
template <class V>
const V& MatrixStorage<V>::Element(size_t row, size_t column) const
{ // Get element at position

	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

template <class V>
size_t MatrixStorage<V>::MinRowIndex() const
{ // Return the minimum row index

	// Always ONE
	return 1;
}

template <class V>
size_t MatrixStorage<V>::MaxRowIndex() const
{ // Return the maximum row index

	// Always row size . use the Rows() function of derived classes
	return Rows();
}

template <class V>
size_t MatrixStorage<V>::MinColumnIndex() const
{ // Return the minimum column index

	// Always ONE
	return 1;
}

template <class V>
size_t MatrixStorage<V>::MaxColumnIndex() const
{ // Return the maximum column index

	// Always column size. use the Columns() function of derived classes
	return Columns();
}

// Modifiers
template <class V>
void MatrixStorage<V>::Element(size_t row, size_t column, const V& val)
{ // Change element at position


	// Use the subscripting operator of derived class
	(*this)[row][column] = val;
}

// Operators
template <class V>
MatrixStorage<V>& MatrixStorage<V>::operator = (const MatrixStorage<V>& source)
{ // Assignment operator

	return *this;
}

template <class V>
V& MatrixStorage<V>::operator () (size_t row, size_t column)
{ // Get element at position


	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

template <class V>
const V& MatrixStorage<V>::operator () (size_t row, size_t column) const
{ // Get element at position


	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

#endif