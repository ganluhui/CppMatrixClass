#include <iostream>
#include <cstdlib>
#include "Array.h"
#include "RegularArray.h"
#include "Matrix.h"

int main(){

	Matrix arr1(1,5,5);
	Matrix arr2(5,5,5);
	Matrix arr3 = arr2 + arr1;

	//Print(arr1);
	//Print(arr2);
	
	return 0;
}