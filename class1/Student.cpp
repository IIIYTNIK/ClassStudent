#include <iostream>
#include "Student.h"
using namespace std;


//конструктор по умолчанию
Students::Students() {
	name = "Noname";
	id_number = 1;
	age = 1;
	grade = Curs::first;
};

 //конструктор с параметрами
Students::Students(const string &name, int id_number, int age, Curs grade){
	//Установка занчений пол умолчанию
	set_name(name);
	set_id_number(id_number);
	set_age(age);
	set_grade(grade);
}

//методы для установки значения(сеттеры):
///сеттер устанвки имени. При пустом значении имя будет "Noname"
void Students::set_name(const string& a) { //проверка имена на пустое значение
	if (a != "") {
		this->name = a;
	}
	else {
		this->name = "Noname";
	}
 }
///сеттер установки номера студенческого. При отрицательном значении, устанавливает значение 1
void Students::set_id_number(int a) { //проверка, что номер студенческого положителен
	if (a > 0) {
		this->id_number = a;
	}
	else {
		this->id_number = 1;
	}
}
///сеттер для установки возвраста. При отрицательном значении, устанавливает значение 1
void Students::set_age(int a) { //проверка, что возвраст положителен
	if (a > 0) {
		this->age = a;
	}
	else {
		this->age = 1;
	}
}
///сеттер для установки курса. проверка не требуется из-за нестандартного типа данных
void Students::set_grade(Curs a) { this->grade = a; }

///метод возвращает информацию о всех полях класса в строком типе
string Students::to_string() const { return ("Name: " + name + ", ID: " + std::to_string(id_number) + ", Age: " + std::to_string(age) + ", Grade: " + std::to_string(static_cast<int>(grade)) + "\n"); }

///функция для записив файл
void to_file(Students a, string filename) {
	ofstream out;
	out.open(filename);
	if (out.is_open()) // окрываем файл для чтения
	{
		out << a.get_name() << " " << a.get_id_number() << " " << a.get_age() << " " << a.get_grade();
	}
	out.close();
}

//функция для записи объекта из файла
void out_file(Students &a, string filename) {
	string arrs[4];
	ifstream in(filename); // окрываем файл для чтения
	if (in.is_open())
	{
		string name, id_str, age_str, grade_str; //создаём переменные в которые будет производиться запись
		in >> name >> id_str >> age_str >> grade_str; //записываем данные в переменные
		a.set_name(name);
		a.set_id_number(stoi(id_str));
		a.set_age(stoi(age_str));
		a.set_grade(static_cast<Curs>(stoi(grade_str)));
	}
	in.close();
}