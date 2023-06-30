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
		return (*this = *this + other).to_proper();
	}
	Fraction operator-=(const Fraction& other)
	{
		return (*this = *this - other).to_proper();
	}
	Fraction& operator*=(const Fraction& other)
	{
		return (*this = *this * other).to_proper(); //code with OA
	}
	Fraction& operator/=(const Fraction& other)
	{
		return (*this = *this * other.inverted()).to_proper();
	}
	
	//------------------------ Methods
	Fraction& reduction() //reduce() - по заданию ОА
	{
		//Сделал его Function
		//------------------------------------------- Сделаю сокращение по Евклиду
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

#define HOME_WORK
//#define HOME_WORK2
//#define HOME_WORK3

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
	cout << "Сложим дроби A: " << A << " и B: " << B << " = " <<  A + B << ", Сокращенно: " << C << endl;
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

	Fraction B(3, 4, 5);
	B.print();
	
	//Fraction C = A * B;
	//C.print();

	//Fraction D = A / B;
	//D.print();

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
	((A / -B)+ 10).to_proper().print();
	Fraction C(2695, 3465); //Проверка сокращения по Евклиду
	C.print();
	C.reduction();
	C.print();
#endif //HOME_WORK3


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
	int temp_int;
	double temp_num, temp_den;
	cout << "Ввведите целую часть дроби: ";
	in >> temp_int;
	obj.set_integer(temp_int);
	cout << "Введите числитель: ";
	in >> temp_num;
	obj.set_numerator(temp_num);
	cout << "Введите знаменатель: ";
	in >> temp_den;
	obj.set_denominator(temp_den);
	return in;
}

// ----------------- Арифметические операторы вынесем за класс
Fraction operator+(const Fraction& left, const Fraction& right) // Оператор сложение
{
	double common_denominator = left.get_denominator() * right.get_denominator();
	double left_nominator = left.get_integer() * common_denominator + (left.get_numerator() * right.get_denominator());
	double right_nominator = right.get_integer() * common_denominator + (right.get_numerator() * left.get_denominator());
	return Fraction(0, left_nominator + right_nominator, common_denominator);
}
Fraction operator-(const Fraction& left, const Fraction& right) // Оператор вычитания
{
	double common_denominator = left.get_denominator() * right.get_denominator();
	double left_nominator = left.get_integer() * common_denominator + (left.get_numerator() * right.get_denominator());
	double right_nominator = right.get_integer() * common_denominator + (right.get_numerator() * left.get_denominator());
	return Fraction(0, left_nominator - right_nominator, common_denominator);
}
Fraction operator*(Fraction left, Fraction right) // Оператор умножения
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator()).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right) // Оператор вычитания
{
	return left * right.inverted();
}

//-------------------- bool Function and операторы сравнения
bool operator ==(const Fraction& left, const Fraction& right)
{
	return ((left.get_integer() * left.get_denominator() * right.get_denominator() + right.get_denominator() * left.get_numerator()) == (right.get_integer() * right.get_denominator() * left.get_denominator() + left.get_denominator() * right.get_numerator()));
}
bool operator !=(const Fraction& left, const Fraction& right) //Единственное сравнение, которое можно взять от обратного
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