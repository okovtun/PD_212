#include <iostream>
#include <ctime>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "Element constructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "Element destructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;

public:
	Element* getRoot()
	{
		return this->Root;
	}

	Tree() : Root(nullptr)
	{
#ifdef DEBUG
		cout << "Three constructor:\t" << this << endl;
#endif // DEBUG

	}

	Tree(initializer_list<int> il) : Tree()
	{
		for (int i : il) insert(i, Root);
#ifdef DEBUG
		cout << "Tree il constructor:\t" << this << endl;
#endif // DEBUG

	}

	~Tree()
	{
		Clear();
#ifdef DEBUG
		cout << "Tree destructor:\t" << this << endl;
#endif // DEBUG

	}

	void insert(int Data)
	{
		insert(Data, Root);
	}

	int minValue() const
	{
		return minValue(Root);
	}

	int maxValue() const
	{
		return maxValue(Root);
	}

	int Sum() const
	{
		return Sum(Root);
	}

	int Count() const
	{
		return Count(Root);
	}

	double Avg() const
	{
		return Avg(Root);
	}

	void print()const
	{
		print(Root);
		cout << endl;
	}

	void print_tree() const
	{
		int Depth = 0;
		print_tree(Depth, Root);
	}

	void Clear()
	{
		Clear(Root);
		Root = nullptr;
	}

	int Depth() const
	{
		return Depth(Root);
	}

	void Erase(int Data)
	{
		Erase(Data, Root);
	}

	void balance()
	{
		balance(Root);
	}

private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr) this->Root = new Element(Data);
		if (Root == nullptr) return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr) Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

	void Erase(int Data, Element*& Root)
	{
		if (Root == nullptr) return;
		Erase(Data, Root->pLeft);
		Erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Count(Root->pLeft) > Count(Root->pRight))
				{
					Root->Data = maxValue(Root->pLeft);
					Erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					Erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
	}

	int minValue(Element* Root) const
	{
		if (this->Root == nullptr) return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}

	int maxValue(Element* Root) const
	{
		if (this->Root == nullptr) return 0;
		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
	}

	int Sum(Element* Root) const
	{
		if (this->Root == nullptr) return 0;
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}

	int Count(Element* Root) const
	{
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}

	double Avg(Element* Root) const
	{
		return (double)Sum() / Count(Root);
	}

	void print(Element* Root) const
	{
		if (Root == nullptr) return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}

	void print_tree(int Depth, Element* Root) const
	{
		if (Root == nullptr) return;
		print_tree(Depth + 1, Root->pLeft);
		for (int i = 1; i < Depth; i++)
		{
			cout << "\t";
		}
		if (Root != this->Root)cout << "|-------";
		cout << Root->Data << endl;
		print_tree(Depth + 1, Root->pRight);
	}

	void balance(Element*& Root)
	{
		if (Root == nullptr) return;
		if (abs(Count(Root->pLeft) - Count(Root->pRight)) > 1)
		{
			int Data = Root->Data;
			Erase(Root->Data);
			insert(Data);
			balance();
		}
		balance(Root->pLeft);
		balance(Root->pRight);
	}

	void Clear(Element* Root)
	{
		if (Root == nullptr) return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
	}

	int Depth(Element* Root) const
	{
		if (Root == nullptr) return 0;
		int l_depth = Depth(Root->pLeft) + 1;
		int r_depth = Depth(Root->pRight) + 1;
		return l_depth < r_depth ? r_depth : l_depth;
	}

};

class UniqueTree : public Tree
{
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr) this->Root = new Element(Data);
		if (Root == nullptr) return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr) Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
};
template <typename T>
void Measure(const char* message, const Tree& tree, T(Tree::*member_function)() const)
{
	cout << message;
	clock_t start = clock();
	T value = (tree.*member_function)();
	clock_t end = clock();
	cout << value << endl;
	cout << "Completed in:  " << double(end - start) / CLOCKS_PER_SEC << " sec." << endl;
}

