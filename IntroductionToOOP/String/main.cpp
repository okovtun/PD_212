#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

#define tab "\t"
#define delimiter "\n-------------------------------------------\n"

class String
{
	int size;	//размер строки в Байтах
	char* str;	//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//				Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str) :String(strlen(str) + 1)
	{
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other) :String(other.str)
	{
		//Deep copy
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other):size(other.size), str(other.str)
	{
		//Shallow copy:
		//this->size = other.size;
		//this->str = other.str;
		other.size = 0;
		other.str = 0;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//						Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		int a = 2;
		int b = 3;
		a = b;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//						Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	/*const int a = 2;
	a = 3;*/
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

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