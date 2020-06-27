#include "pch.h"
#include "Date.h"
#include <string>

using namespace std;

Date::Date(int d, int m, int y)
{
	set_date(d, m, y);
}

Date::Date(const Date& date)
{
	set_date(date.day, date.month, date.year);
}

//Геттеры для полей
int Date::get_day() const { return day; }
int Date::get_month() const { return month; }
int Date::get_year() const { return year; }

//Сеттеры для полей
void Date::set_day(const int& day)
{
	this->day = day;
	if (this->day > days_in_month(year, month))
	{
		this->day -= days_in_month(year, month);
		set_month(++month);
	}
}

void Date::set_month(const int& month)
{
	this->month = month;
	if (this->month > 12)
	{
		year++;
		this->month %= 12;
	}
}

void Date::set_year(const int& year)
{
	this->year = year;
}

void Date::set_date(const int& day, const int& month, const int& year)
{
	if (is_valid_date(day, month, year))
	{
		set_year(year);
		set_month(month);
		set_day(day);
	}
}

//Получение даты из строки
int get_number_from_stringdate(string& str)
{
	int position_point = str.find('.');
	if (position_point != -1)
	{
		string tmp_substr = str.substr(0, position_point);
		str.erase(0, position_point + 1);
		return atoi(tmp_substr.c_str());
	}
	return 0;
}

//Добавление дней
void Date::add_days(int days)
{
	while (days >= days_in_year(year))
	{
		days -= days_in_year(year);
		year++;
	}
	while (days >= days_in_month(year, month))
	{
		days -= days_in_month(year, month);
		set_month(++month);
	}
	if (days > 0)
	{
		set_day(this->day + days);
	}
}

//Проверка валидности даты
bool Date::is_valid_date(int day, int month, int year)
{
	if ((day < 1 || day>31) || (month < 1 || month>12))
	{
		return false;
	}
	return true;
}

int Date::days_in_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400)
	{
		return 366;
	}
	return 365;
}

bool Date::is_leap_year(int year)
{
	return days_in_year(year) == 366;
}

int Date::days_in_month(int year, int month)
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (is_leap_year(year))
	{
		days[1] = 29;
	}
	return days[month - 1];
}

//Перегрузка оператора вывода
ostream& operator<<(ostream& out, const Date& date)
{
	out << date.day << '.'
		<< date.month << '.'
		<< date.year << endl;
	return out;
}

//Перегрузка оператора ввода
istream& operator>>(istream& in, Date& date)
{
	string s;
	int day, month, year;
	string tmp_date;
	getline(in, tmp_date);
	day = get_number_from_stringdate(tmp_date);
	month = get_number_from_stringdate(tmp_date);
	year = atoi(tmp_date.c_str());
	date.set_date(day, month, year);
	return in;
}

//Перегрузка оператора "не равно"
static bool operator!=(const Date& d1, const Date& d2)
{
	return (!(d1 == d2));
}

//Перегрузка оператора "меньше"
bool operator<(const Date& d1, const Date& d2)
{
	if (d1.year < d2.year)
		return true;
	if (d1.year > d2.year)
		return false;
	if (d1.month < d2.month)
		return true;
	if (d1.month > d2.month)
		return false;
	return d1.day < d2.day;
}

//Перегрузка оператора "больше"
static bool operator>(const Date& d1, const Date& d2)
{
	return (!(d1 < d2) && !(d1 == d2));
}

//Перегрузка операторa меньше или равно
static bool operator<=(const Date& d1, const Date& d2)
{
	return ((d1 < d2) || (d1 == d2));
}

//Перегрузка операторa больше или равно
static bool operator>=(const Date& d1, const Date& d2)
{
	return ((d1 > d2) || (d1 == d2));
}