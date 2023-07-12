#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
#define delimetr "\n----------------------------------------------------------\n"

class Matrix;
ostream& operator<<(ostream& out, const Matrix& obj);
istream& operator>>(istream& in, Matrix& obj);
Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator-(const Matrix& left, const Matrix& right);
Matrix operator*(const Matrix& left, const Matrix& right);
Matrix operator*(const Matrix& left, const double &number);
Matrix operator/(const Matrix& left, const Matrix& right);
int matrix_determenant(const Matrix& other);
Matrix minor_matrix(const Matrix& other);
Matrix matrix_of_algebraic_additions(const Matrix& other);
Matrix& copy_matrix(Matrix& left, const Matrix& right);
Matrix transpose_matrix(const Matrix& other);


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
	const int get_element(const int i, const int j) const
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
		int a = 2;
		int b = 3;
		a = b;
		if (this == &other) return *this;
		for (int i = 0; i < rows; i++) delete[] array[i];
		delete[] array;

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
	const int* operator[](int i)const
	{
		return array[i];
	}
	int* operator[](int i)
	{
		return array[i];
	}
	
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
	/*cout << "Enter rows: "; cin >> rows;
	cout << "Enter cols: "; cin >> cols;
	cout << "Введите цифры в массив " << rows << " на " << cols << ", в кол-ве: " << rows * cols << ", разделяя ',' ';' ':'";*/
	//Matrix matrix1(rows, cols);
	//cin >> matrix1;
	Matrix matrix1(3, 3);
	Matrix matrix2(3, 3);
	matrix1.random_array();
	matrix2.random_array();
	cout << matrix1 << endl;
	cout << matrix2 << endl;
	cout << delimetr;
	Matrix matrix3;
	matrix3 = matrix1 + matrix2;
	cout << endl << "matrx 1 + matrix2 = " << endl;
	cout << matrix3 << endl;
	cout << delimetr;
	Matrix matrix4 = matrix1 - matrix2;
	cout << matrix4 << endl;
	cout << delimetr;
	Matrix matrix5 = matrix1 * matrix2;
	cout << endl << "matrx 1 * matrix2 = " << endl;
	cout << matrix5 << endl;
	cout << delimetr;
	cout << "Determenant matrix1: " << matrix_determenant(matrix1) << endl;
	cout << "Determenant matrix2: " << matrix_determenant(matrix2) << endl;
	cout << delimetr;
	cout << "Minor matrix1:" << endl;
	cout << minor_matrix(matrix1) << endl;
	cout << "Minor matrix2:" << endl;
	cout << minor_matrix(matrix2) << endl;
	cout << delimetr;
	cout << "Матрица алгебраических дополнений matrix1:" << endl;
	cout << matrix_of_algebraic_additions(minor_matrix(matrix1)) << endl;
	cout << "Матрица алгебраических дополнений matrix2:" << endl;
	cout << matrix_of_algebraic_additions(minor_matrix(matrix2)) << endl;
	cout << delimetr;
	cout << "Transpose matrix1:" << endl;
	Matrix transposeMatrix1 = transpose_matrix(matrix_of_algebraic_additions(minor_matrix(matrix1)));
	cout << transposeMatrix1 << endl;
	Matrix transposeMatrix2 = transpose_matrix(matrix_of_algebraic_additions(minor_matrix(matrix2)));
	cout << transposeMatrix2 << endl;
	cout << delimetr;
	cout << "Итак внимание - обратная матрица!" << endl;
	cout << "Обратная матрица matrix1, сперва множитель: " << -1 << "/" << matrix_determenant(matrix1) * (-1) << endl;
	cout << "Сама матрица:" << endl;
	cout << transposeMatrix1 << endl;
	cout << "Обратная матрица matrix2, сперва множитель: " << -1 << "/" << matrix_determenant(matrix2) * (-1) << endl;
	cout << "Сама матрица:" << endl;
	cout << transposeMatrix2 << endl;
	cout << delimetr;
	cout << "matrix1 / matrix2:" << endl << endl;
	cout << "сперва множитель: " << -1 << "/" << matrix_determenant(matrix2) * (-1) << endl;
	cout << matrix1 / matrix2 << endl;
	cout << delimetr;
	cout << "Умножаем матрицу1 на число:" << endl;
	cout << "matrix1 * 4:" << endl << matrix1 * 4 << endl;
	cout << "Умножаем матрицу2 на число:" << endl;
	cout << "matrix2 * 3:" << endl << matrix2 * 3 << endl;

}

