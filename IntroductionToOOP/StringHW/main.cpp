#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tad "\t"
#define delimiter "\n-------------------------------------------------------------------------\n"
//#define CONSTRUCTORS

class String;
ostream& operator<<(ostream& os, const String& obj);
String operator+(const String& left, const String& right);

//Класс string предназначен для работы со строками типа char*, которые представляют собой строку с завершающим нулем. 
class String
{
	char* str; // адрес строкт(указатель) в динамической памяти
	int size; // размер строки в байтах
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//                                            Constructors:	
	explicit String(int size = 80)// конструктор дефолтный
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str) // конструктор //char* - указатель
	{
		this->size = strlen(str) + 1; // strlen - считает длину строки //с учетом терминирующего нуля
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) // копирование в нов
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other) // конструктор копирования побитово
	{
		//Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) // копирование в нов
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other) // MoveConstructor - конструктор переноса
	{
		// https://legacy.cplusplus.com/doc/tutorial/classes2/
		//Конструктор перемещения вызывается, когда объект инициализируется при построении с использованием неназванного временного объекта. 
		//Аналогично, назначение перемещения вызывается, когда объекту присваивается значение неназванного временного
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;

	}
	~String() // удаление
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}
	//                                                Methods:
	void print()const
	{
		cout << "size: \t" << size << endl;
		cout << "str: \t" << str << endl;
	}
	//                                                Onerators:

	char operator[](int i) const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor" << this << endl;
		return *this;
	}
	String& operator=(String&& other) //Move-assignment
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment" << this << endl;
		return *this;
	}


};

//                                                Onerators:
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	/*const int a = 2;
	a = 3;*/
	String res(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		res[i] = left[i];
		//res.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		res[i + left.get_size() - 1] = right[i];
		//res.get_str()[i+left.get_size() - 1] = left.get_str()[i];
	}
	return res;
}



void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS
	cout << sizeof("Hello") << endl;
	String str;
	str.print();
	cout << delimiter << endl;

	String str2(5);
	str2.print();
	cout << delimiter << endl;

	String str3 = "Hello";
	str3 = str3;
	cout << str3 << endl;
	cout << delimiter << endl;

	String str4 = "World";
	cout << str4 << endl;

	cout << delimiter << endl;
	String str5 = str3 + " " + str4;
	cout << str5 << endl;

	cout << delimiter << endl;
	String str6;
	str6 = str3 + str4;
	cout << str6 << endl;
#endif // CONSTRUCTORS
	String str1("Hello");
	String str2("World");
	cout << delimiter << endl;
	String str3 = str1 + str2;
	//str3 = str1 + str2;
	cout << delimiter << endl;
	cout << "str 3 = " << str3 << endl;

}