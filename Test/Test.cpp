#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "BandedMatrix.h"


int main(){
	Matrix arr1(1, 5, 5);
	Matrix arr2(5, 5, 5);
	Matrix arr3 = arr2 + arr1;
	arr3.Print();

	BandedMatrix arr4(1.0, 4, 1, 1);
	arr4.Print();
	arr4.Change(2.0, 1, 1);
	arr4.Print();
	//Print(arr1);
	//Print(arr2);
	return 0;
}