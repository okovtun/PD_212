#pragma once
#include<iostream>

#define delim "\n----------------------------------------------------------------\n"

template<typename T>class List
{
	//Element
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;

	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List<T>;
	} *Head, * Tail;
	unsigned int size;
	//Iterators
	class constBaseIterator
	{
	protected:
		Element* Temp;
	public:
		constBaseIterator(Element* Temp);
		~constBaseIterator();
		bool operator==(const constBaseIterator& other)const;
		bool operator!=(const constBaseIterator& other)const;
		const T& operator*()const;
	};
public:

	//Iterators
	class constIterator :public constBaseIterator
	{
	public:
		constIterator(Element* Temp = nullptr);
		~constIterator();
		constIterator& operator++();
		constIterator operator++(int);
		constIterator& operator--();
		constIterator operator--(int);
	};
	class constReversIterator : public constBaseIterator
	{
	public:
		constReversIterator(Element* Temp = nullptr);
		~constReversIterator();
		constReversIterator& operator++();
		constReversIterator operator++(int);
		constReversIterator& operator--();
		constReversIterator operator--(int);
	};
	class Iterator :public constIterator
	{
	public:
		Iterator(Element* Temp = nullptr);
		T& operator*();
	};
	class ReversIterator :public constReversIterator
	{
	public:
		ReversIterator(Element* Temp = nullptr);
		T& operator*();
	};
	constIterator cbegin()const;
	constIterator cend()const;
	constReversIterator rcbegin()const;
	constReversIterator rcend()const;
	Iterator begin();
	Iterator end();
	ReversIterator rbegin();
	ReversIterator rend();

	//Constructors List
	List();
	List(const std::initializer_list<T>& il);
	List(const List<T>& other);
	~List();

	//Operators
	List<T>& operator=(const List<T>& other);

	//Adding elements
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int index);

	//Removing elements
	void pop_front();
	void pop_back();
	void erase(int index);

	//Methods
	void print()const;
	void revprint()const;
};

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right);