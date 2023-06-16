#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x(void)const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;	//ќбъ€вление переменной 'a' типа 'int'
	Point A;//ќбъ€вление переменной 'A' типа 'Point'
			//—оздание объекта 'A' сруктуры 'Point'
			//—оздание экземпл€ра 'A' струкуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
}

/*
---------------------------------
.  - ќператор пр€мого доступа (Point operator)
-> - ќператор косвенного доступа (Arrow operator)
---------------------------------
*/

/*
---------------------------------
1. Encapsulation:
	ћодификаторы доступа:
		private:	закрытые пол€, доступны только внутри класса.
		public:
		protected:
	get/set-методы:
		get (вз€ть, получить)
		set (задать, установить)
2. Inheritance;
3. Polymorphism;
---------------------------------
*/