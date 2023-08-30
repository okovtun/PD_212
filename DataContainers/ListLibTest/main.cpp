#include"include\List2.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	List<int> list = { 3, 5, 8, 13, 21 };
	for (int i : list)cout << i << "\t"; cout << endl;
}