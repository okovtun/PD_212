#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------------------\n"

/*
--------------------------
	virtual type name(parameters)modifiers = 0;
--------------------------
*/

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;
};
//////////////////////////////////////////////////////
class GroundVehicle :public Vehicle{};
class AirVehicle :public Vehicle
{
	int height;
public:
	virtual void take_off() = 0;
	virtual void landing() = 0;
};
//////////////////////////////////////////////////////
class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Car drives on 4 wheels" << endl;
	}
};
class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "Bike drives on 2 wheels" << endl;
	}
};
///////////////////////////////////////////////////////
class Plane :public AirVehicle
{
public:
	void move()
	{
		cout << "Самолет летит на высокой скорости, и преодолевает большие расстояния" << endl;
	}
	void take_off()
	{
		cout << "Для взлета нужна ВПП" << endl;
	}
	void landing()
	{
		cout << "Для посадки тоже нужна ВПП" << endl;
	}
};
class Helicopter :public AirVehicle
{
public:
	void move()
	{
		cout << "Летает на небольшой высоте, на небольшие расстояния, и очень манервернный" << endl;
	}
	void take_off()
	{
		cout << "Взлетает откуда угодно, разгон не требуется" << endl;
	}
	void landing()
	{
		cout << "Приземлиться так же можно куда угодно" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;
	//GroundVehicle gv;

	Car bmw;
	bmw.move();
	cout << delimiter << endl;

	Bike harley_davidson;
	harley_davidson.move();
	cout << delimiter << endl;

	Plane boeing;
	boeing.take_off();
	boeing.move();
	boeing.landing();
	cout << delimiter << endl;

	Helicopter black_hawk;
	black_hawk.take_off();
	black_hawk.move();
	black_hawk.landing();
}