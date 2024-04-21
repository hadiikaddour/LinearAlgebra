#include"QbMatrix.h"
#include"QbMatrix.cpp"
#include<iostream>

int main() {
	int inputDataArry1[] = {1,2,3,4,5,6,7,8,9};
	int inputDataArry2[] = { 9,8,7,6,5,4,3,2,1};
	QbMatrix<int> mat1(3, 3, inputDataArry1);
	QbMatrix<int> mat2(3, 3, inputDataArry2);
	QbMatrix<int> mat3(3, 3);
	mat3 = mat1 * mat2;
	mat1.print();
	std::cout << std::endl;
	mat2.print();
	std::cout << std::endl;
	mat3.print();

	return 0;
}