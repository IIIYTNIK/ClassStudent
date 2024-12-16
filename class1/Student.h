#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Перечисление для обозначения курса обучения
enum class Curs { first = 1, second, third, fourth, fifth, sixth };


// Класс, представляющий студента
class Students {
private:
	string name;       // Имя студента
	int id_number;     // Номер студенческого билета
	int age;          // Возраст студента
	Curs grade;       // Курс обучения

public:
	//конструктор по умолчанию
	Students();

	//конструктор с параметрами
	Students(const string& name, int id_number, int age, Curs grade);

	// Сеттеры для установки значений полей класса
	///сеттер устанвки имени. При пустом значении имя будет "Noname"
	void set_name(const string& a);
	///сеттер установки номера студенческого. При отрицательном значении, устанавливает значение 1
	void set_id_number(int a);
	///сеттер для установки возвраста. При отрицательном значении, устанавливает значение 1
	void set_age(int a);
	///сеттер для установки курса. проверка не требуется из-за нестандартного типа данных
	void set_grade(Curs a);

	// Геттеры для получения значений полей класса
	/// Возвращает имя студента в типе string
	string get_name() const { return name; }
	/// Возвращает номер студенческого билета в типе int
	int get_id_number() const { return id_number; }
	// Возвращает возраст студента в типе int
	int get_age() const { return age; }
	// Возвращает курс обучения в типе int(преобразование enum в int)
	int get_grade() const { return static_cast<int>(grade); }
	///метод возвращает информацию о всех полях класса в строком типе
	string to_string() const;
};

///функция для записи в файл
void to_file(Students a, string filename);
/// Функция для чтения информации о студенте из файла и заполнения объекта
void out_file(Students &a, string filename);