#include <iostream>

using namespace std;
using std::cin;
using std::cout;

class Fraction;
ostream& operator<<(ostream& out, const Fraction& obj);
istream& operator>>(istream& in, Fraction& obj);

Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);

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
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	// ----------------------- Constructors
	Fraction()
	{
		this->integer = 0;
		this->numenator = 0;
		this->denominator = 1;
		cout << "DefaultConstraction:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numenator = 0;
		this->denominator = 1;
		cout << "ArgConstructor:\t" << this << endl;
	}
	Fraction(double numenator, double denominator)
	{
		this->integer = 0;
		this->numenator = numenator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, double numenator, double denominator) //знаменатель 1 т.к. на 0 делить нельзя, а если разделить на 1 всегда будет в числителе тоже самое число
	{
		this->integer = integer;
		this->numenator = numenator;
		set_denominator(denominator);
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
	//-----------------------------------------------
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
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
		this->numenator *= other.denominator;
		this->denominator *= other.denominator;
		this->numenator = (this->integer * this->denominator + this->numenator) + (this->denominator * other.integer + other.numenator * (this->denominator / other.denominator));
		this->integer = 0;
		return *this;
	}
	Fraction operator-=(const Fraction& other)
	{
		this->numenator *= other.denominator;
		this->denominator *= other.denominator;
		this->numenator = (this->integer * this->denominator + this->numenator) - (this->denominator * other.integer + other.numenator * (this->denominator / other.denominator));
		this->integer = 0;
		return *this;
	}
	Fraction operator*=(const Fraction& other)
	{
		this->numenator += this->integer * this->denominator;
		this->integer = 0;
		this->numenator *= other.integer * other.denominator + other.numenator;
		this->denominator *= other.denominator;
		return *this;
	}
	Fraction operator/=(const Fraction& other)
	{
		this->numenator += this->integer * this->denominator;
		this->integer = 0;
		this->numenator *= other.denominator;
		this->denominator *= other.integer * other.denominator + other.numenator;
		return *this;
	}

	//------------------------- FRIEND Operators
	friend istream& operator>>(istream& in, Fraction& obj);
	friend ostream& operator<<(ostream& out, const Fraction& obj);
	friend bool operator ==(const Fraction& left, const Fraction& right);
	friend bool operator !=(const Fraction& left, const Fraction& right);
	friend bool operator >=(const Fraction& left, const Fraction& right);
	friend bool operator <=(const Fraction& left, const Fraction& right);
	friend bool operator >(const Fraction& left, const Fraction& right);
	friend bool operator <(const Fraction& left, const Fraction& right);


	// 
	//------------------------ Methods
	void reduction() //Перед любыми вычислениями и сравнениями хочу применять этот метод для соркащения дроби
	{
		for (int i = 2; i < 98; i++)  // Сделал сокращения до 97, больше нет смысла, не работаем обычно с большими числами
		{
			while (int(numenator) % i == 0 && int(denominator) % i == 0)
			{
				numenator /= i;
				denominator /= i;
			}
		}
		if (numenator < 0) numenator = -numenator; //чтобы знаменатель был не отрицательным
		if (numenator < 0 && integer > 0) integer = -integer; //в случае если минус не перенесся
	}
	void to_proper()
	{
		if (numenator >= denominator || -numenator >= denominator)
		{
			integer += (numenator / denominator);
			//numenator %= denominator; // Работает на инте, от ОА
			numenator -= (int(numenator / denominator)) * denominator;
			if (numenator < 0) numenator = -numenator; //чтобы знаменатель был не отрицательным
		}
	}
	void to_improper()
	{
		if (integer > 0)
		{
			numenator += integer * denominator;
			integer = 0;
		}
	}
	void print()
	{
		reduction(); //Пока поставил на вывод, т.к. не происходит изменение числа, а только его сокращение, по сути число в целом остается тем же
		if (integer)cout << integer;
		if (denominator == 1 || numenator == 0)
		{
			cout << 0;
		}
		else if (integer > 0)
		{
			cout << "(" << numenator << "/" << denominator << ")" << endl;
		}
		else
		{
			cout << numenator << "/" << denominator << endl;
		}
	}

};

