//
//  Matrix.h
//  
//

#ifndef Matrix_Matrix_h
#define Matrix_Matrix_h

# include <vector>

class Matrix {
private:
	int nrow; // number of rows
	int ncol; // number of columns
	double determinant;
	bool isInvert; // True if it is invertible, False otherwise
	std::vector<double> elements;
public:
	Matrix(double, int, int); // constructor 1
	Matrix(std::vector<double>, int, int); // constructor 2
	
	Matrix operator + (const Matrix&) const; // define Matrix + Matrix, return a Matrix
	Matrix operator - (const Matrix&) const; // Matrix - Matrix
	Matrix operator * (const Matrix&) const; // multiplication
	Matrix operator [] (int) const; //??? how to do subscriting?
	
	void change_element (double, int, int); // change the value of a single element
	Matrix invert(const Matrix&) const;
	Matrix transpose(const Matrix&) const; 
	Matrix reshape(const Matrix&, int, int);

};



#endif

