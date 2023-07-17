https://github.com/okovtun/PD_212
https://www.youtube.com/watch?v=9JSiZ6RT56o&list=PLeqyOOqxeiIPzkSeyZpJxffGotPeC7krw

TODO:
1. Реализовать класс Teacher;
2. Реализовать класс Graduate  - Дипломник;

DONE:
1. Разделить класс 'Fraction' на файлы;
2. От ветки 'StringSeparation' создать ветку 'StringLib', в проекте 'String' собрать *.lib-файл,
   и проветрить его на другом проекте;

DONE:
1. *Разделить класс 'String' на файлы (будем делать на следующем занятии);
2. Применить инициализацию в заголовке, и деллегирование в классе Matrix;
3. Реализовать класс 'Binary', описывающий двоичное число;

DONE:
В Solution 'IntroductionToOOP' добавить проект 'Matrix', и в этом проекте реализовать класс Matrix,
описывающий матрицу.
Необходимо реализовать следующие операции над матрицами: +, -, *, /;

DONE:
Добавить в класс 'String' Move-методы: https://legacy.cplusplus.com/doc/tutorial/classes2/

DONE:
В Solution 'IntroductionToOOP' добавить проект 'String', и в нем реализовать класс 'String',
описывающий строку.
Проверочный код:
	String str1;	//пустая строка, размером 80 Byte
	String str2 = 5;//пустая строка, размером 5 Byte

	String str3 = "Hello";
	cout << str3 << endl;

	String str4 = "World";
	cout << str4 << endl;

	String str5 = str3 + str4;
	cout << str5 << endl;

TODO:
1. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
2. В класс 'Fraction' добавить методы:	DONE
	??? to_proper();	//преобразует дробь в правильную
	??? to_improper();	//преборазует дробь в неправильную
	??? reduce();		//сокращает дробь		https://www.webmath.ru/poleznoe/formules_12_7.php	DONE
3. Перегрузить и проветрить арифметические операторы: +, -;
4. Перегрузить и проветрить составные присваивания: +=, -=, /=;
5. Перегрузить и проветрить операторы сравнения: ==, !=, >, <, >=, <=;	DONE
6.	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
7.	Fraction A = 2.75;	//https://legacy.cplusplus.com/doc/tutorial/typecasting/
	cout << A << endl;

DONE:
1. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
2. Перегрузить оставшиеся операторы для класса 'Point';
3. В Solution "IntroductionToOOP" добавить проект "Fraction", 
   и в нем реализовать класс "Fraction", описывающий простую дробь.
   В классе должны быть все необходимые методы и операторы;

DONE:
1. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
2. В проекте 'IntroductinToOOP' реализовать метод ??? distance(???),	DONE
   который находит расстояние до указанной точки;
3. В проекте 'IntroductinToOOP' реализовать функцию ??? distance(???),	DONE
   которая находит расстояние между двумя точками;