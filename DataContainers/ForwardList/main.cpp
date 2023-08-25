//ForwardList
#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------\n"

template<typename T>class ForwardList;
template<typename T>class Iterator;
template<typename T>ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);

template<typename T>class Element
{
	T Data;		//значение элемента
	Element<T>* pNext;	//адрес следующего элемента
public:
	Element(T Data, Element<T>* pNext = nullptr) :Data(Data), pNext(pNext)
	{
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Element()
	{
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
	}
	friend class ForwardList<T>;
	friend class Iterator<T>;
	template<typename T>friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};
template<typename T>class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr) :Temp(Temp)
	{
#ifdef DEBUG
		cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Iterator()
	{
#ifdef DEBUG
		cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG
	}

	Iterator<T>& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	bool operator==(const Iterator<T>& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator<T>& other)const
	{
		return this->Temp != other.Temp;
	}

	T operator*()
	{
		return Temp->Data;
	}
};
template<typename T>class ForwardList
{
	Element<T>* Head;	//Голова списка - содержит адрес начального элемента списка
public:
	Iterator<T> begin()
	{
		return Head;
	}
	Iterator<T> end()
	{
		return nullptr;
	}
	ForwardList()
	{
		Head = nullptr;	//Если список пуст, то его голова указывает на 0
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const std::initializer_list<T>& il):ForwardList()
	{
		//begin() - возвращает итератор на начало контейнера
		//end()   - возвращает итератор на конец контейнера
		cout << typeid(il.begin()).name() << endl;
		//https://legacy.cplusplus.com/doc/tutorial/pointers/#:~:text=legibility%20to%20expressions.-,Pointers%20and%20const,-Pointers%20can%20be
		cout << typeid(int*).name() << endl;	//int*  - указатель на 'int'
		cout << typeid(const int*).name() << endl;//const int* - указатель на константу
		//int* const - консантный указатель
		//const int* const - констаный указатель на константу

		for (T const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList<T>& other) :ForwardList()
	{
		cout << "LCopyConstructor:\t" << this << endl;
		//Deep copy:
		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);*/
		*this = other;
	}
	ForwardList(ForwardList<T>&& other):ForwardList()//ForwardList&& - r-value reference
	{
		/*this->Head = other.Head;
		other.Head = nullptr;*/
		*this = std::move(other);	//Функция move() принудительно вызывает MoveAssignment для объекта, если он есть.
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//					Operators:
	ForwardList<T>& operator=(const ForwardList<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		cout << "LCopyAssignment:\t" << this << endl;
		//Deep copy:
		for (Element<T>* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}
	ForwardList<T>& operator=(ForwardList<T>&& other)
	{
		while (Head)pop_front();
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveAssignment:\t" << this << endl;
		return *this;
	}

	//					Adding elements:
	void push_front(T Data)
	{
		Head = new Element<T>(Data, Head);
	}
	void push_back(T Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element<T>* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		Temp->pNext = new Element<T>(Data);
	}
	void insert(T Data, int Index)
	{
		if (Index == 0) return push_front(Data);
		Element<T>* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		//1) Создаем новый элемент:
		Element<T>* New = new Element<T>(Data);
		//2) 
		New->pNext = Temp->pNext;
		//3)
		Temp->pNext = New;
	}

	//					Delete elements:
	void pop_front()
	{
		Element<T>* erased = Head;
		Head = Head->pNext;
		delete erased;
	}
	void pop_back()
	{
		Element<T>* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = 0;
	}
	void erase(int Index)
	{
		if (Index == 0)return pop_front();
		Element<T>* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		Element<T>* erased = Temp->pNext;
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
		for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

	}
	template<typename T>friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};

template<typename T>ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> cat = left;
	for (Element<T>* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;
}

//#define BASE_CHECK
//#define OPERATOR_PLUS_CHECK
//#define RANGE_BASED_FOR_ARRAY
//#define RANGE_BASED_FOR_LIST
#define MOVE_SEMANTIC_CHECK

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
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_LIST

#ifdef MOVE_SEMANTIC_CHECK
	ForwardList<int> list1 = { 3, 5, 8, 13, 21 };
	for (int i : list1)cout << i << tab; cout << endl;

	ForwardList<int> list2 = { 34, 55, 89 };
	for (int i : list2)cout << i << tab; cout << endl;

	cout << delimiter << endl;
	//ForwardList list3 = list1 + list2;	//Move constructor
	ForwardList<int> list3;
	list3 = list1 + list2;
	cout << delimiter << endl;
	for (int i : list3)cout << i << tab; cout << endl;

	ForwardList<double> d_list_1 = { 2.7, 3.14, 5.1 };
	ForwardList<double> d_list_2 = { 7.3, 8.2, 4.4, 9.5 };
	ForwardList<double> d_list_3 = d_list_1 + d_list_2;
	for (double i : d_list_1)cout << i << tab; cout << endl;
	for (double i : d_list_2)cout << i << tab; cout << endl;
	for (double i : d_list_3)cout << i << tab; cout << endl;

#endif // MOVE_SEMANTIC_CHECK

}