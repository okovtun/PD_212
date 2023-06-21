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
		x = y = double();	//type() - �� �������� �� ��������� ��� ��������� ����
							//���� ������� �� ����� �������� ����������� �� ��������� ��� ��������� ����
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

double distance(const Point& A, const Point& B)
{
	//pow(base, exponent);
	//base - ��������� �������;
	//exponent - ���������� �������;
	//return pow(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2), .5);
	//return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//Point A;

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;	//���������� ���������� 'a' ���� 'int'
	Point A;//���������� ���������� 'A' ���� 'Point'
			//�������� ������� 'A' �������� 'Point'
			//�������� ���������� 'A' �������� 'Point'
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
	cout << "���������� �� ����� 'A' �� ����� 'B':\t" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� 'B' �� ����� 'A':\t" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� 'A' � 'B':\t" << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� 'B' � 'A':\t" << distance(B, A) << endl;
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
	//RAII - Resource Aquilisation - Is Initialisation	(��� ��� ����������� ����������� ������ ���� �������������������)
	//		 (��������� �������� - ��� �������������)
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

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;

	A = B = C = Point(2, 3);

	A.print();
	B.print();
	C.print();
}

/*
---------------------------------
.  - �������� ������� ������� (Point operator)
-> - �������� ���������� ������� (Arrow operator)
---------------------------------
*/

/*
---------------------------------
1. Encapsulation:
	������������ �������:
		private:	�������� ����, �������� ������ ������ ������.
		public:
		protected:
	get/set-������:
		get (�����, ��������)
		set (������, ����������)
2. Inheritance;
3. Polymorphism;
---------------------------------
*/

/*
---------------------------------
			Special members:
1. Constructor - ��� �����, ������� ������� ������;
	-� �����������;
	-��� ����������;
	-�� ��������� - ��� �����������, ������� ����� ���� ������ ��� ����������;
					Point A;	//Default constructor
	-����������� �����������;
	-����������� ��������;

2. ~Destructor - ��� �����, ������� ���������� ������ �� ���������� ��� ������� �����;
3. Assignment operator;
---------------------------------
*/