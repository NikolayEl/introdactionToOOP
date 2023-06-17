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
	double distance(void) const // ��� ��� �� ������� �� ����� ����� �� ���� ����������, �� �� ��������� ������� ��� �� ������ ��� ���������, 
	{							// � const ������ ��� � ���� ������� �� �� ������ ����������� �������� ����� � ���������� �� ����� ����� ������ ����������
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
	int a; // ���������� ���������� '�' ���� 'int'
	Point A; //���������� ���������� '�' ���� 'Poin'
			// �������� ������� 'A' ��������� 'Point'
			// �������� ���������� 'A' ��������� 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

#endif // STRACT_POINT

	Point A; //����� � � � ��� �������� ������ ������ ���������, ���� ����� � ������� ����� �������

	A.set_x(2);
	A.set_y(3);
	cout << "���������� �� ������ ��� ��������� �� ����� A � ������������ x = " << A.get_x() << " �  y = " << A.get_y() << " ����� " << A.distance() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);

	cout << "���������� �� ����� � � ������������ (" << A.get_x() << "," << A.get_y() << ") �� ����� B � ������������ (";
	cout << B.get_x() << "," << B.get_y() << ") ���������� " << distance(A.get_x(), A.get_y(), B.get_x(), B.get_y()) << endl;

	
}

double distance(const double x1, const double y1, const double x2, const double y2)
{
	double distance;
	distance = round(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) * 100)/100;
	return distance;
}