#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

enum class Curs { first = 1, second, third, fourth, fifth, sixth };


//класс студента
class Students {
private:
	string name;
	int id_number;
	int age;
	Curs grade;

public:
	//конструктор по умолчанию
	Students();

	//конструктор с параметрами
	Students(const string& name, int id_number, int age, Curs grade);

	void set_name(const string& a);
	void set_id_number(int a);
	void set_age(int a);
	void set_grade(Curs a);

	//методы для получения значения поля
	string get_name() const { return name; }///сеттер устанвки имени. При пустом значении имя будет "Noname"
	int get_id_number() const { return id_number; }///сеттер установки номера студенческого. При отрицательном значении, устанавливает значение 1
	int get_age() const { return age; }///сеттер для установки возвраста. При отрицательном значении, устанавливает значение 1
	int get_grade() const { return static_cast<int>(grade); }///сеттер для установки курса. проверка не требуется из-за нестандартного типа данных
	///метод возвращает информацию о всех полях класса в строком типе
	string to_string() const;
};

///функция для записи в файл
void to_file(Students a, string filename);
//функция для записи объекта из файла
void out_file(Students &a, string filename);