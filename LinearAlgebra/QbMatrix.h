#pragma once

template<class T>
class QbMatrix{
public:
	QbMatrix();
	QbMatrix(int rows, int cols);
	QbMatrix(int rows, int cols, const T* inputData);
	QbMatrix(const QbMatrix<T>& inputMatrix);
	~QbMatrix();
//getters and setters
	T getElement(int i_indx, int j_indx);
	bool setElement(int i_indx, int j_indx, T value);
	int getRowsNum();
	int getColsNum();
//operrators
	//=
	void operator=(const QbMatrix<T>& mat);
	bool operator==(const QbMatrix<T>& rightSideMatrix);
	//+
	template<class U> friend QbMatrix<U> operator+(const QbMatrix<U>& leftSideMatrix, const QbMatrix<U>& RightSideMatrix);
	template<class U> friend QbMatrix<U> operator+(const U& leftSideScalor, const QbMatrix<U>& RightSideMatrix);
	template<class U> friend QbMatrix<U> operator+(const QbMatrix<U>& leftSideMatrix, const U& rightSideScalor);
	//-
	template<class U> friend QbMatrix<U> operator-(const QbMatrix<U>& leftSideMatrix, const QbMatrix<U>& RightSideMatrix);
	template<class U> friend QbMatrix<U> operator-(const U& leftSideScalor, const QbMatrix<U>& RightSideMatrix);
	template<class U> friend QbMatrix<U> operator-(const QbMatrix<U>& leftSideMatrix, const U& rightSideScalor);
	//*
	template<class U> friend QbMatrix<U> operator*(const QbMatrix<U>& leftSideMatrix, const QbMatrix<U>& RightSideMatrix);
	template<class U> friend QbMatrix<U> operator*(const U& leftSideScalor, const QbMatrix<U>& RightSideMatrix);
	template<class U> friend QbMatrix<U> operator*(const QbMatrix<U>& leftSideMatrix, const U& rightSideScalor);
private:
	int linearIndx(int rows, int cols);
private:
	int n_rows, n_cols, n_elements;
	T* matrixDataArry;
public:
	void print();
};

