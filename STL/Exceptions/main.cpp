#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	try
	{
		throw 1;
	}
	catch (int e)
	{
		std::cerr << "Error #" << e << endl;
	}
	catch (double e)
	{
		std::cerr << "Error #" << e << endl;
	}

	try
	{
		throw std::exception("C++ Exception");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
}