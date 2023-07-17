//#include<iostream>
#include<MyString.h>

void main()
{
	setlocale(LC_ALL, "");
	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3 = str1 + str2;
	cout << str3 << endl;
}