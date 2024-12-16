#include <iostream>
#include "Student.h"
using namespace std;


/// Конструктор по умолчанию. Инициализирует поля класса значениями по умолчанию.
Students::Students() {
	name = "Noname"; // Устанавливаем имя по умолчанию
	id_number = 1;    // Устанавливаем номер студенческого билета по умолчанию
	age = 1;         // Устанавливаем возраст по умолчанию
	grade = Curs::first; // Устанавливаем курс по умолчанию
}

/// Конструктор с параметрами. Инициализирует поля класса значениями, переданными в качестве аргументов.
Students::Students(const string& name, int id_number, int age, Curs grade) {
	// Используем сеттеры для установки значений, чтобы обеспечить валидацию данных.
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

/// Функция для записи информации о студенте в файл.
void to_file(Students a, string filename) {
	ofstream out; // Создаем объект выходного потока для записи в файл.
	out.open(filename); // Открываем файл для записи.
	if (out.is_open()) { // Проверяем, успешно ли открыт файл.
		// Записываем данные студента в файл, разделяя поля пробелами.
		out << a.get_name() << " " << a.get_id_number() << " " << a.get_age() << " " << a.get_grade();
	}
	out.close(); // Закрываем файл.
}


///Функция для чтения информации о студенте из файла и заполнения объекта.
void out_file(Students &a, string filename) {
	ifstream in(filename); // Создаем объект входного потока для чтения из файла.
	if (in.is_open()) { // Проверяем, успешно ли открыт файл.
		string name, id_str, age_str, grade_str; // Создаем временные переменные для хранения данных из файла.
		in >> name >> id_str >> age_str >> grade_str; // Считываем данные из файла в временные переменные.
		// Устанавливаем значения полей объекта студента, используя сеттеры.
		a.set_name(name);
		a.set_id_number(stoi(id_str)); // Преобразуем строку в целое число.
		a.set_age(stoi(age_str));     // Преобразуем строку в целое число.
		a.set_grade(static_cast<Curs>(stoi(grade_str))); // Преобразуем строку в целое число, затем в enum Curs.
	}
	in.close(); // Закрываем файл.
}