#include <iostream>

using namespace std;
using std::cin;
using std::cout;

class Fraction
{
	int integer;
	double numenator;
	double denominator;
public:
	// ---------------------  GET METHODS
	double get_integer(void) const // Создаем методы get для вывода значений
	{
		return integer;
	}
		double get_numenator(void) const
	{
		return numenator;
	}
		double get_denominator(void) const
	{
		return denominator;
	}
	// ---------------------- SET METHODS
	void set_integer(double integer) // Создаем set методы для ввода значений
	{
		this->integer = integer;
	}
	void set_numenator(double numenator)
	{
		this->numenator = numenator;
	}
	void set_denominator(double denominator)
	{
		this->denominator = denominator;
	}
	// ----------------------- Constructors
	Fraction(int integer = 0, double numenator = 0, double denominator = 0)
	{
		this->integer = integer;
		this->numenator = numenator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}

};

void main()
{
	setlocale(LC_ALL, "");

}