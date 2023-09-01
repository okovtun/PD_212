#include<iostream>
using namespace std;

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

	int Sum(Element* Root)
	{
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	int Count(Element* Root)
	{
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	double Avg()
	{
		return (double)Sum(Root) / Count(Root);
	}

	int minValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
	}
	int maxValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
		/*if (Root->pRight == nullptr)return Root->Data;
		else return maxValue(Root->pRight);*/
	}

	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};

class UniqueTree: public Tree
{
public:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if(Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//caller - вызывающая функция
	//callee - вызываемая функция
	//Stack overflow exception
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	tree.print(tree.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве:  " << tree.minValue(tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue(tree.getRoot()) << endl;
	cout << "Сумма элементов дерева:\t\t" << tree.Sum(tree.getRoot()) << endl;
	cout << "Количество элементов дерева:    " << tree.Count(tree.getRoot()) << endl;
	cout << "Среднее-арифметическое элементов дерева: " << tree.Avg() << endl;


	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100, u_tree.getRoot());
	}
	u_tree.print(u_tree.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве:  " << u_tree.minValue(u_tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << u_tree.maxValue(u_tree.getRoot()) << endl;
	cout << "Сумма элементов дерева:\t\t" << u_tree.Sum(u_tree.getRoot()) << endl;
	cout << "Количество элементов дерева:    " << u_tree.Count(u_tree.getRoot()) << endl;
	cout << "Среднее-арифметическое элементов дерева: " << u_tree.Avg() << endl;
}