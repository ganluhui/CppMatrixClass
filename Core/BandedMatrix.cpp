#include "Array.h"
#include "Matrix.h"
#include "BandedMatrix.h"
#include "BandedArray.h"
#include <memory>
#include <iostream>

using namespace std;

BandedMatrix::BandedMatrix(double value, size_t dim, size_t up, size_t low){
	std::shared_ptr<BandedArray<double>> newdata(new BandedArray<double>(value, dim, up, low));
	data = newdata;
}

BandedMatrix::BandedMatrix(size_t dim, size_t up, size_t low) : BandedMatrix(1.0, dim, up, low){};

shared_ptr<Matrix> BandedMatrix::operator+ (Matrix& rhs){
	if (typeid(rhs).name() == typeid(BandedMatrix).name()){
		cout << "BandedMatrix + BandedMatrix is called." << endl;
		BandedMatrix rhs1 = dynamic_cast<BandedMatrix&> (rhs);
		int dim = data->RowSize();
		int up = max(this->Upper(), rhs1.Upper());
		int low = max(this->Lower(), rhs1.Lower());
		shared_ptr<BandedMatrix> lhs(new BandedMatrix(0.0, dim, up, low));
		
		int j_mat;
		for (int i = 1; i <= dim; i++){
			for (int j = 1; j <= up + low + 1; j++){
				j_mat = i - low + j - 1;
					if (j_mat > 0 && j_mat <= dim)
						lhs->Change(rhs1(i, j_mat) + this->operator()(i, j_mat), i, j_mat);
				}
			}
		return lhs;
	}
	else{
		cout << "BandedMatrix + Matrix is called, passed to base class." << endl;
		return this->Matrix::operator+ (rhs);
	}
}

size_t BandedMatrix::Upper() { 
	std::shared_ptr<BandedArray<double>> data2;
	data2 = std::dynamic_pointer_cast<BandedArray<double>>(data);
	return data2->Upper(); 
}

size_t BandedMatrix::Lower() {
	std::shared_ptr<BandedArray<double>> data2;
	data2 = std::dynamic_pointer_cast<BandedArray<double>>(data);
	return data2->Upper();
}