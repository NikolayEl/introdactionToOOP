#include "String.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//							Определение класса - class Defenition

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
//////////////////////////////////////////Определение класса
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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