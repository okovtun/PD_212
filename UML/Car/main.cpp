#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<thread>
using namespace std;
using namespace std::chrono_literals;

#define Enter	13
#define Escape	27

#define MIN_TANK_VOLUME		20
#define MAX_TANK_VOLUME	   120
class Tank
{
	const int VOLUME;
	double fuel_level;
public:
	int get_VOLUME()const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	void fill(double fuel)
	{
		if (fuel < 0)return;
		if (fuel_level + fuel < VOLUME)fuel_level += fuel;
		else fuel_level = VOLUME;
	}
	double give_fuel(double amount)
	{
		fuel_level -= amount;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level;
	}

	Tank(int volume)
		:VOLUME
		(
			volume < MIN_TANK_VOLUME ? MIN_TANK_VOLUME :
			volume > MAX_TANK_VOLUME ? MAX_TANK_VOLUME :
			volume
		)
	{
		this->fuel_level = 0;
		cout << "Tank is ready\t" << this << endl;
	}
	~Tank()
	{
		cout << "Tank is over\t" << this << endl;
	}

	void info()const
	{
		cout << "Volume:\t\t" << VOLUME << " liters\n";
		cout << "Fuel level:\t" << get_fuel_level() << " liters\n";
	}
};

#define MIN_ENGINE_CONSUMPTION	 3
#define MAX_ENGINE_CONSUMPTION	30

class Engine
{
	const double DEFAULT_CONSUMPTION;
	const double DEFAULT_CONSUMPTION_PER_SECOND;
	double consumption_per_second;
	bool is_started;
public:
	double get_DEFAULT_CONSUMPTION_PER_SECOND()const
	{
		return DEFAULT_CONSUMPTION_PER_SECOND;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	void set_consumption_per_second(int speed)
	{
		if (speed == 0)consumption_per_second = DEFAULT_CONSUMPTION_PER_SECOND;
		else if (speed < 60)consumption_per_second = DEFAULT_CONSUMPTION_PER_SECOND  * 20 / 3;
		else if (speed < 100)consumption_per_second = DEFAULT_CONSUMPTION_PER_SECOND * 14 / 3;
		else if (speed < 140)consumption_per_second = DEFAULT_CONSUMPTION_PER_SECOND  * 20 / 3;
		else if (speed < 200)consumption_per_second = DEFAULT_CONSUMPTION_PER_SECOND  * 25 / 3;
		else if (speed < 250)consumption_per_second = DEFAULT_CONSUMPTION_PER_SECOND  * 10;
	}
	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()const
	{
		return is_started;
	}

	Engine(double consumption)
		:DEFAULT_CONSUMPTION
		(
			consumption < MIN_ENGINE_CONSUMPTION ? MIN_ENGINE_CONSUMPTION :
			consumption > MAX_ENGINE_CONSUMPTION ? MAX_ENGINE_CONSUMPTION :
			consumption
		),
		DEFAULT_CONSUMPTION_PER_SECOND(DEFAULT_CONSUMPTION*3e-5)
	{
		//this->DEFAULT_CONSUMPTION_PER_SECOND = DEFAULT_CONSUMPTION * 3e-5;
		set_consumption_per_second(0);
		is_started = false;
		cout << "Engine is ready:" << this << endl;
	}
	~Engine()
	{
		cout << "Engine is over:\t" << this << endl;
	}

	void info()const
	{
		cout << "Consumption:\t" << DEFAULT_CONSUMPTION << " liters per 100km.\n";
		cout << "Consumption:\t" << consumption_per_second << " liters per 1 second.\n";
	}
};

#define MAX_SPEED_LOWER_LEVEL	30
#define MAX_SPEED_UPPER_LEVEL  400
class Car
{
	Engine engine;
	Tank tank;

	int speed;
	const int MAX_SPEED;
	int accelleration;

