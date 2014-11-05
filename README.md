CppMatrixClass
==============

BSIFG C++ Project: Matrix Class 

BSFIG Training Group C++ Project
Team Member: Luhui, Tianyi, Pengfei, Le Yan
===========================================
1. Introduction
1.1. The purpose of our project is to create a cpp class to perform computations for matrix with numeric elements. Matrix computation is closely related to financial engineering applications.

1.2. The matrix forms considered in our project are full matrix and banded matrix.

1.3. The matrix operations considered in our project are +, -, *, transpose.

1.4. We use class template, polymorphism and smart pointer features to achieve mantainance/expansion needs. The methods of matrices class are implemented via polymorphism of array classes. The matrix operators are called for specific matrix shape via polymorphism of both matrix and array classes. It is easy to reuse our codes to add new matrix types and matrix operations.
=========================================================================
2. Delievered Codes:

-- Header Files:

Array.h, RegualrArray.h, BandedArray.h, Matrix.h, BandedMatrix.h

-- CPP Files:

Matrix.h, BandedMatrix.h
========================
3. Design:

3.1. "Array" is an abstract class template which provides following interfaces (pure virtual functions):

3.1.1. Data Members: none.

3.1.2. Methods:

RowSize(): interface for function returns the row size of the array;
ColSize(): interface for function returns the column size of the array;
Change(): interface for function modifies selected element of the array;
(): interface for function return selected element of the array;
Print(): interface for function prints the array.

3.2. "RegularArray" is a real class template derived from Array to store full matrix with following members:

3.2.1. Data Members: nrow; ncol; std::vector.

3.2.2. Methods: 

constructors and destructors;
RowSize();
ColSize();
Change();
();
Print().

3.3. "BandedArray" is a real class template derived from Array to store banded matrix with following members:

3.3.1. Data Members: dimension; upper; lower; std::vector.

3.3.2. Methods: 

constructors and destructors;
RowSize();
ColSize();
Change();
();
Print().

Extra methods for banded matrix:

Upper();
Lower();

Array, RegularArray and BandedArray are realized using class template. This allows us to generate arrays with different element types without rewriting the codes.

3.4. "Matrix" is a real class for full numeric matrix with following members:

3.4.1. Data Members: std::shared_ptr<Array<double>>.

We use shared_ptr to utilize polymorphism features and take care of memory leak problems.

3.4.2. Methods: 

constructors and destructors;
RowSize();
ColSize();
Change();
();
Print();
GetRow();
GetColumn();
+;
-;
*;
Transpose().
 
3.5. "BandedMatrix" is a real class for banded numeric matrix derived from class "Matrix" with following members:

3.5.1. Data Members: none

3.5.2. Methods (realized using the methods defined for banded array via polymorphism of Arrays):

constructors and destructors;
+;
Upper();
Lower() 

We only implement operator "+" in the "BandedMatrix" since other methods can be done similarly. 
