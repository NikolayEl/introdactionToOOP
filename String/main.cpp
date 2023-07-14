#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define tab "\t"
#define delimetr "\n--------------------------------------------------------------------------------------\n"

class String;
ostream& operator<<(ostream& out, const String& obj);
String operator+(const String& left, const String& right);

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

int String::get_size() const //:: - Scope operator (Оператор разрешения видимости)
{
	return size;
}
const char* String::get_str(void) const
{
	return str;
}
char* String::get_str(void)
{
	return str;
}

//				Constructors
String::String(int size) :size(size), str(new char[size] {})
{

	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{

	for (int i = 0; str[i]; i++) this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Depp Copy

	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{

	other.str = nullptr;
	other.size = 0;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}

//				Operators
String& String::operator=(const String& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->str = other.str;
	this->size = other.size;
	other.str = nullptr;
	other.size = 0;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}

char String::operator[](int i) const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//				Methods
void String::print() const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;

}

#define BASE_CHEK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHEK

	//cout << sizeof("Hello") << endl;
	String str("Test");
	str.print();
	String str2(5);
	str2.print();
	String str3 = "Hello";
	str3 = str3;
	cout << str3 << endl;
	String str4 = "World";
	cout << str4 << endl;

	String str5 = str3 + str4;
	cout << str5 << endl;
	String str6;
	String str7 = str6;
	str6 = str3 + str4;
	cout << str6 << endl;

#endif // BASE_CHEK

#ifdef CAlLING_CONSTRUCTORS
	String str1; //Default constructor
	str1.print();

	String str2(5);
	str2.print();

	String str3 = "Hello";
	str3.print();

	String str4(); //Таким образом, явно не вызывается конструктор по умолчанию, и следовательно объект тоже не создается,
	//str4.print();  //Таким образом объявляется функция str4(), которая ничего не принимает, и возвращает
					// значение типа String

	//Если нужно явно вызвать конструктор по умолчанию, то это можно сделать следующим образом:
	String str5{}; //Явный вызов конструктора по умолчанию
	str5.print();

#endif // CAlLING_CONSTRUCTORS



}

ostream& operator<<(ostream& out, const String& obj)
{
	return out << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	/*const int a = 2;
	a = 3;*/
	//string left_str = left.get_str(); //my code
	//string right_str = right.get_str();
	//string temp = (left_str + right_str);
	//const char* temp_char = temp.c_str();
	//return String(temp_char);
	String cat(left.get_size() + right.get_size() - 1); //code of OA
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}