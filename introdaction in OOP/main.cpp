#include <iostream>

using namespace std;
using std::cin;
using std::cout;
//using std::;

#define delimetr "\n--------------------------------------------------------------------------------------------------------------------\n"


class Point;
ostream& operator<<(ostream& os, const Point& obj);
Point operator+(const Point& left, const Point& right);
Point operator-(const Point& left, const Point& right);
double distance(const Point& A, const Point& B);

class Point
{
	double x;
	double y;
public:
	double get_x(void) const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//                     Constructors:
	//Point()
	//{
	//	x = y = double(); //type() - это значение по умолчанию для заданного типа
	//					  // таким образом мы якобы вызываем конструктор по умолчанию для заданного типа
	//	cout << "Constructor:\t\t" << this << endl;
	//}
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = 0;
	//	cout << "Single-argument constructor\t" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Distructor:\t\t" << this << endl;
	}

	//                     Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this; // сохраняем исходное значение объекта
		x++;
		y++;
		return old;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	//                     Methods:
	double distance(const Point& other) const // На всякий случай сделал метод, который вычисляет расстояние до указанной точки, от текущей точки
	{
		//double x_distance = this->x - other.x;
		//double y_distance = this->y - other.y;
		//return round(sqrt(x_distance * x_distance + y_distance * y_distance) * 100) / 100;
		return round(sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2)) * 100) / 100;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define STRACT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHEK
//#define ASSIGNMENT_CHEK
//#define INCREMENT_CHEK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRACT_POINT


	//type name;
	int a; // Объявление переменной 'а' типо 'int'
	Point A; //Объявление переменной 'А' типа 'Poin'
			// Создание объекта 'A' структуры 'Point'
			// Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

#endif // STRACT_POINT

#ifdef DISTANCE_CHECK
	Point A; //Точка А и В для удобства заданы внутри программы, хотя можно и сделать чтобы их вводили

	A.set_x(2);
	A.set_y(3);

	Point B;
	B.set_x(7);
	B.set_y(8);

	cout << delimetr << endl;
	
	cout << "(Function)Расстояние от точки А с координатами (" << A.get_x() << "," << A.get_y() << ") до точки B с координатами (";
	cout << B.get_x() << "," << B.get_y() << ") составляет " << distance(A, B) << endl << endl;

	cout << delimetr << endl;

	cout << "(Function)Расстояние от точки А с координатами (" << B.get_x() << "," << B.get_y() << ") до точки B с координатами (";
	cout << A.get_x() << "," << A.get_y() << ") составляет " << distance(B, A) << endl << endl;

	cout << delimetr << endl;

	cout << "(Method)Расстояние от точки А с координатами (" << A.get_x() << "," << A.get_y() << ") до точки B с координатами (";
	cout << B.get_x() << "," << B.get_y() << ") составляет " << A.distance(B) << endl;

	cout << delimetr << endl;

	cout << "(Method)Расстояние от точки А с координатами (" << B.get_x() << "," << B.get_y() << ") до точки B с координатами (";
	cout << A.get_x() << "," << A.get_y() << ") составляет " << B.distance(A) << endl;

	cout << delimetr << endl;

#endif //DISTANCE_CHEK
	
#ifdef CONSTRUCTOR_CHEK


	Point A;
	A.print();

	Point B = 5; // Single-argument constructor
	B.print();

	Point C(2, 3);
	C.print();
	int a = 2, b = 3;

	Point D = C; //CopyConstructor
	D.print();

	Point E;
	E = D; //Copy Assigment
	E.print();
#endif // CONSTRUCTOR_CHEK

#ifdef ASSIGNMENT_CHEK


	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;

	A = B = C = Point(2, 3);

	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHEK

#ifdef INCREMENT_CHEK

	int a = 2;
	int b = 3;
	int c = a + b;
	cout << c << endl;

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();

	A++;
	A.print();

#endif // INCREMENT_CHEK

	Point A(2, 3);
	cout << "A: " << A << endl;

	Point B(7, 8);
	cout << "B: " << B << endl << endl;

	cout << "Dot operation: " << endl;
	A += B;
	cout << "A += B: " << A << endl;

	cout << "B - A: " << B - A << endl;

}

ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();

}
Point operator+(const Point& left, const Point& right)
{
	//Point result;
	//result.set_x(left.get_x() + right.get_x());
	//result.set_y(left.get_y() + right.get_y());
	//Point result
	//(
	//	left.get_x() + right.get_x(), 
	//	left.get_y() + right.get_y()
	//);
	return Point
		(
			left.get_x() + right.get_x(),
			left.get_y() + right.get_y()
		);
}
Point operator-(const Point& left, const Point& right)
{
	return Point(left.get_x() - right.get_x(), left.get_y() - right.get_y());
}

double distance(const Point& A, const Point& B)
{
	//double x_distance = A.get_x() - B.get_x();
	//double y_distance = A.get_y() - B.get_y();
	//return round(sqrt(x_distance * x_distance + y_distance * y_distance) * 100) / 100;
	return round(sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2)) * 100) / 100;
}