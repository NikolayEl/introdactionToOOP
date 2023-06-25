﻿#include <iostream>

using namespace std;
using std::cin;
using std::cout;

class Fraction;
ostream& operator<<(ostream& out, Fraction& obj);
istream& operator>>(istream& in, Fraction& obj);

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
	Fraction(int integer = 0, double numenator = 0, double denominator = 1) //знаменатель 1 т.к. на 0 делить нельзя, а если разделить на 1 всегда будет в числителе тоже самое число
	{
		this->integer = integer;
		this->numenator = numenator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Distructor:\t" << this << endl;
	}
	// ----------------------- Operators
	friend istream& operator>>(istream& in, Fraction& obj);
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
	}
	Fraction& operator-() // Унарный минус
	{
		this->integer = -integer;
		return *this;
	}
	Fraction& operator+() // Унарный плюс
	{
		this->integer = +integer;
		return *this;
	}
	Fraction& operator++() //Префексный инкремент
	{
		++integer;
		return *this;
	}
	Fraction& operator--() //Префексный декремент
	{
		--integer;
		return *this;
	}
	Fraction operator++(int) //Постфиксный инкремент
	{
		Fraction old = *this; // Сохраняем старое значение
		integer++;
		return old;
	}
	Fraction operator--(int) //Постфиксный декремент
	{
		Fraction old = *this; // Сохраняем старое значение
		integer--;
		return old;
	}


	// 
	//------------------------ Methods
	void reduction() //Перед любыми вычислениями и сравнениями хочу применять этот метод для соркащения дроби
	{
		if (numenator >= denominator)
		{
			integer += (numenator / denominator);
			numenator -= (int(numenator / denominator)) * denominator;
		}
		for (int i = 2; i < 98; i++)  // Сделал сокращения до 97, больше нет смысла, не работаем обычно с большими числами
		{
			if (int(numenator) % i == 0 && int(denominator) % i == 0)
			{
				numenator /= i;
				denominator /= i;
			}
		}
	}
	void print()
	{
		reduction(); //Пока поставил на вывод, т.к. не происходит изменение числа, а только его сокращение, по сути число в целом остается тем же
		if (denominator == 1 || numenator == 0)
		{
			cout << integer << endl;
		}
		else
		{
			cout << integer << "(" << numenator << "/" << denominator << ")" << endl;
		}
	}

};

void main()
{
	setlocale(LC_ALL, "");
	Fraction A(2, 22, 4);
	cout << "Дробь А: " << A << endl;
	A++;
	cout << "A++: " << A << endl;
	Fraction B = A;
	cout << "B = A: " << B << endl;
	cout << "Унарный минус -A: " << -A << endl;
	cout << "Унарный плюс +A: " << +A << endl;
	cout << "Префексный инкремент ++A: " << ++A << endl;
	cout << "Префексный декремент --A: " << --A << endl;
	A++;
	cout << "Постфиксный инкремент A++: " << A << endl;
	A--;
	cout << "Постфиксный декремент A--: " << A << endl;
	
}

ostream& operator<<(ostream& out, Fraction& obj)
{
	obj.reduction();
	if (obj.get_denominator() == 1 || obj.get_numenator() == 0)
	{
		return out << obj.get_integer();
	}
	else
	{
		return out << obj.get_integer() << "(" << obj.get_numenator() << "/" << obj.get_denominator() << ")" << endl;
	}
}

istream& operator>>(istream& in, Fraction& obj)
{
	cout << "Ввведите целую часть дроби: ";
	in >> obj.integer;
	cout << "Введите числитель: ";
	in >> obj.numenator;
	cout << "Введите знаменатель: ";
	in >> obj.denominator;
	return in;
}