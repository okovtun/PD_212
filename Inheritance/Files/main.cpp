#include<iostream>
#include<fstream>	//0) Подключаем файловую библиотеку
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	cout << "Hello Files" << endl;
	//1) Создаем поток:
	std::ofstream fout;
	//2) Открываем поток:
	fout.open("File.txt", std::ios_base::app);
	//3) Пишем в поток:
	fout << "Hello Files" << endl;
	fout << "Ну привет" << endl;
	//4) Закрываем поток:
	fout.close();

	system("start notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	//1) Создаем поток:
	std::ifstream fin;
	//2) Открываем поток:
	fin.open("File.txt");
	//3) Проверяем, открылся ли поток:
	if (fin.is_open())
	{
		//TODO: read file
		while (!fin.eof())
		{
			const int SIZE = 10240;
			char sz_buffer[SIZE] = {};
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		//Закрываем поток:
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
#endif // READ_FROM_FILE

}