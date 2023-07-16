#pragma once
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>

using namespace std;
using std::cin;
using std::cout;

#define delimeter "\n------------------------------------------------------------------------\n"

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
	float numerator;
	float denominator;
public:
	// ---------------------  GET METHODS
	double get_integer(void) const;
	double get_numerator(void) const;
	double get_denominator(void) const;
	// ---------------------- SET METHODS
	void set_integer(double integer);
	void set_numerator(double numerator);
	void set_denominator(double denominator);
	// ----------------------- Constructors
	Fraction();
	Fraction(double number);
	explicit Fraction(int integer);
	Fraction(double numerator, double denominator);
	Fraction(int integer, double numerator, double denominator);
	Fraction(const Fraction& other);
	~Fraction();
	// ----------------------- Operators
	//-----------------------------------------------
	Fraction& operator=(const Fraction& other);
	Fraction& operator-();
	Fraction& operator+();
	Fraction& operator++();
	Fraction& operator--();
	Fraction operator++(int);
	Fraction operator--(int);

	Fraction operator+=(const Fraction& other);
	Fraction operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	//						   Type-cast operators

	explicit operator int() const;
	explicit operator double() const;


	//------------------------ Methods
	Fraction& reduction();
	Fraction& reduce();
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted() const;
	void print() const;

};