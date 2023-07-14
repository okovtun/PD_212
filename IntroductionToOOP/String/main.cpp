#include"String.h"

#define BASE_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	cout << sizeof("Hello") << endl;
	String str(5);
	str.print();

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimiter << endl;

	String str4;
	str4 = str1 + str2;
	cout << str4 << endl;

	String str5 = str4;
	cout << str5 << endl;
#endif // BASE_CHECK

#ifdef CALLING_CONSTRUCTORS
	String str1;	//Default constructor
	str1.print();

	String str2(5);
	str2.print();

	String str3 = "Hello";	//Single-argumrnt constructor
	str3.print();

	String str4();	//Таким образом, явно не вызывается конструктор по умолчанию, и следовательно объект тоже не создается,
					//Таким образом объявляется функция 'str4()', которая ничего НЕ принимает, и возвращает значение типа 'String'
	//str4.print();

	//Если нужно явно вызвать конструктор по умолчанию, то это можно сделать следующим образом:
	String str5{};	//Явный вызов конструктора по умолчанию
	str5.print();

	cout << String() << endl;
	String().print();
#endif // CALLING_CONSTRUCTORS

}