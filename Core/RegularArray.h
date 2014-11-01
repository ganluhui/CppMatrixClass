// Template class for a non-sparse arrays.

#ifndef RegularArray_h
#define RegularArray_h

// Use the STL vector class
#include <vector>
#include "ArrayStorage.cpp"


template <class V, class TA = std::allocator<V> >
class RegularArray : public ArrayStorage<V>
{
private:
	std::vector<V, TA> m_vector;								// Use STL vector class for storage

public:
	// Constructors & destructor
	RegularArray();
	RegularArray(size_t size);
	RegularArray(const RegularArray<V, TA>& source);
	virtual ~RegularArray();

	// Selectors
	virtual size_t Size() const;

	// Modifiers

	// Operators
	V& operator[] (size_t index);
	const V& operator[] (size_t index) const;

	RegularArray<V, TA>& operator = (const RegularArray<V, TA>& source);
};


#endif