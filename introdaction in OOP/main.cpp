#include <iostream>

using namespace std;
//using std::;
//using std::
//using std::


class Point;
double distance(Point A, Point B);

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
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Distructor:\t\t" << this << endl;
	}
	//                     Methods:
	double distance(Point other) const // На всякий случай сделал метод, который вычисляет расстояние до указанной точки, от текущей точки
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

	
	cout << "(Function)Расстояние от точки А с координатами (" << A.get_x() << "," << A.get_y() << ") до точки B с координатами (";
	cout << B.get_x() << "," << B.get_y() << ") составляет " << distance(A, B) << endl << endl;

	cout << "(Method)Расстояние от точки А с координатами (" << A.get_x() << "," << A.get_y() << ") до точки B с координатами (";
	cout << B.get_x() << "," << B.get_y() << ") составляет " << A.distance(B) << endl;
#endif //DISTANCE_CHEK
	
	Point A;
	A.print();

	Point B = 5; // Single-argument constructor
	B.print();

	Point C(2, 3);
	C.print();
}

double distance(Point A, Point B)
{
	//double x_distance = A.get_x() - B.get_x();
	//double y_distance = A.get_y() - B.get_y();
	//return round(sqrt(x_distance * x_distance + y_distance * y_distance) * 100) / 100;
	return round(sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2)) * 100) / 100;
}