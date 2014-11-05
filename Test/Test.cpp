#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "BandedMatrix.h"

using namespace std;

int main(){
	
	// initialize 2 matrices
	shared_ptr<Matrix> M1(new Matrix(1.0, 3, 3));
	shared_ptr<Matrix> M2(new Matrix(2.0, 3, 3));

	// print M1
	M1->Print();
	cout << endl;
	M2->Print();

	// add M1 and M2, print
	shared_ptr<Matrix> M3 = *M1 + *M2;
	M3->Print();

	// add 2 banded matrices
	shared_ptr<Matrix> B1(new BandedMatrix(1.0, 3, 1, 0));
	shared_ptr<Matrix> B2(new BandedMatrix(2.0, 3, 0, 0));
	cout << endl << endl;
	B1->Print();
	B2->Print();
	shared_ptr<Matrix> B3 = *B1 + *B2;
	B3->Print();

	// Matrix + BandedMatrix
	shared_ptr<Matrix> M4 = *M1 + *B1;
	M4->Print();

	// BandedMatrix + Regular Matrix
	shared_ptr<Matrix> M5 = *B1 + *M1;
	M5->Print();

	// BandedMatrix + BandedMatrix
	shared_ptr<Matrix> B4 = *B3 + *B2;
	B4->Print();

	return 0;
}