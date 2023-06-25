#include <iostream>

using namespace std;
using std::cin;
using std::cout;
//using std::;

#define delimetr "\n--------------------------------------------------------------------------------------------------------------------\n"


class Point;
ostream& operator<<(ostream& out, const Point& obj);     // Оператор потокового вывода
Point operator+(const Point& left, const Point& right); // Арифметический оператор "сложение"
Point operator-(const Point& left, const Point& right); // Арифметический оператор "вычитание"
Point operator*(const Point& left, const Point& right); // Арифметический оператор "умножение"
Point operator/(const Point& left, const Point& right); // Арифметический оператор "деление"
//Point operator-(const Point& other);					// Унарный минус
//Point operator+(const Point& other);					// Унарный плюс

bool operator==(const Point& left, const Point& right);


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
	Point& operator-() // Унарный минус
	{
		x = -x;
		y = -y;
		return *this;
	}
	Point& operator+() // УНарный плюс
	{
		x = +x;
		y = +y;
		return *this;
	}
	Point& operator++()  // Префиксный инкремент
	{
		++x;
		++y;
		return *this;
	}
	Point& operator--() // Префиксный декремент
	{
		--x;
		--y;
		return *this;
	}
	Point operator++(int) // Постфиксный инкремент
	{
		Point old = *this; // сохраняем исходное значение объекта
		x++;
		y++;
		return old;
	}
	Point operator--(int) // Постфиксный декремент
	{
		Point old = *this;
		x--;
		y--;
		return old;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point& operator-=(const Point& other) //составное присваивание с вычитанием 
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	Point& operator*=(const Point& other) //составное присваивание с умножением
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}
	Point& operator/=(const Point& other) //составное присваивание с делением
	{
		this->x /= other.x;
		this->y /= other.y;
		this->x = round((this->x * 1) / 1);
		this->y = round((this->y * 1) / 1);
		return *this;
	}

	friend bool operator==(const Point& left, const Point& right); //операторы сравнения 
	friend bool operator!=(const Point& left, const Point& right);
	friend bool operator>(const Point& left, const Point& right);
	friend bool operator<(const Point& left, const Point& right);
	friend bool operator>=(const Point& left, const Point& right);
	friend bool operator<=(const Point& left, const Point& right);
	friend istream& operator>>(istream& in, Point& obj);           //для доступа прямого к х и у сделал оператор ввода дружественным

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
	cout << "-(B - A): " << -(B - A) << endl;
	cout << "+(B - A): " << +(B - A) << endl;
	cout << "A * B: " << A * B << endl;
	cout << "A / B: " << A / B << endl << endl;
	cout << "  A: " << A << endl;
	cout << "--A: " << --A << endl;
	cout << "++A: " << ++A << endl;
	A--;
	cout << "A--: " << A << endl;
	A++;
	cout << "A++: " << A << endl;
	cout << "A: " << A << ",     B: " << B << endl;
	A -= B;
	cout << "A -= B: " << A << endl << endl;
	cout << "A: " << A << ",     B: " << B << endl;
	A *= B;
	cout << "A *= B: " << A << endl << endl;
	A++;												//Сделал для проверки дробей
	cout << "A: " << A << ",     B: " << B << endl;
	A /= B;
	cout << "A /= B: " << A << endl << endl;
	//A = B; // Делаем для понимания сработки условия сравнения
	cout << "A: " << A << ",     B: " << B << endl;
	cout << "Проверяем сравненение А == В:   " << (A == B ? "true" : "false") << endl << endl;	
	cout << "A: " << A << ",     B: " << B << endl;
	cout << "Проверяем сравненение А != В:   " << (A != B ? "true" : "false") << endl << endl;
	cout << "A: " << A << ",     B: " << B << endl;
	cout << "Проверяем сравненение А > В:   " << (A > B ? "true" : "false") << endl << endl;
	cout << "A: " << A << ",     B: " << B << endl;
	cout << "Проверяем сравненение А < В:   " << (A < B ? "true" : "false") << endl << endl;
	cout << "A: " << A << ",     B: " << B << endl;
	cout << "Проверяем сравненение А >= В:   " << (A >= B ? "true" : "false") << endl << endl;
	cout << "A: " << A << ",     B: " << B << endl;
	cout << "Проверяем сравненение А <= В:   " << (A <= B ? "true" : "false") << endl << endl;
	Point C;
	cout << "Проверяем cin, зададим координаты новой точке С!" << endl;
	cin >> C;
	cout << "Какие координаты записались в точку C: " << C << endl;
	

}

ostream& operator<<(ostream& out, const Point& obj)           // Оператор потокового вывода
{
	return out << "X = " << obj.get_x() << "\tY = " << obj.get_y();

}
istream& operator>>(istream& in, Point& obj)           // Оператор потокового вывода
{
	cout << "Введите значение Х: ";
	in >> obj.x;
	cout << "Введите значение Y: ";
	in >> obj.y;
	return in;
}
// Арифметические операторы
Point operator+(const Point& left, const Point& right)       // Арифметический оператор "сложение"
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
Point operator-(const Point& left, const Point& right)		 // Арифметический оператор "вычитание"
{
	return Point(left.get_x() - right.get_x(), left.get_y() - right.get_y());
}
Point operator*(const Point& left, const Point& right)      // Арифметический оператор "умножение"
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}
Point operator/(const Point& left, const Point& right)     // Арифметический оператор "деление"
{
	return Point(round((left.get_x() / right.get_x())*1)/1, round((left.get_y() / right.get_y())*1)/1); // Округлил до целового с помощью round ибо если перевести в int, то он просто отбрасывает остаток
}
//Унарные операторы перенес в класс, потому что так мы избегаем создание многих конструкторов, сделал по аналогии с оператором "="
//Point operator-(const Point& other)                          // Унарный минус
//{
//	return Point(-other.get_x(), -other.get_y());
//}
//Point operator+(const Point& other)					     // Унарный плюс
//{
//	return Point(+other.get_x(), +other.get_y());
//}

bool operator==(const Point& left, const Point& right)
{
	return (left.get_x() == right.get_x() && left.get_y() == right.get_y());
}
bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}
bool operator>(const Point& left, const Point& right)
{
	return ((left.get_x() + left.get_y()) > (right.get_x() + right.get_y()));
}
bool operator<(const Point& left, const Point& right)
{
	return ((left.get_x() + left.get_y()) < (right.get_x() + right.get_y()));
}
bool operator<=(const Point& left, const Point& right)
{
	return ((left.get_x() + left.get_y()) <= (right.get_x() + right.get_y()));
}
bool operator>=(const Point& left, const Point& right)
{
	return ((left.get_x() + left.get_y()) >= (right.get_x() + right.get_y()));
}

double distance(const Point& A, const Point& B)
{
	//double x_distance = A.get_x() - B.get_x();
	//double y_distance = A.get_y() - B.get_y();
	//return round(sqrt(x_distance * x_distance + y_distance * y_distance) * 100) / 100;
	return round(sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2)) * 100) / 100;
}