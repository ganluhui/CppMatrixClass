#ifndef RegularArray_h
#define RegularArray_h

#include "Array.h"
template <class T, class TA = std::allocator<T>>
class RegularArray : public Array<T> {
protected:
	size_t nrow;
	size_t ncol;
	std::vector<T, TA> m_Array;
public:
	// constructor, destructor
	RegularArray();
	RegularArray(size_t, size_t);
	RegularArray(T, size_t, size_t);
	RegularArray(const RegularArray<T, TA>&);
	virtual ~RegularArray();

	// selector
	virtual const size_t RowSize() const;
	virtual const size_t ColSize() const;

	// modifier
	virtual void Change(T, size_t, size_t);

	// operators
	virtual T& operator() (std::size_t, std::size_t);

	// print
	void print();

};

template<class T, class TA>
RegularArray<T, TA>::RegularArray()
{
	nrow = 1;
	ncol = 1;
	m_Array = vector<T, TA>(1);
};

template<class T, class TA>
RegularArray<T, TA>::RegularArray(size_t nr, size_t nc)
{
	nrow = nr;
	ncol = nc;
	size_t size = nr*nc;
	m_Array = std::vector<T, TA>(size);
};

template<class T, class TA>
RegularArray<T, TA>::RegularArray(T val, size_t nr, size_t nc)
{
	nrow = nr;
	ncol = nc;
	size_t size = nr*nc;
	(*this).m_Array.assign(size, val);
};

template <class T, class TA>
RegularArray<T, TA>::RegularArray(const RegularArray<T, TA>& source)
{
	nrow = source.nrow;
	ncol = source.ncol;
	m_Array = source.m_Array;
};

template <class T, class TA>
RegularArray<T, TA>::~RegularArray()
{
};

template <class T, class TA>
const size_t RegularArray<T, TA>::RowSize() const
{
	return (*this).nrow;
};

template <class T, class TA>
const size_t RegularArray<T, TA>::ColSize() const
{
	return (*this).ncol;
};

template <class T, class TA>
void RegularArray<T, TA>::Change(T val, size_t nr, size_t nc)
{
	m_Array[(nr - 1)*ncol + nc] = val;
};

template <class T, class TA>
T& RegularArray<T, TA>::operator() (size_t nr, size_t nc)
{
	return m_Array[(nr - 1)*ncol + nc - 1];
};

template <class T, class TA>
void RegularArray<T, TA>::print(){
	std::cout << "\n\nRow Size:" << (*this).RowSize() << std::endl;
	std::cout << "Column Size: " << (*this).ColSize() << std::endl;
	std::cout << "\nArray: [";
	for (size_t row_index = 1; row_index <= (*this).RowSize(); row_index++){
		std::cout << "\nRow" << row_index << "(";
		for (size_t col_index = 1; col_index <= (*this).ColSize(); col_index++){
			std::cout << (*this)(row_index, col_index) << " , ";

		}
		std::cout << ")";

	}
	std::cout << "]";
};

#endif