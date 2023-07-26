#include<iostream>
#include<fstream>	//0) Подключаем файловую библиотеку
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

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

	std::ofstream fout_wol("201 ready.txt");
	std::ofstream fout_dhcpd("201dhcpd.txt");
	std::ifstream fin("201 RAW.txt");
	if (fin.is_open())
	{
		const int MAC_SIZE = 18;
		const int IP_SIZE = 16;
		char sz_mac_buffer[MAC_SIZE]{};
		char sz_ip_buffer[IP_SIZE]{};
		//WOL:
		while (!fin.eof())
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
			fout_wol << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
		}
		//DHCP:
		cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;
		for (int i = 1; !fin.eof(); i++)
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			if (strlen(sz_ip_buffer) == 0)continue;
			for (int i = 0; sz_mac_buffer[i]; i++)
				if (sz_mac_buffer[i] == '-')
					sz_mac_buffer[i] = ':';

			cout << "host-" << i << endl;
			cout << "{\n";
			cout << "\thardware ethernet:\t" << sz_mac_buffer << ";\n";
			cout << "\tfixed-address:\t\t" << sz_ip_buffer << ";\n";
			cout << "}\n";

			fout_dhcpd << "host-" << i << endl;
			fout_dhcpd << "{\n";
			fout_dhcpd << "\thardware ethernet:\t" << sz_mac_buffer << ";\n";
			fout_dhcpd << "\tfixed-address:\t\t" << sz_ip_buffer << ";\n";
			fout_dhcpd << "}\n";


		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;;
	}
	fout_wol.close();
	fout_dhcpd.close();
	system("start notepad 201 ready.txt");
	system("start notepad 201dhcpd.txt");
}