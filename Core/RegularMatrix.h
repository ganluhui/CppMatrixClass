// RegularMatrix.h
//
// Template class for normal matrices.
// A size_t is used for indexing. Indexing starts at 1.

#ifndef RegularMatrix_h
#define RegularMatrix_h

#include "MatrixStorage.cpp"
#include "RegularArray.h"


template <class TValue, class TA = std::allocator<TValue> >
class RegularMatrix : public MatrixStorage<TValue>
{
	RegularArray<RegularArray<TValue, TA>, std::allocator<RegularArray<TValue, TA> > > m_structure;

	// Redundant data 
	size_t nr, nc;

public:
	// Constructors & destructor
	RegularMatrix();													// Default constructor
	RegularMatrix(size_t rows, size_t columns);						// Constructor with size
	RegularMatrix(const RegularMatrix<TValue, TA>& source);				// Copy constructor
	virtual ~RegularMatrix();											// Destructor

	// Selectors
	virtual size_t Rows() const;									// Number of rows
	virtual size_t Columns() const;									// Number of columns

	// Modifiers

	// Operators
	virtual ArrayStructure<TValue>& operator[] (size_t index);					// Subscripting operator
	virtual const ArrayStructure<TValue>& operator[] (size_t index) const;		// Subscripting operator

	RegularMatrix<TValue, TA>& operator = (const RegularMatrix<TValue, TA>& source);
};



#endif