// Template class for normal matrices.
// A size_t is used for indexing. Indexing starts at 1.

/*
#ifndef RegularMatrixContainer_cpp
#define RegularMatrixContainer_cpp

#include "RegularMatrixContainer.h"

// Constructors & destructor
template <class V, class TA>
RegularMatrixContainer<V, TA>::RegularMatrixContainer() : AbstractMatrix<V>()
{ // Default constructor

	m_structure = RegularArrayContainer<RegularArrayContainer<V, TA>, std::allocator<RegularArrayContainer<V, TA> > >();

	nr = nc = 1;
}

template <class V, class TA>
RegularMatrixContainer<V, TA>::RegularMatrixContainer(size_t rows, size_t columns) : AbstractMatrix<V>()
{ // Constructor with size

	// Create the rows
	m_structure = RegularArrayContainer<RegularArrayContainer<V, TA>, std::allocator<RegularArrayContainer<V, TA> > >(rows);

	// Add the colums to the rows
	for (size_t i = 1; i <= m_structure.Size(); i++) m_structure[i] = RegularArrayContainer<V, TA>(columns);

	nr = rows; nc = columns;
}

template <class V, class TA>
RegularMatrixContainer<V, TA>::RegularMatrixContainer(const RegularMatrixContainer<V, TA>& source) : AbstractMatrix<V>(source)
{ // Copy constructor

	m_structure = source.m_structure;

	nr = source.nr; nc = source.nc;
}

template <class V, class TA>
RegularMatrixContainer<V, TA>::~RegularMatrixContainer()
{ // Destructor
}

// Selectors
template <class V, class TA>
size_t RegularMatrixContainer<V, TA>::Rows() const
{ // Number of rows

	return nr;
}

template <class V, class TA>
size_t RegularMatrixContainer<V, TA>::Columns() const
{ // Number of columns

	return nc;
}

// Modifiers
// Operators
template <class V, class TA>
AbstractArray<V>& RegularMatrixContainer<V, TA>::operator[] (size_t row)
{ // Subscripting operator

	return m_structure[row];
}

template <class V, class TA>
const AbstractArray<V>& RegularMatrixContainer<V, TA>::operator[] (size_t row) const
{ // Subscripting operator

	return m_structure[row];
}

template <class V, class TA>
RegularMatrixContainer<V, TA>& RegularMatrixContainer<V, TA>::operator = (const RegularMatrixContainer<V, TA>& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source) return *this;

	// Call base class assignment
	AbstractMatrix<V>::operator = (source);

	m_structure = source.m_structure;

	nr = source.nr; nc = source.nc;

	return *this;
}



#endif
*/