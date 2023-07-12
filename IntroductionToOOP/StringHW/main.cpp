#include<iostream>
#include<Windows.h>

class Strings
{
	int size;
	char* str;
public:
	//�������
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//������������
	explicit Strings(int size = 80) :size(size), str(new char[size] {}) //������������� ����������� ��� ��������� ������
	{
		//this->size = size;
		//char* str = new char[size] {};
		std::cout << "�����������\t" << this << std::endl;
	}
	Strings(const char* str) :
		size(strlen(str) + 1),
		str(new char[size] {})//����������� ��� ����� ������
	{
		//this->size = strlen(str)+1;
		//this->str = new char[size] {};
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		std::cout << "�����������\t" << this << std::endl;
	}
	Strings(const Strings& str) //����������� �����������
	{
		this->size = strlen(str.str);
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		std::cout << "�����������\t" << this << std::endl;
	}
	Strings(Strings&& str)//����������� ��������
	{
		this->str = str.str;
		this->size = str.size;
		str.str = nullptr;
		str.size = 0;
		std::cout << "�����������\t" << this << std::endl;
	}
	//���������� ���������� � ������
	Strings& operator=(const Strings& str)
	{
		if (this == &str) return *this;
		delete[] this->str;
		this->size = strlen(str.str);
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str.str[i];
		std::cout << "������������\t" << this << std::endl;
		return *this;
	}
	Strings& operator=(Strings&& str)
	{
		if (this == &str) return *this;
		delete[] this->str;
		this->str = str.str;
		size = str.size;
		str.str = nullptr;
		str.size = 0;
		std::cout << "������������\t" << this << std::endl;
		return *this;
	}

	char& operator[](int i)
	{
		return str[i];
	}
	char operator[](int i)const
	{
		return str[i];
	}
	//����������
	~Strings()
	{
		delete[] str;
		std::cout << "����������\t" << this << std::endl;
	}
};

//���������� ����������
Strings operator+(const Strings& left, const Strings& right)
{
	Strings concate(left.get_size() + right.get_size() - 1);
	int i = 0;
	for (; i < left.get_size(); i++) concate[i] = left[i];
	i--;
	for (int j = 0; j < right.get_size(); j++, i++) concate[i] = right[j];
	return concate;
}
Strings operator-(const Strings& left, const Strings& right)
{
	const int n = 256;
	char buff[n] = {};
	int k = 0;
	for (int i = 0; left[i]; i++)
	{
		for (int j = 0; right[j]; j++)
		{
			if (left[i] != right[j])
			{
				buff[k] = left[i];
				continue;
			}
			else
			{
				buff[k] = 0;
				k--;
				break;
			}
		}
		k++;
	}
	Strings diff(k + 1);
	for (int i = 0; buff[i]; i++)
	{
		diff[i] = buff[i];
	}
	return diff;
}
std::ostream& operator<<(std::ostream& os, const Strings& str)
{
	return os << str.get_str();
}
std::istream& operator>>(std::istream& is, Strings& str)
{
	return is.getline(str.get_str(), str.get_size());
}


void main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	//Strings str1;
	//Strings str2 = (Strings)5;
	Strings str3 = "Hello";
	std::cout << "������ ������: " << str3 << std::endl;
	Strings str4 = "World";
	std::cout << "������ ������: " << str4 << std::endl;
	Strings str5 = str3 + str4;
	std::cout << "������������ �����: " << str5 << std::endl;
	//std::cout << "������� ������: " << std::endl;
	//Strings str6;
	//std::cin >> str6;
	//std::cout << "�� ����� ������: " << str6;
	//Strings str6 = str3 - str4;
	//std::cout << "��������� �������� �����: " << str6 << std::endl;
}
