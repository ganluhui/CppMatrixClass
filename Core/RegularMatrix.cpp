// Template class for normal matrices.
// A size_t is used for indexing. Indexing starts at 1.

#ifndef RegularMatrix_cpp
#define RegularMatrix_cpp

#include "RegularMatrix.h"

// Constructors & destructor
template <class V, class TA>
RegularMatrix<V, TA>::RegularMatrix() : MatrixStorage<V>()
{ // Default constructor

	m_structure = RegularArray<RegularArray<V, TA>, std::allocator<RegularArray<V, TA> > >();

	nr = nc = 1;
}

template <class V, class TA>
RegularMatrix<V, TA>::RegularMatrix(size_t rows, size_t columns) : MatrixStorage<V>()
{ // Constructor with size

	// Create the rows
	m_structure = RegularArray<RegularArray<V, TA>, std::allocator<RegularArray<V, TA> > >(rows);

	// Add the colums to the rows
	for (size_t i = 1; i <= m_structure.Size(); i++) m_structure[i] = RegularArray<V, TA>(columns);

	nr = rows; nc = columns;
}

template <class V, class TA>
RegularMatrix<V, TA>::RegularMatrix(const RegularMatrix<V, TA>& source) : MatrixStorage<V>(source)
{ // Copy constructor

	m_structure = source.m_structure;

	nr = source.nr; nc = source.nc;
}

template <class V, class TA>
RegularMatrix<V, TA>::~RegularMatrix()
{ // Destructor
}

// Selectors
template <class V, class TA>
size_t RegularMatrix<V, TA>::Rows() const
{ // Number of rows

	return nr;
}

template <class V, class TA>
size_t RegularMatrix<V, TA>::Columns() const
{ // Number of columns

	return nc;
}

// Modifiers
// Operators
template <class V, class TA>
ArrayStructure<V>& RegularMatrix<V, TA>::operator[] (size_t row)
{ // Subscripting operator

	return m_structure[row];
}

template <class V, class TA>
const ArrayStructure<V>& RegularMatrix<V, TA>::operator[] (size_t row) const
{ // Subscripting operator

	return m_structure[row];
}

template <class V, class TA>
RegularMatrix<V, TA>& RegularMatrix<V, TA>::operator = (const RegularMatrix<V, TA>& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source) return *this;

	// Call base class assignment
	MatrixStorage<V>::operator = (source);

	m_structure = source.m_structure;

	nr = source.nr; nc = source.nc;

	return *this;
}



#endif
