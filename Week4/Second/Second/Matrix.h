#ifndef __MATRIX_INCLUDED__
#define __MATRIX_INCLUDED__

class Matrix
{
private:
	void copy(const Matrix& other);
	void erase();

	int m_Rows;
	int m_Cols;
	int** m_Data;

public:
	Matrix(int rows, int cols);
	~Matrix();
	Matrix(const Matrix& other);

	Matrix& operator=(const Matrix& other);
	Matrix(Matrix&& other);
	Matrix& operator=(Matrix&& other);

	int& operator()(int row, int col) const;

	Matrix operator+(const Matrix& other) const;

	Matrix operator-(const Matrix& other) const;

	Matrix operator*(const Matrix& other) const;

	bool operator==(const Matrix& other) const;

	friend Matrix transpose(const Matrix& matrix);

	friend void print(const Matrix& matrix);
};

#endif // !__MATRIX_INCLUDED__



