//ForwardList
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

class ForwardList;
ForwardList operator+(const ForwardList& left, const ForwardList& right);

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
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
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
	ForwardList(const ForwardList& other) :ForwardList()
	{
		cout << "LCopyConstructor:\t" << this << endl;
		//Deep copy:
		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);*/
		*this = other;
	}
	ForwardList(ForwardList&& other)//ForwardList&& - r-value reference
	{

	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//					Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		cout << "LCopyAssignment:\t" << this << endl;
		//Deep copy:
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}

	//					Adding elements:
	void push_front(int Data)
	{
		Head = new Element(Data, Head);
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
	}
	void insert(int Data, int Index)
	{
		if (Index == 0) return push_front(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) 
		New->pNext = Temp->pNext;
		//3)
		Temp->pNext = New;
	}

	//					Delete elements:
	void pop_front()
	{
		Element* erased = Head;
		Head = Head->pNext;
		delete erased;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = 0;
	}
	void erase(int Index)
	{
		if (Index == 0)return pop_front();
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		Element* erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete erased;
	}

	//					Methods:
	void print()const
	{
		/*Element* Temp = Head;	//Temp - это итератор
		//Итератор - это указатель, при помощи которого можно получить доступ к элементам структуры данных.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}*/
		cout << "Head: " << Head << endl;
		//		Counter		;	Condition;	Expression	 
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

	}
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (Element* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;
}

//#define BASE_CHECK
//#define OPERATOR_PLUS_CHECK
//#define RANGE_BASED_FOR_ARRAY
#define RANGE_BASED_FOR_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	//list.push_back(123);
	list = list;
	list.print();

	/*int value;
	int index;
	cout << "Введите индекс элемента: "; cin >> index;
	cout << "Введите значение элемента: "; cin >> value;
	list.insert(value, index);
	list.print();

	cout << "Введите индекс элемента: "; cin >> index;
	list.erase(index);
	list.print();*/

	//ForwardList list2 = list;	//Copy constructor
	ForwardList list2;
	list2 = list;		//Copy assignment
	list2.print();
#endif // BASE_CHECK

#ifdef OPERATOR_PLUS_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();

	ForwardList list3 = list1 + list2;
	list3.print();

#endif // OPERATOR_PLUS_CHECK

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	//https://legacy.cplusplus.com/doc/tutorial/control/#:~:text=equal%20to%2050.-,Range%2Dbased%20for%20loop,-The%20for%2Dloop
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_ARRAY

#ifdef RANGE_BASED_FOR_LIST
	ForwardList list = { 3, 5, 8, 13, 21 };
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_LIST

}