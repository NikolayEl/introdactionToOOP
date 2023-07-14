#include "String.h"

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

