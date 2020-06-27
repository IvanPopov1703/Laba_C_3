#pragma once
#include <string>

using namespace std;

class Date
{
public:
	//Конструкторы
	Date(int d = 1, int m = 1, int y = 1970);
	Date(const Date& date);

	//Геттеры для полей
	int get_day() const;
	int get_month() const;
	int get_year() const;

	//Сеттеры для полей
	void set_day(const int& day);
	void set_month(const int& month);
	void set_year(const int& year);
	void set_date(const int& day, const int& month, const int& year);

	//Перегрузка операторов ввода/вывода
	friend ostream& operator<<(ostream& out, const Date& date);
	friend istream& operator >>(istream& in, Date& date);

	//Перегрузка операторов равно/не равно
	//friend static bool operator==(const Date& d1, const Date& d2);
	friend static bool operator== (const Date& d1, const Date& d2)
	{
		return ((d1.day == d2.day) && (d1.month == d2.month) && (d1.year == d2.year));
	}
	friend static bool operator!=(const Date& d1, const Date& d2);

	//Перегрузка операторов больше/меньше
	friend bool operator< (const Date& d1, const Date& d2);
	friend static bool operator> (const Date& d1, const Date& d2);

	//Перегрузка операторов больше или равно/меньше или равно
	friend static bool operator<= (const Date& d1, const Date& d2);
	friend static bool operator>= (const Date& d1, const Date& d2);

	//Добавление дней
	void add_days(int days);

	//Проверка валидности даты
	static bool is_valid_date(int day, int month, int year);

	static int days_in_year(int year);

	static bool is_leap_year(int year);

	static int days_in_month(int year, int month);

private:
	int day;
	int month;
	int year;
};

