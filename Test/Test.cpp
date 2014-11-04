#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "BandedMatrix.h"
#include "BandedArray.h"

int main(){
	//BandedMatrix arr1(1, 5, 1, 1);
	//std::cout << arr1(5, 3);
	//BandedMatrix arr2(2, 5, 0, 0);
	
	Matrix arr3(1.0, 5, 5);
	Matrix arr4(2.0, 5, 5);
	Matrix arr5 = arr3 + arr4;
	//arr1 + arr2;
	//delete arr3;

	return 0;
}