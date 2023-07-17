#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define tab "\t"
#define delimetr "\n--------------------------------------------------------------------------------------\n"

class String;
ostream& operator<<(ostream& out, const String& obj);
String operator+(const String& left, const String& right);

//									Объявление класса - Class declaration
//////////////////////////////////////////////////////////////////////////////////////////////////
class String
{
	int size; //Размер строки в байтах
	char* str; //Адрес строки в динамической памяти
public:
	//				Get method
	int get_size() const;
	const char* get_str(void) const;
	char* get_str(void);

	//				Constructors
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators
	String& operator=(const String& other);
	String& operator=(String&& other);

	char operator[](int i) const;
	char& operator[](int i);

	//				Methods
	void print() const;
};