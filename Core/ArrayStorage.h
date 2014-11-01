#ifndef __ArrayStorage_h__
#define __ArrayStorage_h__

template<class V>
class ArrayStorage
{
public:

	// Selectors
	virtual size_t Size() const = 0;						    // Size of the array, pure virtual function
	const V& Element(size_t index) const;						// Get element at position

	size_t MinIndex() const;									// Return the minimum index == 1
	size_t MaxIndex() const;									// Return the maximum index == size

	// Modifiers
	void Element(size_t index, const V& val);					// Change element at position

	// Operators
	virtual V& operator[] (size_t index) = 0;
	virtual const V& operator[] (size_t index) const = 0;
	ArrayStorage<V>& operator= (const ArrayStorage<V>& source);
}

#endif