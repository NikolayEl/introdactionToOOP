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
	const char* get_str(void) const
	{
		return str;
	}
	char* get_str(void)
	{
		return str;
	}
	int get_size() const
	{
		return size;
	}
	//				Set method
	/*void set_str(const char* str)
	{
		this->str = (char*)str;	//Низя так делать!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
		this->size = sizeof(str);
	}*/
	//				Constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const String& other)
	{
		//Depp Copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{	
		//this->str = nullptr;
		//this->size = 0;
		this->str = other.str;
		this->size = other.size;
		other.str = nullptr;
		other.size = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}

	String (const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
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

	char operator[](int i) const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
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
	str6 = str3 + str4;
	cout << str6 << endl;
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