//#define BASE_CHECK
//#define OLD_PERFORMANCE_CHECK
#define RANGE_BASED_FOR_TREE_CHECK
//#define DEPTH_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Enter tree size:\n"; cin >> n;

	Tree tree;
	clock_t start1 = clock();
	clock_t start = clock();
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
#ifdef OLD_PERFORMANCE_CHECK
	//Measure("insert", tree, &Tree::insert);
	clock_t end = clock();
	cout << "insert time:\t" << double(end - start) / CLOCKS_PER_SEC << endl;
	//tree.print();

	cout << "Min value in tree:\t" << endl;
	start = clock();
	int min = tree.minValue();
	end = clock();
	cout << min << endl;
	cout << "min time:\t" << double(end - start) / CLOCKS_PER_SEC << endl;
	///////////////////////////////////////
	cout << "Max value in tree:\t";
	start = clock();
	int max = tree.maxValue();
	end = clock();
	cout << max << endl;
	cout << "max time:\t" << double(end - start) / CLOCKS_PER_SEC << endl;
	///////////////////////////////////
	cout << "Sum of tree elements:\t";
	start = clock();
	int sum = tree.Sum();
	end = clock();
	cout << sum << endl;
	cout << "Sum time:\t" << double(end - start) / CLOCKS_PER_SEC << endl;
	///////////////////////////
	cout << "Number of tree elements:\t";
	start = clock();
	int num = tree.Count();
	end = clock();
	cout << num << endl;
	cout << "Count time:\t" << double(end - start) / CLOCKS_PER_SEC << endl;
	//////////////////////////////////////////
	cout << "Arithmetic mean of tree elements:\t";
	start = clock();
	double avg = tree.Avg();
	end = clock();
	cout << avg << endl;
	cout << "Avg time:\t" << double(end - start) / CLOCKS_PER_SEC << endl;
	//////////////////////////////////////////
	cout << "Depth of tree:\t";
	start = clock();
	int depth = tree.Depth();
	end = clock();
	cout << depth << endl;
	cout << "Depth time:\t" << double(end - start) / CLOCKS_PER_SEC << endl;
#endif // OLD_PERFORMANCE_CHECK
	Measure<int>("Min value in tree: ", tree, &Tree::minValue);
	Measure<int>("Max value in tree: ", tree, &Tree::maxValue);
	Measure<int>("Sum of tree elements: ", tree, &Tree::Sum);
	Measure<int>("Number of tree elements: ", tree, &Tree::Count);
	Measure<int>("Avg value of tree elements: ", tree, &Tree::Avg);
	Measure<int>("Depth of tree: ", tree, &Tree::Depth);

	cout << "==================================== Unique Tree ====================================" << endl;

	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	//u_tree.print();
	cout << "Min value in unique tree:\t" << u_tree.minValue() << endl;
	cout << "Max value in unique tree:\t" << u_tree.maxValue() << endl;
	cout << "Sum of unique tree elements:\t" << u_tree.Sum() << endl;
	cout << "Number of unique tree elements:\t" << u_tree.Count() << endl;
	cout << "Arithmetic mean of unique tree elements:\t" << u_tree.Avg() << endl;
	cout << "Depth of tree:\t" << u_tree.Depth() << endl;

#endif // BASE_CHECK

#ifdef RANGE_BASED_FOR_TREE_CHECK
	//Tree tree = { 2000, 1998, 1900, 1800, 1700, 1600, 1500, 1400, 1300, 1200, 1100, 1000, 900, 800 };
	Tree tree = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711 };
	//Tree tree = {10, 20, 5, 6, 3, 15, 2, 4, 1};
	//tree.print();
	tree.print_tree();
	tree.balance();
	cout << "----------------------------" << endl;
	//tree.print();
	tree.print_tree();
#endif // RANGE_BASED_FOR_TREE_CHECK

#ifdef DEPTH_CHECK
	Tree tree = { 50, 25, 75, 16, 32, 64, 90 };
	tree.print();
	cout << "Depth of tree:\t" << tree.Depth() << endl;
#endif // DEPTH_CHECK


}