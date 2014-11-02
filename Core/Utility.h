#ifndef Utility_h
#define Utility_h

#include<iostream>
#include<cstdlib>

template <class T, class TA = std::allocator<T>>
void print(RegularArray<T, TA>& m){
	std::cout << "\n\nRow Size:" << m.RowSize() << std::endl;
	std::cout << "Column Size: " << m.ColSize() << std::endl;
	std::cout << "\nArray: [";
	for (size_t row_index = 1; row_index <= m.RowSize(); row_index++){
		std::cout << "\nRow" << row_index << "(";
		for (size_t col_index = 1; col_index <= m.ColSize(); col_index++){
			std::cout << m(row_index, col_index) << " , ";

		}
		std::cout << ")";

	}
	std::cout << "]";
};

#endif