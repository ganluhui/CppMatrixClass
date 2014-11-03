// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"
#include "Matrix.h"
#include "RegularArray.h"
#include "RegularMatrix.h"
#include "Utility.h"

int _tmain(int argc, _TCHAR* argv[])
{
	RegularArray<double> arr1(5, 5);
	RegularArray<double> arr2(5, 5, 10);

	RegularMatrix A(1.0, 3, 4);
	return 0;
}

