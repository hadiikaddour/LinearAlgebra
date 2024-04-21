#include "QbMatrix.h"
#include<iostream>
template<class T>
QbMatrix<T>::QbMatrix() {
	n_rows = 0;
	n_cols = 0;
	n_elements = 0;
	matrixDataArry = new T[n_elements];
	matrixDataArry[0] = 0;
}
template<class T>
QbMatrix<T>::QbMatrix(int rows,int cols) {
	n_rows = rows;
	n_cols = cols;
	n_elements = rows * cols;
	matrixDataArry = new T[n_elements];
	for (int i = 0; i < n_elements; i++)
		matrixDataArry[i] = 0;
}
template<class T>
QbMatrix<T>::QbMatrix(int rows, int cols, const T* inputData) {
	n_rows = rows;
	n_cols = cols;
	n_elements = rows * cols;
	matrixDataArry = new T[n_elements];
	for (int i = 0; i < n_elements; i++)
		matrixDataArry[i] = inputData[i];
}
template<class T>
QbMatrix<T>::QbMatrix(const QbMatrix<T>& inputMatrix) {
	n_rows = inputMatrix.n_rows;
	n_cols = inputMatrix.n_rows;
	n_elements = inputMatrix.n_elements;
	matrixDataArry = new T[n_elements];
	for (int i = 0; i < n_elements; i++)
		matrixDataArry[i] = inputMatrix.matrixDataArry[i];
}
template<class T>
QbMatrix<T>::~QbMatrix() {
	if (matrixDataArry != nullptr)
		delete[] matrixDataArry;
}
//getters and setters
template<class T>
T QbMatrix<T>::getElement(int i_indx, int j_indx) {
	int linear_indx = linearIndx(i_indx, j_indx);
	return matrixDataArry[linear_indx];
 }

template<class T>
bool QbMatrix<T>::setElement(int i_indx, int j_indx,T value) {
	int linear_indx = linearIndx(i_indx, j_indx);
	if (linearIndx >= 0) {
		matrixDataArry[linear_indx] = value;
		return true;
	}
	return false;
}
template<class T>
int QbMatrix<T>::getRowsNum() {
	return n_rows;
}
template<class T>
int QbMatrix<T>::getColsNum() {
	return n_cols;
}
//operrators 
	//+

template<class T>
QbMatrix<T> operator+(const QbMatrix<T>& leftSideMatrix, const QbMatrix<T>& RightSideMatrix) {
	int rowsNum = leftSideMatrix.n_rows;
	int colsNum = leftSideMatrix.n_cols;
	int elementsNum = colsNum * rowsNum;
	T* tempArry = new T[elementsNum];
	for (int i = 0; i < elementsNum; i++)
		tempArry[i] = leftSideMatrix.matrixDataArry[i] + RightSideMatrix.matrixDataArry[i];
	QbMatrix<T> result(rowsNum, colsNum, tempArry);
	delete[] tempArry;
	return result;
}


template<class U>
QbMatrix<U> operator+(const U& leftSideScalor, const QbMatrix<U>& RightSideMatrix) {
	int rowsNum = RightSideMatrix.n_rows;
	int colsNum = RightSideMatrix.n_cols;
	int elementsNum = colsNum * rowsNum;
	U* tempArry = new U[elementsNum];
	for (int i = 0; i < elementsNum; i++)
		tempArry[i] = RightSideMatrix.matrixDataArry[i]+leftSideScalor;
	QbMatrix<U> result(rowsNum, colsNum, tempArry);
	delete[] tempArry;
	return result;
}
template<class U>
QbMatrix<U> operator+(const QbMatrix<U>& leftSideMatrix, const U& rightSideScalor) {
	int rowsNum = leftSideMatrix.n_rows;
	int colsNum = leftSideMatrix.n_cols;
	int elementsNum = rowsNum * colsNum;
	U* tempArry = new U[elementsNum];
	for (int i = 0; i < elementsNum; i++)
		tempArry[i] = leftSideMatrix.matrixDataArry[i] + rightSideScalor;
	QbMatrix<U> result(rowsNum, colsNum, tempArry);
	return result;
}
	//-


template<class T>
QbMatrix<T> operator-(const QbMatrix<T>& leftSideMatrix, const QbMatrix<T>& RightSideMatrix) {
	int rowsNum = leftSideMatrix.n_rows;
	int colsNum = leftSideMatrix.n_cols;
	int elementsNum = colsNum * rowsNum;
	T* tempArry = new T[elementsNum];
	for (int i = 0; i < elementsNum; i++)
		tempArry[i] = leftSideMatrix.matrixDataArry[i] - RightSideMatrix.matrixDataArry[i];
	QbMatrix<T> result(rowsNum, colsNum, tempArry);
	delete[] tempArry;
	return result;
}
template<class U>
QbMatrix<U> operator-(const U& leftSideScalor, const QbMatrix<U>& RightSideMatrix) {
	int rowsNum = RightSideMatrix.n_rows;
	int colsNum = RightSideMatrix.n_cols;
	int elementsNum = colsNum * rowsNum;
	U* tempArry = new U[elementsNum];
	for (int i = 0; i < elementsNum; i++)
		tempArry[i] = RightSideMatrix.matrixDataArry[i] - leftSideScalor;
	QbMatrix<U> result(rowsNum, colsNum, tempArry);
	delete[] tempArry;
	return result;
}


