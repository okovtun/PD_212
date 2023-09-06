#include<iostream>
using namespace std;

void hello()
{
	cout << "Hello" << endl;
}
int sum(int a, int b)
{
	return a + b;
}

void main()
{
	void (*p_hello)() = hello;	//void* - void pointer (указатель на 'void', может хранить адрес абсолютно любого типа)
	//При разыменовании void-pointer-а обязатель нужно преобразовывать его в целевой тип.
	p_hello();

	//cout << sum(2, 3) << endl;
	cout << sum << endl;
	int(*p_sum)(int, int) = sum;
	cout << p_sum(2, 3) << endl;
}