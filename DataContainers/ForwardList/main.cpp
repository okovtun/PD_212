//ForwardList
#include<iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data;		//значение элемента
	Element* pNext;	//адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
class ForwardList
{
	Element* Head;	//Голова списка - содержит адрес начального элемента списка
public:
	ForwardList()
	{
		Head = nullptr;	//Если список пуст, то его голова указывает на 0
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//					Adding elements:
	void push_front(int Data)
	{
		Head = new Element(Data, Head);
	}
	void push_back(int Data)
	{
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
	}

	//					Methods:
	void print()const
	{
		Element* Temp = Head;	//Temp - это итератор
		//Итератор - это указатель, при помощи которого можно получить доступ к элементам структуры данных.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.push_back(123);
	list.print();
}