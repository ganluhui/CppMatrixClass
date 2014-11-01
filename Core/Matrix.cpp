// Matrix class. It is used as an actual storage for matrix.
// This class acts like a kind of adapter class since it defines a common interface
// for different matrix structures like normal matrices and sparse matrices.
// The matrix structure to use is given as template argument.

#ifndef Matrix_cpp
#define Matrix_cpp

#include "Matrix.h"
#include <stddef.h>


// Constructors & destructor
template <class V, class I, class S>
Matrix<V, I, S>::Matrix()
{ // Default constructor

	m_structure = S();

	m_rowstart = 1;
	m_columnstart = 1;

	nr = nc = 1;
}

template <class V, class I, class S>
Matrix<V, I, S>::Matrix(size_t rows, size_t columns)
{ // Constructor with size. Start index=1.

	m_structure = S(rows, columns);

	m_rowstart = 1;
	m_columnstart = 1;

	nr = rows; nc = columns;
}

template <class V, class I, class S>
Matrix<V, I, S>::Matrix(size_t rows, size_t columns, I rowStart, I columnStart)
{ // Constructor with size & start index

	m_structure = S(rows, columns);

	m_rowstart = rowStart;
	m_columnstart = columnStart;

	nr = rows; nc = columns;
}

template <class V, class I, class S>
Matrix<V, I, S>::Matrix(const Matrix<V, I, S>& source)
{ // Copy constructor

	m_structure = source.m_structure;

	m_rowstart = source.m_rowstart;
	m_columnstart = source.m_columnstart;

	nr = source.nr; nc = source.nc;
}

template <class V, class I, class S>
Matrix<V, I, S>::~Matrix()
{ // Destructor
}

// Selectors
template <class V, class I, class S>
I Matrix<V, I, S>::MinRowIndex() const
{ // Return the minimum row index

	return m_rowstart;
}

template <class V, class I, class S>
I Matrix<V, I, S>::MaxRowIndex() const
{ // Return the maximum row index

	return m_rowstart + Rows() - 1;
}

template <class V, class I, class S>
I Matrix<V, I, S>::MinColumnIndex() const
{ // Return the minimum column index

	return m_columnstart;
}

template <class V, class I, class S>
I Matrix<V, I, S>::MaxColumnIndex() const
{ // Return the maximum column index

	return m_columnstart + Columns() - 1;
}

template <class V, class I, class S>
size_t Matrix<V, I, S>::Rows() const
{ // The number of rows

	return nr;
}

template <class V, class I, class S>
size_t Matrix<V, I, S>::Columns() const
{ // The number of columns

	return nc;
}





// Operators
template <class V, class I, class S>
const V& Matrix<V, I, S>::operator () (I row, I column) const
{ // Get the element at position


	return m_structure[row - m_rowstart + 1][column - m_columnstart + 1];
}

template <class V, class I, class S>
V& Matrix<V, I, S>::operator () (I row, I column)
{ // Get the element at position

	return m_structure[row - m_rowstart + 1][column - m_columnstart + 1];
}

template <class V, class I, class S>
Matrix<V, I, S>& Matrix<V, I, S>::operator = (const Matrix<V, I, S>& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source) return *this;

	m_structure = source.m_structure;

	m_rowstart = source.m_rowstart;
	m_columnstart = source.m_columnstart;

	nr = source.nr; nc = source.nc;


	return *this;
}

#endif
