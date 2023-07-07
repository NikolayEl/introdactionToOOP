#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class String
{
	int size; //������ ������ � ������
	char* str; //����� ������ � ������������ ������
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

	cout << sizeof("Hello") << endl;
	String str;
	str.set_str("Test");
	cout << str.get_str() << endl;
	str.print();
	String str2 = 5;
	str2.print();
	String str3 = "Hello";
	str.print();
}