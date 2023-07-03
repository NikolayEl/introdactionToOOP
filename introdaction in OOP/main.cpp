﻿#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
using std::cin;
using std::cout;

class Fraction;
ostream& operator<<(ostream& out, const Fraction& obj);
istream& operator>>(istream& in, Fraction& obj);

Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

bool operator ==(const Fraction& left, const Fraction& right);
bool operator !=(const Fraction& left, const Fraction& right);
bool operator >=(const Fraction& left, const Fraction& right);
bool operator <=(const Fraction& left, const Fraction& right);
bool operator >(const Fraction& left, const Fraction& right);
bool operator <(const Fraction& left, const Fraction& right);

int& number_simbol_after(double const& number);

class Fraction
{
	int integer;
	double numerator;
	double denominator;
public:
	// ---------------------  GET METHODS
	double get_integer(void) const // Создаем методы get для вывода значений
	{
		return integer;
	}
		double get_numerator(void) const
	{
		return numerator;
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
	void set_numerator(double numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(double denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	// ----------------------- Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstraction:\t" << this << endl;
	}
	Fraction(double const number)
	{
		this->integer = (int)number;
		this->numerator = number - integer;
		this->denominator = 1;
		for (int i = 0; i < number_simbol_after(number); i++) this->numerator *= 10, this->denominator *= 10;
		cout << "TypeDoubleConstructor:\t" << this << endl;
		//this->reduce(); Не уверен, что сокращать в конструктуре - это верно!
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "ArgConstructor:\t" << this << endl;
	}
	Fraction(double numerator, double denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, double numerator, double denominator) //знаменатель 1 т.к. на 0 делить нельзя, а если разделить на 1 всегда будет в числителе тоже самое число
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Distructor:\t" << this << endl;
	}
	// ----------------------- Operators
	//-----------------------------------------------
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
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

	Fraction operator+=(const Fraction& other)
	{
		return (*this = *this + other).to_proper().reduction();
	}
	Fraction operator-=(const Fraction& other)
	{
		return (*this = *this - other).to_proper().reduction();
	}
	Fraction& operator*=(const Fraction& other)
	{
		return (*this = *this * other).to_proper().reduction(); //code with OA
	}
	Fraction& operator/=(const Fraction& other)
	{
		return (*this = *this * other.inverted()).to_proper().reduction();
	}
	
	//------------------------ Methods
	Fraction& reduction() //reduce() - по заданию ОА
	{
		//Сделал его Function
		//------------------------------------------- Сделаю сокращение по Евклиду
		if (this->numerator == 0) return *this;
		double max = (denominator > 0?denominator:-denominator), min = (numerator > 0 ? numerator:-numerator), temp;
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
	Fraction& reduce()
	{
		//int more, less, rest;
		//if (numerator > denominator) more = numerator, less = denominator;
		//else more = denominator, less = numerator;
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
	Fraction& to_proper()
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
	Fraction& to_improper()
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
	Fraction inverted() const
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
	void print() const
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

};

//#define HOME_WORK
//#define HOME_WORK2
//#define HOME_WORK3
//#define INPUT_CHEK_1
//#define INPUT_CHEK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef HOME_WORK
	Fraction A(2, 22, 4);
	Fraction B;
	cin >> B;
	B.print();
	Fraction C;
	cout << "B: " << B << ", C: " << C << endl;
	cout << "Дробь А: " << A << endl;
	A++;
	cout << "A++: " << A << endl;
	B = A;
	cout << "B = A: " << B << endl;
	cout << "Унарный минус -A: " << -A << endl;
	cout << "Унарный плюс +A: " << +A << endl;
	cout << "Префексный инкремент ++A: " << ++A << endl;
	cout << "Префексный декремент --A: " << --A << endl;
	A++;
	cout << "Постфиксный инкремент A++: " << A << endl;
	A--;
	cout << "Постфиксный декремент A--: " << A << endl;
	cout << "Давайте зададим с клавиатуры дробь С" << endl;
	C = { 0, 1 , 2 };
	cout << "Дробь С: " << C << endl;
	B = { 0, 11, 3 };
	A.reduction();
	A.to_proper();
	B.to_proper();
	B.reduction();
	C = (A + B);
	C.reduction();
	C.to_proper();
	cout << "Сложим дроби A: " << A << " и B: " << B << " = " << A + B << ", Сокращенно: " << C << endl;
	C = A - B;
	C.reduction();
	C.to_proper();
	cout << "Вычтем дроби A: " << A << " и B: " << B << " = " << A - B << ", Сокращенно: " << C << endl;
	C = (A * B);
	C.reduction();
	cout << "Умножем дроби A: " << A << " и B: " << B << " = " << A * B << ", Сокращенно: " << C << endl;
	C = (A / B);
	C.reduction();
	cout << "Разделим дроби A: " << A << " и B: " << B << " = " << A / B << ", Сокращенно: " << C << endl;

	cout << "С дробью А = " << A << " и дробью В = " << B << endl;
	A += B;
	A.reduction();
	cout << "совершим действие А += B, итого: " << A << endl;

	cout << "С дробью А = " << A << " и дробью В = " << B << endl;
	A -= B;
	A.reduction();
	cout << "совершим действие А -= B, итого: " << A << endl;

	cout << "С дробью А = " << A << " и дробью В = " << B << endl;
	A *= B;
	A.reduction();
	cout << "совершим действие А *= B, итого: " << A << endl;

	cout << "С дробью А = " << A << " и дробью В = " << B << endl;
	A /= B;
	A.reduction();
	cout << "совершим действие А /= B, итого: " << A << endl;

	//B = {2, 2, 4}; //Проверим на true ниже, специально делаю дроби с разным знаменателем, но должны быть равные
	cout << "Сравним (оператор ==) дробь А = " << A << " с дробью В = " << B << endl;
	cout << (A == B ? "True" : "False") << endl;

	cout << "Сравним (оператор !=) дробь А = " << A << " с дробью В = " << B << endl;
	cout << (A != B ? "True" : "False") << endl;

	//A = B; // Проверка на true в оператарах <=&&>=, а так же на false в операторах ><
	cout << "Сравним (оператор >=) дробь А = " << A << " с дробью В = " << B << endl;
	cout << (A >= B ? "True" : "False") << endl;

	cout << "Сравним (оператор <=) дробь А = " << A << " с дробью В = " << B << endl;
	cout << (A <= B ? "True" : "False") << endl;
	cout << "Сравним (оператор >) дробь А = " << A << " с дробью В = " << B << endl;
	cout << (A > B ? "True" : "False") << endl;

	cout << "Сравним (оператор <) дробь А = " << A << " с дробью В = " << B << endl;
	cout << (A < B ? "True" : "False") << endl;
#endif //HOME_WORK
#ifdef HOME_WORK2
	Fraction A(1, 4, 8);
	cout << "Fraction A: " << A << endl;
	A.to_improper();
	cout << "Fraction A after to improper: " << A << endl;
	A.to_proper();
	cout << "Fraction A after to proper: " << A << endl;
	A.reduction();
	cout << "Fraction A after reduction: " << A << endl;
#endif //HOME_WORK2

#ifdef HOME_WORK3
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 16, 20);
	B.print();

	//Fraction C = A * B;
	//C.print();

	//Fraction D = A / B;
	//D.print();
	A *= B;
	A.print();
	A -= B;
	A.print();
	cout << A << endl;
	A.to_improper();
	A.print();
	A.to_proper();
	A.print();
	B.print();
	B = -B;
	B.to_improper();
	B.print();
	A.to_improper();
	A.print();
	cout << B.inverted() << endl;
	cout << A / -B << endl;
	((A / -B) + 10).to_proper().print();
	Fraction C(2695, 3465); //Проверка сокращения по Евклиду
	C.print();
	C.reduction();
	C.print();
#endif //HOME_WORK3
#ifdef	INPUT_CHEK_1
	Fraction A = 2.75;
	cout << A << endl;
	Fraction B;
	cout << "Введите число либо последовательно целую часть, числитель и знаминатель, либо сразу дробь в десятичном виде: ";
	cin >> B; //Можно ввести в десятичном виде 2.75
	cout << B << endl;
	B.reduce();
	B.reduction();
	cout << B << endl;
#endif //INPUT_CHEK_1
#ifdef	INPUT_CHEK_2
	Fraction A, B, C;
	cout << "Введите 3 прострые дроби: "; cin >> A >> B >> C;
	cout << A << "\t" << B << "\t" << C << endl;
#endif //INPUT_CHEK_2
	int a = 2;  //No conversion
	double b = 3; //Conversion  from less to more
	int c = b; //Conversion from more to less without data loss
	int d = 5.7; //Conversion from more to less with data loss
	//int e = "Hello"; //Types not compatible
	cout << 7 / 2 << endl;
	cout << 7. / 2 << endl; //Implicit conversion from less to more.


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
		if(obj.get_integer()) return out << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
		else return out <<  obj.get_numerator() << "/" << obj.get_denominator();
	}
}

istream& operator>>(istream& in, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//in >> buffer;
	in >> buffer;
	int number[3] = {};
	int n = 0; // счетчик введенных чисел
	char delimiters[] = "()/ ";
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
	double temp = number;
	while (temp != double(int(temp))) temp *= 10, count++;
	return count;
}