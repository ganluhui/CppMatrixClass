#ifndef AbstractArray_h
#define AbstractArray_h

template<class V>
class AbstractArray
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
	AbstractArray<V>& operator= (const AbstractArray<V>& source);
};


// Selectors
template <class V>
const V& AbstractArray<V>::Element(size_t index) const
{ // Get element at position

	// Use the subscript operator in derived classes
	return ((*this)[index]);

}

template <class V>
size_t AbstractArray<V>::MinIndex() const
{ // Return the minimum index

	// Always ONE
	return 1;
}

template <class V>
size_t AbstractArray<V>::MaxIndex() const
{ // Return the maximum index


	return Size();
}

// Modifiers
template <class V>
void AbstractArray<V>::Element(size_t index, const V& val)
{ // Change element at position

	// Use the subscript operator in derived classes
	(*this)[index] = val;
}

template <class V>
AbstractArray<V>& AbstractArray<V>::operator = (const AbstractArray<V>& source)
{ // Assignment operator

	return *this;
}


#endif