//#define HOME_WORK
//#define HOME_WORK2

void main()
{
	setlocale(LC_ALL, "");
#ifdef HOME_WORK
	Fraction A(2, 22, 4);
	Fraction B;
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
	cin >> C;
	cout << "Дробь С: " << C << endl;
	B = { 0, 11, 3 };
	A.reduction();
	B.reduction();
	C = (A + B);
	C.reduction();
	cout << "Сложим дроби A: " << A << " и B: " << B << " = " <<  A + B << ", Сокращенно: " << C << endl;
	C = (A - B);
	C.reduction();
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
	cout << A << endl;
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

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();
	
	Fraction C = A * B;
	C.print();
	C.to_proper();
	C.print();
}

ostream& operator<<(ostream& out, const Fraction& obj)
{
	if (obj.get_denominator() == 1 || obj.get_numenator() == 0)
	{
		return out << obj.get_integer();
	}
	else
	{
		if(obj.integer) return out << obj.get_integer() << "(" << obj.get_numenator() << "/" << obj.get_denominator() << ")";
		else return out <<  obj.get_numenator() << "/" << obj.get_denominator();
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

// ----------------- Арифметические операторы вынесем за класс
Fraction operator+(const Fraction& left, const Fraction& right) // Оператор сложение
{
	double common_denominator = left.get_denominator() * right.get_denominator();
	double left_nominator = left.get_integer() * common_denominator + (left.get_numenator() * right.get_denominator());
	double right_nominator = right.get_integer() * common_denominator + (right.get_numenator() * left.get_denominator());
	return Fraction(0, left_nominator + right_nominator, common_denominator);
}
Fraction operator-(const Fraction& left, const Fraction& right) // Оператор вычитания
{
	double common_denominator = left.get_denominator() * right.get_denominator();
	double left_nominator = left.get_integer() * common_denominator + (left.get_numenator() * right.get_denominator());
	double right_nominator = right.get_integer() * common_denominator + (right.get_numenator() * left.get_denominator());
	return Fraction(0, left_nominator - right_nominator, common_denominator);
}
Fraction operator*(const Fraction& left, const Fraction& right) // Оператор вычитания
{
	double common_denominator = left.get_denominator() * right.get_denominator();
	double left_nominator = left.get_integer() * left.get_denominator() + left.get_numenator();
	double right_nominator = right.get_integer() * right.get_denominator() + right.get_numenator();

	return Fraction(0, left_nominator * right_nominator, common_denominator);
}
Fraction operator/(const Fraction& left, const Fraction& right) // Оператор вычитания
{
	double left_nominator = left.get_integer() * left.get_denominator() + left.get_numenator();
	double right_nominator = right.get_integer() * right.get_denominator() + right.get_numenator();

	return Fraction(0, left_nominator * right.get_denominator(), left.get_denominator() * right_nominator);
}

//-------------------- bool Function and операторы сравнения
bool operator ==(const Fraction& left, const Fraction& right)
{
	return ((left.integer * left.denominator * right.denominator + right.denominator * left.numenator) == (right.integer * right.denominator * left.denominator + left.denominator * right.numenator));
}
bool operator !=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator >=(const Fraction& left, const Fraction& right)
{
	return ((left.integer * left.denominator * right.denominator + right.denominator * left.numenator) >= (right.integer * right.denominator * left.denominator + left.denominator * right.numenator));
}
bool operator <=(const Fraction& left, const Fraction& right)
{
	return ((left.integer * left.denominator * right.denominator + right.denominator * left.numenator) <= (right.integer * right.denominator * left.denominator + left.denominator * right.numenator));
}
bool operator >(const Fraction& left, const Fraction& right)
{
	return ((left.integer * left.denominator * right.denominator + right.denominator * left.numenator) > (right.integer * right.denominator * left.denominator + left.denominator * right.numenator));
}
bool operator <(const Fraction& left, const Fraction& right)
{
	return ((left.integer * left.denominator * right.denominator + right.denominator * left.numenator) < (right.integer * right.denominator * left.denominator + left.denominator * right.numenator));
}