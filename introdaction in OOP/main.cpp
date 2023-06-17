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
		double distance;        // Хотя скорее всего так как метод принадлежит определенной точки, то в задании говорится про другую точку и нужно найти расстояние до неё, сделал этот метод ниже
		distance = round(sqrt(x * x + y * y)*100)/100;
		return distance;
	}
	double distance_from_point(double x2, double y2) const // На всякий случай сделал метод, который вычисляет расстояние до указанной точки, от текущей точки
	{
		return round(sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)) * 100) / 100;
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

	Point A; //Точка А и В для удобства заданы внутри программы, хотя можно и сделать чтобы их вводили

	A.set_x(2);
	A.set_y(3);

	Point B;
	B.set_x(4);
	B.set_y(5);

	cout << "Расстояние от начала оси координат до точки A с координатами x = " << A.get_x() << " и  y = " << A.get_y() << " равно " << A.distance() << endl << endl;
	
	cout << "(Function)Расстояние от точки А с координатами (" << A.get_x() << "," << A.get_y() << ") до точки B с координатами (";
	cout << B.get_x() << "," << B.get_y() << ") составляет " << distance(A.get_x(), A.get_y(), B.get_x(), B.get_y()) << endl << endl;

	cout << "(Method)Расстояние от точки А с координатами (" << A.get_x() << "," << A.get_y() << ") до точки B с координатами (";
	cout << B.get_x() << "," << B.get_y() << ") составляет " << A.distance_from_point(B.get_x(), B.get_y()) << endl;

	
}

double distance(const double x1, const double y1, const double x2, const double y2)
{
	return round(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) * 100) / 100;
}