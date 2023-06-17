#include <iostream>

using namespace std;

double distance(const double x1, const double y1, const double x2, const double y2); 

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
	double distance(void) const // Так как не указано от какой точки мы ищем расстояние, то по умолчанию считаем что от начала оси координат, 
	{							// а const потому что в этой функции мы не меняем изначальных значений точки и расстояние до точки будет всегда одинаковым
		double distance;
		distance = round(sqrt(x * x + y * y)*100)/100;
		return distance;
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

	Point A; //Точка А и В для удобства задаем внутри программы, хотя можно и сделать чтобы вводили

	A.set_x(2);
	A.set_y(3);
	cout << "Расстояние от начала оси координат до точки A с координатами x = " << A.get_x() << " и  y = " << A.get_y() << " равно " << A.distance() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);

	cout << "Расстояние от точки А с координатами (" << A.get_x() << "," << A.get_y() << ") до точки B с координатами (";
	cout << B.get_x() << "," << B.get_y() << ") составляет " << distance(A.get_x(), A.get_y(), B.get_x(), B.get_y()) << endl;

	
}

double distance(const double x1, const double y1, const double x2, const double y2)
{
	double distance;
	distance = round(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) * 100)/100;
	return distance;
}