#include<iostream>
using namespace std;

class Integer
{
	int number;
public:
	int get_number()const
	{
		return number;
	}
	void set_number(int number)
	{
		this->number = number;
	}
	Integer(int number=0)
	{
		this->number = number;
		cout << "Constructor:\t" << this << endl;
	}
	Integer(const Integer& other)
	{
		this->number = other.number;
		cout << "CopyConstructor:" << this << endl;
	}
	~Integer()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	Integer& operator=(const Integer& other)
	{
		this->number = other.number;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Integer& operator++()
	{
		number++;
		return *this;
	}
	Integer operator++(int)
	{
		Integer old = *this;
		number++;
		return old;
	}

	//				  Methods:
	void print()const
	{
		cout << number << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Integer& obj)
{
	return os << obj.get_number();
}

Integer operator+(const Integer& left, const Integer& right)
{
	return Integer(left.get_number() + right.get_number());
}

//#define TASK_1

void main()
{
	setlocale(LC_ALL, "");
#ifdef TASK_1
	/*Integer a = 2;
a.print();

Integer b = 3;
b.print();

a = b++;

a.print();
b.print();*/

	Integer i = 3;
	i = i++ + ++i;
	cout << i << endl;
#endif // TASK_1


}