#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------\n"

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

	//					Constructors:
	/*Point()
	{
		x = y = double();	//type() - то значение по умолчанию для заданного типа
							//тким образом мы якобы вызываем конструктор по умолчанию для заданного типа
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	//Deep copy
	//Shallow copy
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//					Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point& operator++()	//Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;	// сохраняем исходное значение объекта
		x++;
		y++;
		return old;
	}

	//					 Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}

double distance(const Point& A, const Point& B)
{
	//pow(base, exponent);
	//base - основание степени;
	//exponent - показатель степени;
	//return pow(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2), .5);
	//return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	/*Point ;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());*/
	/*Point result
	(
		left.get_x() + right.get_x(), 
		left.get_y() + right.get_y()
	);
	return result;*/
	return Point
	(
		left.get_x() + right.get_x(),
		left.get_y() + right.get_y()
	);
}

//Point A;

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define INCREMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
			//Создание объекта 'A' сруктуры 'Point'
			//Создание экземпляра 'A' струкуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << "A:\t" << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "B:\t" << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B':\t" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A':\t" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B':\t" << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A':\t" << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << i << endl;
	cout << endl;*/

#ifdef CONSTRUCTORS_CHECK
	cout << char() << endl;
	//RAII - Resource Aquilisation - Is Initialisation	(Все что объявляется обязательно должно быть проинициализировано)
	//		 (Выделение ресурсов - это инициализация)
	Point A;		//Default constructor
	A.print();

	Point B = 5;	//Single-argument constructor
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;	//CopyConstructor
	D.print();

	Point E;
	E = D;			//CopyAssignemtn
	E.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;

	A = B = C = Point(2, 3);

	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

#ifdef INCREMENT_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;
	cout << c << endl;

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();

	A = B++;
	A.print();
	B.print();
#endif // INCREMENT_CHECK

	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();

	A += B;
	//A.print();

	//cout << typeid(cout).name() << endl;
	cout << A << endl;
}

/*
---------------------------------
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
---------------------------------
*/

/*
---------------------------------
1. Encapsulation:
	Модификаторы доступа:
		private:	закрытые поля, доступны только внутри класса.
		public:
		protected:
	get/set-методы:
		get (взять, получить)
		set (задать, установить)
2. Inheritance;
3. Polymorphism;
---------------------------------
*/

/*
---------------------------------
			Special members:
1. Constructor - это метод, который создает объект;
	-с параметрами;
	-без параметров;
	-по умолчанию - это конструктор, который может быть вызван без параметров;
					Point A;	//Default constructor
	-конструктор копирования;
	-конструктор переноса;

2. ~Destructor - это метод, который уничтожает объект по завершении его времени жизни;
3. Assignment operator;
---------------------------------
*/

/*
---------------------------------
1. Перегрузить можно только существующие операторы:
	+  - перегружается;
	++ - перегружается;
	*  - перегружается;
	** - НЕ перегружается;
2. Не все существующие операторы можно перегрузить.
   Не перегружаются:
	:: - Оператор разрешения видимости (Scope operator);
	?: - Conditional Ternary operator;
	.  - Оператор прямого доступа (Point operator)
	.* - Pointer to member selection
	#  - Preprocessor directive
	## - Preprocessor concatenation
3. Перегруженные операторы сохраняют приоритет;
4. Переопределить поведение операторов над встроенными типами невозможно;
---------------------------------
*/