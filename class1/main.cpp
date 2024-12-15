//Автор Бородиенко Д.Т.

#include <iostream>
#include "Student.h" //подключение заголовочного файла с классом
#include <string>
#include <cassert> //подключение библиотеки assert
using namespace std;


//проверка конструкторов и методов класса
void testClassStudent() {

	//тест конструктора с параметрами
	Students Student1("John", 523, 19, Curs::first);
	assert(Student1.to_string() == "Name: John, ID: 523, Age: 19, Grade: 1\n");

	//тест геттеров
	assert(Student1.get_name() == "John");
	assert(Student1.get_id_number() == 523);
	assert(Student1.get_age() == 19);
	assert(Student1.get_grade() == 1);

	//тест конструктора по умолчанию
	Students Student2;
	assert(Student2.to_string() == "Name: Noname, ID: 1, Age: 1, Grade: 1\n");

	//тест сеттеров с валидными данными
	Student2.set_name("Oleg");
	assert(Student2.get_name() == "Oleg");
	Student2.set_id_number(132123);
	assert(Student2.get_id_number() == 132123);
	Student2.set_age(23);
	assert(Student2.get_age() == 23);
	Student2.set_grade(Curs::sixth);
	assert(Student2.get_grade() == 6);

	//тест сеттеров с невалидными данными
	Student2.set_name("");
	assert(Student2.get_name() == "Noname");
	Student2.set_id_number(-1);
	assert(Student2.get_id_number() == 1);
	Student2.set_age(-5);
	assert(Student2.get_age() == 1);

	//тест to_file и out_file (требуют работы с файлами)
	Students Student3("Test", 12345, 25, Curs::third);
	to_file(Student3, "test_file.txt");
	Students Student4;
	out_file(Student4, "test_file.txt");
	assert(Student4.get_name() == "Test");
	assert(Student4.get_id_number() == 12345);
	assert(Student4.get_age() == 25);
	assert(Student4.get_grade() == 3);
	remove("test_file.txt");
	}



int main() {

	testClassStudent();

	//создание объекта, вызов конструктора
	Students first("Maria", 14881488, 20, Curs::third);
	first.set_grade(Curs::fifth);
	cout << first.to_string();
	
	//динамическое создание объектов
	Students* second = new Students("John Smit", 228, 17, Curs::first);
	cout << second->to_string();
	delete second;

	//массив из объектов
	const int n = 2;
	Students arr[n];
	for (int i = 0; i < n; i++) {
		arr[i].set_name("John");
		arr[i].set_age(15 + i);
		arr[i].set_id_number(123 + i * 100);
		arr[i].set_grade(Curs::first);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i].to_string();
	}

	//динамический массив из объектов
	Students *arr2 = new Students[n];
	for (int i = 0; i < n; i++) {
		arr2[i].set_name("Maria");
		arr2[i].set_age(15 + i * 2);
		arr2[i].set_id_number(123 + i * 300);
		arr2[i].set_grade(Curs::second);
	}
	for (int i = 0; i < n; i++) {
		cout << arr2[i].to_string();
	}
	delete[]arr2;
	arr2 = nullptr;

	//массив из указателей
	Students** arr3 = new Students*[n];
	for (int i = 0; i < n; i++) {
		arr3[i] = new Students("Alen", 555 + i * 133, 15 + i, Curs::third);
		cout << arr3[i]->to_string();
	}
	for (int i = 0; i < n; i++) {
		delete arr3[i];
	}

	//работа с файлом
	Students b("John", 523, 19, Curs::first);
	to_file(b, "filejob.txt");
	Students c;
	out_file(c, "filejob.txt");
	c.set_name("Me");
	to_file(c, "CStudent.txt");
	
	
	return 0;
}