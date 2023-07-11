#include <iostream>

using namespace std;

class Matrix;


class Matrix
{
	int rows;
	int cols;
	int** array;
public:
	//			GET Method's
	const int get_rows(void) const
	{
		return rows;
	}
	const int get_cols(void) const
	{
		return cols;
	}
	//			SET Method's
	void set_rows(int rows)
	{
		this->rows = rows;
	}
	void set_cols(int cols)
	{
		this->cols = cols;
	}

	//			Constructor's
	Matrix()
	{
		this->rows = 1;
		this->cols = 1;
		this->array = new int* [rows] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	Matrix(const int rows = 1)
	{
		this->array = new int*[rows] {};
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Matrix(const int rows = 1, const int cols = 1)
	{
		this->array = new int*[rows] {};
		for (int i = 0; i < rows; i++) array[i] = new int[cols];
		cout << "2ArgConstructor:\t" << this << endl;
	}
	Matrix(Matrix&& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->array = other.array;
		other.rows = 0;
		other.cols = 0;
		other.array = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}

	//			Destructor
	~Matrix()
	{
		for (int i = 0; i < rows; i++) delete[] array[i];
		delete[] array;
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators
	Matrix& operator=(const Matrix& other)
	{
		if (this == &other) return *this;
		this->rows = other.rows;
		this->cols = other.cols;
		this->array = new int* [rows] {};
		for (int i = 0; i < rows; i++) array[i] = new int [cols] {};
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Matrix& operator=(Matrix&& other)
	{
		if (this == &other) return *this;
		for (int i = 0; i < rows; i++) delete[] array[i];
		delete[] array;
		this->rows = other.rows;
		this->cols = other.cols;
		this->array = other.array;
		other.rows = 0;
		other.cols = 0;
		other.array = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}


};

void main()
{
	setlocale(LC_ALL, "");

}