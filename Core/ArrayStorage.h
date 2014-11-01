// ArrayStorage.hpp
//
// Base class for array storage structure.
// A size_t is used for indexing. Indexing starts at 1 in this class and its
// dervived classes. These derived classes must implement the indexing [] operator.
//

#ifndef ArrayStorage_h
#define ArrayStorage_h

using namespace std;

template <class V>
class ArrayStorage
{
public:
	// Constructors & destructor
	ArrayStorage();												// Default constructor
	ArrayStrorage(const ArrayStorage<V>& source);				// Copy constructor
	virtual ~ArrayStorage();								    // Destructor

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
};

#endif