#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Matrix;
ostream& operator<<(ostream& out, const Matrix& obj);
istream& operator>>(istream& in, Matrix& obj);


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
	const int get_array(const int i, const int j) const
	{
		return this->array[i][j];
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
	void set_array(int i, int j, int number)
	{
		this->array[i][j] = number;
	}

	//			Constructor's
	Matrix()
	{
		this->rows = 1;
		this->cols = 1;
		this->array = new int* [rows] {};
		for (int i = 0; i < rows; i++) array[i] = new int[cols] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	Matrix(int cols)
	{
		this->rows = 1;
		this->cols = cols;
		this->array = new int*[rows] {};
		for (int i = 0; i < rows; i++) array[i] = new int[cols] {};
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->array = new int*[rows] {};
		for (int i = 0; i < rows; i++) array[i] = new int[cols] {};
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
	//int& operator[][](int i, int j)
	//{
	//	return array[i][j];
	//}
	//			Method's
	void print() const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) cout << array[i][j] << "\t";
			cout << endl;
		}
	}
	void random_array()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = rand() % (rows * cols);
			}
		}
	}

};

void main()
{
	setlocale(LC_ALL, "");
	int rows, cols;
	cout << "Enter rows: "; cin >> rows;
	cout << "Enter cols: "; cin >> cols;
	cout << "Введите цифры в массив " << rows << " на " << cols << ", в кол-ве: " << rows * cols << ", разделяя ',' ';' ':'";
	Matrix matrix1(rows, cols);
	cin >> matrix1;
	//matrix1.random_array();
	cout << matrix1 << endl;
}

ostream& operator<<(ostream& out, const Matrix& obj)
{
	for (int i = 0; i < obj.get_rows(); i++)
	{
		for (int j = 0; j < obj.get_cols(); j++) out << obj.get_array(i, j) << "\t";
		cout << endl;
	}
	return out;
}

istream& operator>>(istream& in, Matrix& obj) //Если ввели не все цифры, то они будут заменены 0
{
	const int SIZE = 256;
	char* buffer = new char[SIZE]{};
	cin >> buffer;
	int Size_Array = obj.get_cols() * obj.get_rows();
	int* number = new int[Size_Array] {};
	int n = 0;
	char delimetrs[] = ",;: ";
	for (char* pch = strtok(buffer, delimetrs); pch; pch = strtok(NULL, delimetrs))
		number[n++] = atoi(pch);
	int j = 0;
	for (int i = 0; i < obj.get_rows(); i++)
	{
		if (i >= n) break;
		if (i * j >= n) break;
		for (j = 0; j < obj.get_cols(); j++)
		{
			if (i * j >= n) break;
			obj.set_array(i, j, number[(i * obj.get_cols()) + j]);
		}
	}
	return in;
}