template<class U>
QbMatrix<U> operator-(const QbMatrix<U>& leftSideMatrix, const U& rightSideScalor) {
	int rowsNum = leftSideMatrix.n_rows;
	int colsNum = leftSideMatrix.n_cols;
	int elementsNum = rowsNum * colsNum;
	U* tempArry = new U[elementsNum];
	for (int i = 0; i < elementsNum; i++)
		tempArry[i] = leftSideMatrix.matrixDataArry[i] - rightSideScalor;
	QbMatrix<U> result(rowsNum, colsNum, tempArry);
	return result;
}

	//*
template<class U>
QbMatrix<U> operator*(const U& leftSideScalor, const QbMatrix<U>& RightSideMatrix) {
	int rowsNum = RightSideMatrix.getRows();
	int colsNum = RightSideMatrix.getCols();
	int elementsNum = colsNum * rowsNum;
	U* tempArry = new U[elementsNum];
	for (int i = 0; i < elementsNum; i++)
		tempArry[i] = RightSideMatrix.matrixDataArry[i] * leftSideScalor;
	QbMatrix<U> result(rowsNum, colsNum, tempArry);
	delete[] tempArry;
	return result;
}
template<class U>
QbMatrix<U> operator*(const QbMatrix<U>& leftSideMatrix, const U& rightSideScalor) {
	int rowsNum = leftSideMatrix.n_rows;
	int colsNum = leftSideMatrix.n_cols;
	int elementsNum = rowsNum * colsNum;
	U* tempArry = new U[elementsNum];
	for (int i = 0; i < elementsNum; i++)
		tempArry[i] = leftSideMatrix.matrixDataArry[i] * rightSideScalor;
	QbMatrix<U> result(rowsNum, colsNum, tempArry);
	delete[] tempArry;
	return result;
}
//matrix * matrix
template<class U>
QbMatrix<U> operator*(const QbMatrix<U>& leftSideMatrix, const QbMatrix<U>& RightSideMatrix) {
	int leftMatrixRowsNum = leftSideMatrix.n_rows;
	int leftMatrixColsNum = leftSideMatrix.n_cols;
	int rightMatrixRowsNum = RightSideMatrix.n_rows;
	int rightMatrixColsNum = RightSideMatrix.n_cols;
	if (leftMatrixColsNum == rightMatrixRowsNum) {

		U* tempResult = new U[rightMatrixRowsNum];
		//loop for each row of left matrix rows
		for (int l_row = 0; l_row < leftMatrixRowsNum; l_row++) {
			//loop for each coulmn on right matrix columns
			for (int r_col = 0; r_col < rightMatrixColsNum; r_col++) {
				U elementResult = 0;
				//loop for each eleemnt of left matrix row 
				for (int l_col = 0; l_col < leftMatrixColsNum; l_col++) {
					int l_linearIndx = (l_row * leftMatrixColsNum) + l_col;
					int r_linearIndx = (l_col * rightMatrixColsNum) + r_col;
					elementResult += leftSideMatrix.matrixDataArry[l_linearIndx] * RightSideMatrix.matrixDataArry[r_linearIndx];
				}
				int resultLinearIndx = (l_row * rightMatrixColsNum) + r_col;
				tempResult[resultLinearIndx] = elementResult;
			}
		}
		QbMatrix<U> result(leftMatrixRowsNum, rightMatrixColsNum, tempResult);
		delete[] tempResult;
		return new QbMatrix<U>(leftMatrixRowsNum, rightMatrixColsNum, result);

	}
	else
	{
		QbMatrix<U> result(1, 1);
		return std::move(result);
	}
}


template<class T>
int QbMatrix<T>::linearIndx(int i_indx, int j_indx) {
	if ((i_indx < n_rows) && (i_indx >= 0) && (j_indx < n_cols) && (j_indx >= 0))
		return (i_indx * n_cols) + j_indx;
	else
		return -1;
}
template<class T>
bool QbMatrix<T>::operator==(const QbMatrix<T>& rightSideMatrix) {
	if ((this->n_rows != rightSideMatrix.n_rows) || this->n_cols != rightSideMatrix.n_cols)
		return false;
	for (int i = 0; i < this->n_elements; i++)
		if (this->matrixDataArry[i] != rightSideMatrix.matrixDataArry[i])
			return false;
	return true;
}
template<class T> 
void QbMatrix<T>::print() {
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			std::cout << matrixDataArry[linearIndx(i, j)] << " ";
		}
		std::cout << std::endl;
	}
}