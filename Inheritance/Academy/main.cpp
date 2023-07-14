#include<iostream>
using namespace std;

class Human
{
protected:
	string last_name;
	string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
};

class Student :public Human
{
	void print()const
	{
		this->
	}
};

void main()
{
	setlocale(LC_ALL, "");

}