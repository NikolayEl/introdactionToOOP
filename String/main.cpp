#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String;
ostream& operator<<(ostream& out, const String& obj);
String operator+(const String& left, const String& right);

class String
{
	int size; //Размер строки в байтах
	char* str; //Адрес строки в динамической памяти
public:
	//				Get method
	char* get_str(void) const
	{
		return str;
	}
	//				Set method
	void set_str(const char* str)
	{
		this->str = (char*)str;
	}
	//				Constructors
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}

	String (const char* str)
	{
		this->str = (char*)str;
		cout << "1ArgDConstructor:\t" << this << endl;
	}

	~String()
	{
		//if(str)delete[] str;
		cout << "Destructor:\t" << this << endl;
	}
	//				Operators
	String& operator=(const String& other)
	{
		this->str = other.get_str();
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//				Methods
	void print() const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;

	}
};

void main()
{
	setlocale(LC_ALL, "");

	//cout << sizeof("Hello") << endl;
	String str;
	str.set_str("Test");
	cout << str.get_str() << endl;
	str.print();
	String str2 = 5;
	str2.print();
	String str3 = "Hello";
	cout << str3 << endl;
	String str4 = "World";
	cout << str4 << endl;
	String str5 = str3 + str4;
	cout << str3 + str4 << endl;
	str5.print();
	cout << str5 << endl;
}

ostream& operator<<(ostream& out, const String& obj)
{
	return out << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	string left_str = left.get_str();
	string right_str = right.get_str();
	string temp = (left_str + right_str);
	const char* temp_char = temp.c_str();
	return String(temp_char);
}