	bool driver_inside;
	struct Threads
	{
		std::thread panel_thread;
		std::thread engine_idle_thread;
		std::thread free_wheeling_thread;
	}threads;
public:
	int get_speed()const
	{
		return speed;
	}
	int get_MAX_SPEED()const
	{
		return MAX_SPEED;
	}
	Car(double consumption, int volume, int max_speed, int acceleration = 10) :engine(consumption), tank(volume),
		MAX_SPEED
		(
			max_speed < MAX_SPEED_LOWER_LEVEL ? MAX_SPEED_LOWER_LEVEL :
			max_speed > MAX_SPEED_UPPER_LEVEL ? MAX_SPEED_UPPER_LEVEL :
			max_speed
		)
	{
		driver_inside = false;
		this->accelleration = acceleration;
		this->speed = 0;
		cout << "Your car is ready to go " << this << endl;
	}
	~Car()
	{
		cout << "Car is over\t" << this << endl;
	}
	void get_in()
	{
		driver_inside = true;
		threads.panel_thread = std::thread(&Car::panel, this);
	}
	void get_out()
	{
		driver_inside = false;
		if (threads.panel_thread.joinable())threads.panel_thread.join();
		system("CLS");
		cout << "Outside" << endl;
	}
	void start()
	{
		if (driver_inside && tank.get_fuel_level())
		{
			engine.start();
			threads.engine_idle_thread = std::thread(&Car::engine_idle, this);
		}
	}
	void stop()
	{
		engine.stop();
		if (threads.engine_idle_thread.joinable())threads.engine_idle_thread.join();
	}

	void control()
	{
		char key = 0;
		do
		{
			key = 0;
			if (_kbhit())	//‘ункци€ _kbhit() 
				key = _getch();
			switch (key)
			{
			case Enter:
				if (driver_inside && speed == 0)get_out();
				else if (!driver_inside && speed == 0)get_in();
				break;
			case 'F':case 'f':
			{
				if (driver_inside)
				{
					cout << "ƒл€ начала нужно выйти из машины" << endl;
					break;
				}
				double fuel;
				cout << "¬ведите объем топлива: "; cin >> fuel;
				tank.fill(fuel);
				break;
			}
			case 'I':case 'i':	//Ignition - зажигание
				if (engine.started())stop();
				else start();
				break;
			case 'W':case 'w':
				accellerate();
				//std::this_thread::sleep_for(1s);
				break;
			case 'S':case 's':
				slow_down();
				//std::this_thread::sleep_for(1s);
				break;
			case Escape:
				speed = 0;
				stop();
				get_out();
			}
			if (tank.get_fuel_level() == 0)stop();
			if (speed <= 0)engine.set_consumption_per_second(speed = 0);
			if (speed == 0 && threads.free_wheeling_thread.joinable())threads.free_wheeling_thread.join();
		} while (key != Escape);
	}
	void engine_idle()
	{
		while (engine.started() && tank.give_fuel(engine.get_consumption_per_second()))
			std::this_thread::sleep_for(1s);
	}
	void free_wheeling()
	{
		while (--speed > 0)
		{
			std::this_thread::sleep_for(1s);
			engine.set_consumption_per_second(speed);
		}
	}
	void accellerate()
	{
		if (engine.started() && driver_inside)
		{
			speed += accelleration;
			if (speed > MAX_SPEED)speed = MAX_SPEED;
			if (!threads.free_wheeling_thread.joinable())threads.free_wheeling_thread = std::thread(&Car::free_wheeling, this);
			std::this_thread::sleep_for(1s);
		}
	}
	void slow_down()
	{
		if (driver_inside)
		{
			speed -= accelleration;
			if (speed < 0)speed = 0;
			//if (threads.free_wheeling_thread.joinable())threads.free_wheeling_thread.join();
			std::this_thread::sleep_for(1s);
		}
	}
	void panel()const
	{
		while (driver_inside)
		{
			system("CLS");
			for (int i = 0; i < speed / 3; i++)
			{
				cout << "|";
			}
			cout << endl;
			cout << "Fuel level:\t" << tank.get_fuel_level() << " liters\t";
			if (tank.get_fuel_level() < 5)
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 0xCE);
				cout << " LOW FUEL ";
				SetConsoleTextAttribute(hConsole, 0x07);
			}
			cout << endl;
			cout << "Engine is " << (engine.started() ? "started" : "stopped") << endl;
			cout << "Speed:\t" << speed << " km/h\n";
			cout << "Consumption per second:\t" << engine.get_consumption_per_second() << " liters\n";
			std::this_thread::sleep_for(100ms);
		}
	}
};

//#define TANK_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef TANK_CHECK
	Tank tank(150);
	do
	{
		int fuel;
		cout << "¬ведите уровень топлива: "; cin >> fuel;
		tank.fill(fuel);
		tank.info();
	} while (true);
#endif // TANK_CHECK

	//Engine engine(10);
	//engine.info();

	Car bmw(25, 100, 300);
	bmw.control();
}