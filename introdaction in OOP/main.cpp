#include <iostream>

using namespace std;

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
};

//#define STRACT_POINT

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

	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y() << endl;
}