ostream& operator<<(ostream& out, const Matrix& obj)
{
	for (int i = 0; i < obj.get_rows(); i++)
	{
		for (int j = 0; j < obj.get_cols(); j++) out << obj.get_element(i, j) << "\t";
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

Matrix operator+(const Matrix& left, const Matrix& right)
{
	if (left.get_cols() != right.get_cols() || left.get_rows() != right.get_rows()) cout << "Разная размерность - матрицы не складываются" << endl; 
	if (left.get_cols() != right.get_cols() || left.get_rows() != right.get_rows()) return Matrix();
	Matrix buffer(left.get_rows(), left.get_cols());
	buffer.set_rows(left.get_rows());
	buffer.set_cols(left.get_cols());
	for (int i = 0; i < buffer.get_rows(); i++)
	{
		for (int j = 0; j < buffer.get_cols(); j++) buffer.set_array(i, j, (left.get_element(i, j) + right.get_element(i, j)));
	}
	return buffer;
}
Matrix operator-(const Matrix& left, const Matrix& right)
{
	if (left.get_cols() != right.get_cols() || left.get_rows() != right.get_rows()) cout << "Разная размерность - матрицы не вычитаются" << endl;
	if (left.get_cols() != right.get_cols() || left.get_rows() != right.get_rows()) return Matrix();
	Matrix buffer(left.get_rows(), left.get_cols());
	buffer.set_rows(left.get_rows());
	buffer.set_cols(left.get_cols());
	for (int i = 0; i < buffer.get_rows(); i++)
	{
		for (int j = 0; j < buffer.get_cols(); j++) buffer.set_array(i, j, (left.get_element(i, j) - right.get_element(i, j)));
	}
	return buffer;
}
Matrix operator*(const Matrix& left, const Matrix& right)
{
	if (left.get_cols() != right.get_rows()) cout << "Найти произведение невозможно" << endl;
	if (left.get_cols() != right.get_rows()) return Matrix();
	Matrix buffer(left.get_rows(), right.get_cols());
	//int temp = 0;
	for (int i = 0; i < left.get_rows(); i++)
	{
		for (int j = 0; j < right.get_cols(); j++)
		{
			for (int k = 0; k < left.get_cols(); k++)
			{
				buffer[i][j] += left[i][k] * right[k][j];
				//buffer[i][j] += left.get_element(i, k) * right.get_element(k, j);
			}
			//buffer.set_array(i, j, temp);
			//temp = 0;
		}
	}
	return buffer;
}
Matrix operator*(const Matrix& left, const double& number)
{
	Matrix buffer(left.get_rows(), left.get_cols());
	for (int i = 0; i < buffer.get_rows(); i++)
	{
		for (int j = 0; j < buffer.get_cols(); j++)
		{
			buffer[i][j] = left[i][j] * number;
		}
	}
	return buffer;
}

int matrix_determenant(const Matrix& other)
{
	if (other.get_cols() != other.get_rows()) return 0;
	if (other.get_cols() == 2)
	{
		int temp = other[0][0] * other[1][1] - other[0][1] * other[1][0];
		//if (temp == 0) cout << "Определитель равен 0, обратной матрицы не найти" << endl;
		return temp;
	}
	else if (other.get_cols() == 3)
	{
		int temp1 = other[0][0] * other[1][1] * other[2][2];
		int temp2 = other[0][2] * other[0][1] * other[1][2];
		int temp3 = other[1][0] * other[2][1] * other[0][2];
		int temp4 = other[2][0] * other[1][1] * other[0][2];
		int temp5 = other[0][0] * other[2][1] * other[1][2];
		int temp6 = other[1][0] * other[0][1] * other[2][2];
		return temp1 + temp2 + temp3 - temp4 - temp5 - temp6;
	}
	else
	{
		cout << "Не обучена считать больше 3 разрядов" << endl;
		return 0;
	}
}

Matrix minor_matrix(const Matrix& other)
{
	if (other.get_cols() != other.get_rows()) return 0;
	if (other.get_cols() == 2)
	{
		Matrix buffer(2, 2);
		buffer.set_rows(2);
		buffer.set_cols(2);
		buffer.set_array(0, 0, other.get_element(1, 1));
		buffer.set_array(0, 1, other.get_element(1, 0));
		buffer.set_array(1, 0, other.get_element(0, 1));
		buffer.set_array(1, 1, other.get_element(0, 0));
		return buffer;
	}
	else if (other.get_cols() == 3 || other.get_cols() == 4)
	{
		Matrix buffer(other.get_cols(), other.get_cols());
		buffer.set_rows(other.get_rows());
		buffer.set_cols(other.get_cols());
		Matrix temp(other.get_cols() - 1, other.get_cols() - 1);
		temp.set_rows(other.get_rows() - 1);
		temp.set_cols(other.get_cols() - 1);
		for (int i = 0; i < other.get_cols(); i++)
		{
			for (int j = 0; j < other.get_cols(); j++)
			{
				
				for (int k = 0; k < other.get_cols(); k++)
				{
					int k1 = 0, l1 = 0;
					for (int l = 0; l < other.get_cols(); l ++)
					{
						if (k == i || l == j) continue;
						temp.set_array(k1, l1, other.get_element(k, l));
						k1++;
						l1++;
					}
				}
				buffer.set_array(i, j, matrix_determenant(temp));
			}
		}
		return buffer;
	}
	else
	{
		cout << "Не обучена считать больше 4 разрядов" << endl;
		return 0;
	}

}
Matrix matrix_of_algebraic_additions(const Matrix& other)
{
	if (other.get_cols() != other.get_rows()) return 0;
	Matrix buffer(other.get_rows(), other.get_cols());
	buffer.set_rows(other.get_rows());
	buffer.set_cols(other.get_cols());
	copy_matrix(buffer, other);
	if (buffer.get_cols() == 3)
	{
		buffer.set_array(0, 1, buffer.get_element(0, 1) * (-1));
		buffer.set_array(1, 0, buffer.get_element(1, 0) * (-1));
		buffer.set_array(1, 2, buffer.get_element(1, 2) * (-1));
		buffer.set_array(2, 1, buffer.get_element(2, 1) * (-1));
		return buffer;
	}
	else if (buffer.get_cols() == 2)
	{
		buffer.set_array(0, 1, buffer.get_element(0, 1) * (-1));
		buffer.set_array(1, 0, buffer.get_element(1, 0) * (-1));
		return buffer;
	}
	else
	{
		cout << "Не обучена считать больше 3 разрядов" << endl;
		return 0;
	}
}
Matrix& copy_matrix(Matrix& left, const Matrix& right)
{
	for (int i = 0; i < right.get_rows(); i++)
	{
		for (int j = 0; j < right.get_cols(); j++)
		{
			left.set_array(i, j, right.get_element(i, j));
		}
	}
	return left;
}

Matrix transpose_matrix(const Matrix& other)
{
	if (other.get_cols() != other.get_rows()) return 0;
	Matrix buffer(other.get_rows(), other.get_cols());
	buffer.set_rows(other.get_rows());
	buffer.set_cols(other.get_cols());
	for (int i = 0; i < buffer.get_rows(); i++)
	{
		for (int j = 0; j < buffer.get_cols(); j++)
		{
			buffer.set_array(j, i, other.get_element(i, j));
		}
	}
	return buffer;
}

Matrix operator/(const Matrix& left, const Matrix& right)
{
	int matrixDetermenant = matrix_determenant(right);
	Matrix buffer(right.get_rows(), right.get_cols());
	buffer.set_rows(right.get_rows());
	buffer.set_cols(right.get_cols());
	buffer = transpose_matrix(matrix_of_algebraic_additions(minor_matrix(right)));
	return left * buffer;
}