#include "Matrix.h"
#include <exception>
#include <iostream>

void Matrix::copy(const Matrix& other)
{
	m_Rows = other.m_Rows;
	m_Cols = other.m_Cols;

	if (other.m_Data == nullptr)
	{
		m_Data = nullptr;
	}
	else
	{
		m_Data = new int* [m_Rows];
		for (int i = 0; i < m_Rows; ++i)
		{
			m_Data[i] = new int[m_Cols];
		}
		for (int i = 0; i < m_Rows; ++i)
		{
			for (int j = 0; j < m_Cols; ++j)
			{
				m_Data[i][j] = other.m_Data[i][j];
			}
		}

	}
}

void Matrix::erase()
{
	for (int i = 0; i < m_Rows; ++i)
	{
		delete[] m_Data[i];
	}
	delete[] m_Data;
	m_Data = nullptr;
}

Matrix::Matrix(int rows, int cols)
{
	int** m_Data = new int*[rows];

	for (int i = 0; i < rows; ++i)
	{
		m_Data[i] = new int[cols];
	}
	m_Rows = rows;
	m_Cols = cols;
}

Matrix::~Matrix()
{
	erase();
}

Matrix::Matrix(const Matrix& other)
{
	copy(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

Matrix::Matrix(Matrix&& other) noexcept
{
	m_Data = other.m_Data;
	m_Cols = other.m_Cols;
	m_Rows = other.m_Rows;

	other.m_Data = nullptr;
	other.m_Cols = other.m_Rows = 0;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
	if (this != &other)
	{
		erase();
		m_Data = other.m_Data;
		m_Rows = other.m_Rows;
		m_Cols = other.m_Cols;
		other.m_Data = nullptr;
		other.m_Cols = 0;
		other.m_Rows = 0;
	}
	return *this;
}

int& Matrix::operator() (int row, int col) const
{
	if (row >= m_Rows || col >= m_Cols)
	{
		throw std::exception("Invalid index!");
	}
	return m_Data[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const
{
	if (m_Cols != other.m_Cols || m_Rows != other.m_Rows)
	{
		throw std::exception("Invalid matrix size!");
	}

	Matrix toReturn = Matrix(other);

	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Cols; ++j)
		{
			toReturn.m_Data[i][j] += this->m_Data[i][j];
		}
	}

	return toReturn;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	if (m_Cols != other.m_Cols || m_Rows != other.m_Rows)
	{
		throw std::exception("Invalid matrix size!");
	}

	Matrix toReturn = Matrix(*this);

	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Cols; ++j)
		{
			toReturn.m_Data[i][j] -= other.m_Data[i][j];
		}
	}

	return toReturn;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	if (m_Cols != other.m_Cols || m_Rows != other.m_Rows)
	{
		throw std::exception("Invalid matrix size!");
	}

	Matrix toReturn = Matrix(*this);

	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Cols; ++j)
		{
			toReturn.m_Data[i][j] *= other.m_Data[i][j];
		}
	}

	return toReturn;
}

bool Matrix::operator==(const Matrix& other) const
{
	if (this->m_Cols != other.m_Cols || this->m_Rows != other.m_Rows)
	{
		return false;
	}

	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Cols; ++j)
		{
			if (m_Data[i][j] != other.m_Data[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

Matrix transpose(const Matrix& matrix)
{
	Matrix toReturn = Matrix(matrix.m_Cols, matrix.m_Rows);

	for (int i = 0; i < toReturn.m_Rows; ++i)
	{
		for (int j = 0; j < toReturn.m_Cols; ++j)
		{
			toReturn.m_Data[i][j] = matrix.m_Data[j][i];
		}
	}
}

void print(const Matrix& matrix)
{
	for (int i = 0; i < matrix.m_Rows; ++i)
	{
		for (int j = 0; j < matrix.m_Cols; ++j)
		{
			std::cout << matrix(i, j);
		}
	}
}
