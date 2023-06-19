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

	double distance(Point other)
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

double distance(Point A, Point B)
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

Point A;

//#define STRUCT_POINT
//#define DISTANCE_CHECK

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

	cout << "���������� �� ����� 'A' �� ����� 'B':\t" << A.distance(B) << endl;
	cout << "���������� �� ����� 'B' �� ����� 'A':\t" << B.distance(A) << endl;
	cout << "���������� ����� ������� 'A' � 'B':\t" << distance(A, B) << endl;
	cout << "���������� ����� ������� 'B' � 'A':\t" << distance(B, A) << endl;
#endif // DISTANCE_CHECK

	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << i << endl;
	cout << endl;*/

	Point A;	//Default constructor
	A.print();
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