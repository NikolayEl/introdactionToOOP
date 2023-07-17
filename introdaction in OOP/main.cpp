#include "Fraction.h"
//#include <MyString.h>



//#define HOME_WORK
//#define HOME_WORK2
#define HOME_WORK3
//#define INPUT_CHEK_1
//#define INPUT_CHEK_2
//#define INPUT_CHEK_3
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER

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
	cout << "Сложим дроби A: " << A << " и B: " << B << " = " << A + B << ", Сокращенно: " << C << endl;
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

	Fraction B(3, 16, 20);
	B.print();

	//Fraction C = A * B;
	//C.print();

	//Fraction D = A / B;
	//D.print();
	A *= B;
	A.print();
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
	((A / -B) + 10).to_proper().print();
	Fraction C(2695, 3465); //Проверка сокращения по Евклиду
	C.print();
	C.reduction();
	C.print();
#endif //HOME_WORK3
#ifdef	INPUT_CHEK_1
	Fraction A = 2.75;
	cout << A << endl;
	Fraction B;
	cout << "Введите дробь в правильном или неправильном виде, либо сразу дробь в десятичном виде: ";
    cin >> B; //Можно ввести в десятичном виде 2.75
	cout << B << endl;
	B.reduce();
	//B.reduction();
	cout << B << endl;
#endif //INPUT_CHEK_1
#ifdef	INPUT_CHEK_2
	Fraction A, B, C;
	cout << "Введите 3 прострые дроби: "; cin >> A >> B >> C;
	cout << A << "\t" << B << "\t" << C << endl;
#endif //INPUT_CHEK_2
#ifdef INPUT_CHEK_3
	int a = 2;  //No conversion
	double b = 3; //Conversion  from less to more
	int c = b; //Conversion from more to less without data loss
	int d = 5.7; //Conversion from more to less with data loss
	//int e = "Hello"; //Types not compatible
	cout << 7 / 2 << endl;
	cout << 7. / 2 << endl; //Implicit conversion from less to more.  
#endif // INPUT_CHEK_3
#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;
	cout << A << endl;
	cout << delimeter << endl;
	Fraction B; //Default Constructor
	cout << delimeter << endl;
	B = Fraction(8);
	cout << delimeter << endl;
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS
#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 1, 2);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;

	Fraction B(2, 3, 4);
	cout << B << endl;
	double b = (double)B;
	cout << b << endl;

#endif // CONVERSION_FROM_CLASS_TO_OTHER

	//String str("Test");
	//str.print();


}
