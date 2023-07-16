#include "Fraction.h"

// ---------------------  GET METHODS
double Fraction::get_integer(void) const // Создаем методы get для вывода значений
{
	return integer;
}
double Fraction::get_numerator(void) const
{
	return numerator;
}
double Fraction::get_denominator(void) const
{
	return denominator;
}
// ---------------------- SET METHODS
void Fraction::set_integer(double integer) // Создаем set методы для ввода значений
{
	this->integer = integer;
}
void Fraction::set_numerator(double numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(double denominator)
{
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}
// ----------------------- Constructors
Fraction::Fraction() :integer(0), numerator(0), denominator(1)
{
	cout << "DefaultConstraction:\t" << this << endl;
}
Fraction::Fraction(double number)
{
	number += 1e-10; //1*10^-10;
	integer = number;
	number -= integer;
	denominator = 1e+9; // 1 * 10^9 точность всегда будет 9 знаков после запятой
	numerator = number * denominator;
	reduce();
	cout << "1ArgDConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer) :integer(integer), numerator(0), denominator(1)
{
	cout << "OneArgConstructor:\t" << this << endl;
}
Fraction::Fraction(double numerator, double denominator) :integer(0), numerator(numerator)
{
	set_denominator(denominator);
	cout << "Constructor(two parametrs):\t" << this << endl;
}
Fraction::Fraction(int integer, double numerator, double denominator) :integer(integer), numerator(numerator)
{
	set_denominator(denominator);
	cout << "Constructor(three parametrs):\t" << this << endl;
}
Fraction::Fraction(const Fraction& other) :integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}
// ----------------------- Operators
//-----------------------------------------------
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator-() // Унарный минус
{
	this->integer = -integer;
	return *this;
}
Fraction& Fraction::operator+() // Унарный плюс
{
	this->integer = +integer;
	return *this;
}
Fraction& Fraction::operator++() //Префексный инкремент
{
	++integer;
	return *this;
}
Fraction& Fraction::operator--() //Префексный декремент
{
	--integer;
	return *this;
}
Fraction Fraction::operator++(int) //Постфиксный инкремент
{
	Fraction old = *this; // Сохраняем старое значение
	integer++;
	return old;
}
Fraction Fraction::operator--(int) //Постфиксный декремент
{
	Fraction old = *this; // Сохраняем старое значение
	integer--;
	return old;
}

Fraction Fraction::operator+=(const Fraction& other)
{
	return (*this = *this + other).to_proper().reduction();
}
Fraction Fraction::operator-=(const Fraction& other)
{
	return (*this = *this - other).to_proper().reduction();
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return (*this = *this * other).to_proper().reduction(); //code with OA
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return (*this = *this * other.inverted()).to_proper().reduction();
}
//						   Type-cast operators

Fraction::operator int() const
{
	return integer;
}
Fraction::operator double() const
{
	return integer + numerator / denominator;
}


//------------------------ Methods
Fraction& Fraction::reduction() //reduce() - по заданию ОА
{
	//Сделал его Function
	//------------------------------------------- Сделаю сокращение по Евклиду
	numerator = round((numerator * 10) / 10);
	if (this->numerator == 0) return *this;
	float max = (denominator > 0 ? denominator : -denominator), min = (numerator > 0 ? numerator : -numerator), temp;
	if (min > max) max = (numerator > 0 ? numerator : -numerator), min = (denominator > 0 ? denominator : -denominator); // беру значение max&min по модулю ибо знак не влияет на итоговый НОД (наибольший общий делитель)
	while (max != min)
	{
		max = max - min;
		if (max < min) temp = min, min = max, max = temp;
	}
	numerator /= min;
	denominator /= min;
	//-------------------------------------------

	if (numerator < 0 && integer < 0) numerator = -numerator; //чтобы знаменатель был не отрицательным
	if (numerator < 0 && integer > 0) integer = -integer, numerator = -numerator; //в случае если минус не перенесся
	return *this;

}
Fraction& Fraction::reduce()
{
	//int more, less, rest;
	//if (numerator > denominator) more = numerator, less = denominator;
	//else more = denominator, less = numerator;
	numerator = round((numerator * 10) / 10);
	if (this->numerator == 0) return *this;
	to_proper();
	int more = denominator;
	int less = numerator;
	int rest;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more; //GCD - Greatest Common Divisor (Наибольший общий дилитель НОД)
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
Fraction& Fraction::to_proper()
{
	if (denominator < 0)
	{
		denominator = -denominator;
		integer = -integer;
	}
	if (numerator >= denominator || -numerator >= denominator)
	{
		integer += (numerator / denominator);
		//numenator %= denominator; // Работает на инте, от ОА
		numerator -= (int(numerator / denominator)) * denominator;
		if (numerator < 0) numerator = -numerator; //чтобы знаменатель был не отрицательным
		if (numerator < 0 && integer > 0) integer = -integer;
	}
	return *this;
}
Fraction& Fraction::to_improper()
{
	if (integer < 0) numerator = -numerator; //сделано при работе с отрицательными числами
	if (denominator < 0)
	{
		denominator = -denominator;
		integer = -integer;
	}
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction Fraction::inverted() const
{
	Fraction inverted = *this;
	inverted.to_improper();
	if (numerator < 0)
	{
		inverted.denominator = -inverted.denominator;
		inverted.numerator = -inverted.numerator;
	}
	std::swap(inverted.numerator, inverted.denominator);
	return inverted;
}
void Fraction::print() const
{
	if (integer)cout << integer;
	if (!numerator && !integer)
	{
		cout << 0;
	}
	else if (integer != 0)
	{
		cout << "(" << numerator << "/" << denominator << ")" << endl;
	}
	else
	{
		cout << numerator << "/" << denominator << endl;
	}
}

ostream& operator<<(ostream& out, const Fraction& obj)
{
	if (!obj.get_integer() && !obj.get_numerator()) return out << 0;
	if (obj.get_numerator() == 0 && obj.get_integer() > 0)
	{
		return out << obj.get_integer();
	}
	else
	{
		if (obj.get_integer()) return out << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
		else return out << obj.get_numerator() << "/" << obj.get_denominator();
	}
}

istream& operator>>(istream& in, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//in >> buffer;
	in >> buffer;
	if (atoi(buffer) < atof(buffer)) //проверка введена ли была десятичная дробь
	{
		Fraction Temp_A = atof(buffer);
		obj.set_integer(Temp_A.get_integer());
		obj.set_numerator(Temp_A.get_numerator());
		obj.set_denominator(Temp_A.get_denominator());
		return in;
	}
	int number[3] = {};
	int n = 0; // счетчик введенных чисел
	char delimiters[] = "()/.";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = std::atoi(pch);
	switch (n)
	{
	case 1:obj = Fraction(number[0]); break;
	case 2:obj = Fraction(number[0], number[1]);
		//obj.set_numerator(number[0]);
		//obj.set_denominator(number[1]);
		break;
	case 3:
		obj = Fraction(number[0], number[1], number[2]);
		//obj.set_integer(number[0]);
		//obj.set_numerator(number[1]);
		//obj.set_denominator(number[2]);
	}
	return in;
	// atoi - ASCII-string to 'int', принимает строку и возвращает целое число, которое содержится в этой строке
	//for (int i = 0; i < n; i++) cout << number[i] << "\t"; cout << endl;
	//double temp_int;
	//double temp_num, temp_den;
	//in >> temp_int;
	//if (int(temp_int) < temp_int) //Простая проверка на тип данных ввели целое число или дробное
	//{
	//	Fraction Temp_A = temp_int;
	//	obj.set_integer(Temp_A.get_integer());
	//	obj.set_numerator(Temp_A.get_numerator());
	//	obj.set_denominator(Temp_A.get_denominator());
	//}
	//else
	//{
	//	obj.set_integer(temp_int);
	//	in >> temp_num;
	//	obj.set_numerator(temp_num);
	//	in >> temp_den;
	//	obj.set_denominator(temp_den);

	//}
}

// ----------------- Арифметические операторы вынесем за класс
Fraction operator+(const Fraction& left, const Fraction& right) // Оператор сложение
{
	double common_denominator = left.get_denominator() * right.get_denominator();
	double left_nominator = left.get_integer() * common_denominator + (left.get_numerator() * right.get_denominator());
	double right_nominator = right.get_integer() * common_denominator + (right.get_numerator() * left.get_denominator());
	return Fraction(0, left_nominator + right_nominator, common_denominator).to_proper().reduction();
}
Fraction operator-(const Fraction& left, const Fraction& right) // Оператор вычитания
{
	double common_denominator = left.get_denominator() * right.get_denominator();
	double left_nominator = left.get_integer() * common_denominator + (left.get_numerator() * right.get_denominator());
	double right_nominator = right.get_integer() * common_denominator + (right.get_numerator() * left.get_denominator());
	return Fraction(0, left_nominator - right_nominator, common_denominator).to_proper().reduction();
}
Fraction operator*(Fraction left, Fraction right) // Оператор умножения
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator()).to_proper().reduction();
}
Fraction operator/(const Fraction& left, const Fraction& right) // Оператор вычитания
{
	return (left * right.inverted()).to_proper().reduction();
}

//-------------------- bool Function and операторы сравнения
bool operator ==(const Fraction& left, const Fraction& right)
{
	//left.to_improper(); //code of OA
	//right.to_improper();
	//return (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator()) 
	return ((left.get_integer() * left.get_denominator() * right.get_denominator() + right.get_denominator() * left.get_numerator()) == (right.get_integer() * right.get_denominator() * left.get_denominator() + left.get_denominator() * right.get_numerator()));
}
bool operator !=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator >=(const Fraction& left, const Fraction& right)
{
	return ((left.get_integer() * left.get_denominator() * right.get_denominator() + right.get_denominator() * left.get_numerator()) >= (right.get_integer() * right.get_denominator() * left.get_denominator() + left.get_denominator() * right.get_numerator()));
}
bool operator <=(const Fraction& left, const Fraction& right)
{
	return ((left.get_integer() * left.get_denominator() * right.get_denominator() + right.get_denominator() * left.get_numerator()) <= (right.get_integer() * right.get_denominator() * left.get_denominator() + left.get_denominator() * right.get_numerator()));
}
bool operator >(const Fraction& left, const Fraction& right)
{
	return !(left <= right);
}
bool operator <(const Fraction& left, const Fraction& right)
{
	return !(left >= right);
}

int& number_simbol_after(double const& number)
{
	int count = 0;
	float temp = number;
	while (temp != double(int(temp))) temp *= 10, count++;
	return count;
}