#include <cstdlib>
#include "Array.h"
#include "RegularArray.h"
#include "Utility.h"

int main(){

	RegularArray<double> arr1(5,5);
	RegularArray<double> arr2(5,5,10);

	print(arr1);
	print(arr2);
	
	return 0;
}