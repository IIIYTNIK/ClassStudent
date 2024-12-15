#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

enum class Curs { first = 1, second, third, fourth, fifth, sixth };


//����� ��������
class Students {
private:
	string name;
	int id_number;
	int age;
	Curs grade;

public:
	//����������� �� ���������
	Students();

	//����������� � �����������
	Students(const string& name, int id_number, int age, Curs grade);

	void set_name(const string& a);
	void set_id_number(int a);
	void set_age(int a);
	void set_grade(Curs a);

	//������ ��� ��������� �������� ����
	string get_name() const { return name; }///������ �������� �����. ��� ������ �������� ��� ����� "Noname"
	int get_id_number() const { return id_number; }///������ ��������� ������ �������������. ��� ������������� ��������, ������������� �������� 1
	int get_age() const { return age; }///������ ��� ��������� ���������. ��� ������������� ��������, ������������� �������� 1
	int get_grade() const { return static_cast<int>(grade); }///������ ��� ��������� �����. �������� �� ��������� ��-�� �������������� ���� ������
	///����� ���������� ���������� � ���� ����� ������ � ������� ����
	string to_string() const;
};

///������� ��� ������ � ����
void to_file(Students a, string filename);
//������� ��� ������ ������� �� �����
void out_file(Students &a, string filename);