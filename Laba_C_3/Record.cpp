#include "pch.h"
#include "Record.h"
#include <string>
#include "Address.h"
#include "Date.h"

using namespace std;

//Конструктор без параметров
Record::Record() :
	_fio(""),
	_payment_type(""),
	_amount_of_payment(0),
	_percent_fine(0),
	_number_of_days_of_delay(0)
{
	Address address;
	this->_address = address;
}

//Конструктор с параметрами
Record::Record(string fio, string payment_view, Date date, double amount, double percent_fine, int delay, Address address) :
	_fio(fio),
	_payment_type(payment_view),
	_date_payment(date),
	_amount_of_payment(amount),
	_percent_fine(percent_fine),
	_number_of_days_of_delay(delay),
	_address(address) { }

//Геттеры для полей
string Record::get_fio() const { return _fio; }
string Record::get_payment_type(const int& num) const { return (num == 1 ? CASH_PAYMENT : CASHLESS_PAYMENT); }
Date Record::get_date_payment() const { return _date_payment; }
double Record::get_amount_of_payment() const { return _amount_of_payment; }
double Record::get_percent_fine() const { return _percent_fine; }
int Record::get_number_of_days_of_delay() const { return _number_of_days_of_delay; }
Address& Record::get_address() { return _address; }

//Сеттеры для полей
void Record::set_fio(const string& fio)
{
	this->_fio = fio;
}

void Record::set_payment_type(const int& num)
{
	switch (num)
	{
	case 1: this->_payment_type = CASH_PAYMENT;
		break;
	case 2: this->_payment_type = CASHLESS_PAYMENT;
		break;
	}
}

void Record::set_date_payment(const Date& date)
{
	this->_date_payment = date;
}

void Record::set_amount_of_payment(const double& amount)
{
	this->_amount_of_payment = amount;
}

void Record::set_percent_fine(const double& fine)
{
	this->_percent_fine = fine;
}

void Record::set_number_of_days_of_delay(const double& delay)
{
	this->_number_of_days_of_delay = delay;
}

void Record::set_address(const Address& address)
{
	this->_address = address;
}

//Перегрузка оператора равно
bool operator==(const Record& r1, const Record& r2)
{
	return (r1._fio == r2._fio && r1._payment_type == r2._payment_type &&
		r1._date_payment == r2._date_payment && r1._amount_of_payment == r2._amount_of_payment &&
		r1._percent_fine == r2._percent_fine && r1._number_of_days_of_delay == r2._number_of_days_of_delay &&
		r1._address == r2._address);
}

//Перегрузка оператора "не равно"
bool operator!=(const Record& r1, const Record& r2)
{
	return !(r1 == r2);
}

//Вспомогательная функция для выбора типа оплаты
string help_func_for_select_type_payment(const string& str)
{
	if (str == "1" || str == "Наличные")
	{
		return CASH_PAYMENT;
	}
	if (str == "2" || str == "Безналично")
	{
		return CASHLESS_PAYMENT;
	}
	return NOT_CHOSEN;
}

//Перегрузка оператора ввода
istream& operator>>(istream& in, Record& rec)
{
	string s;
	getline(in, rec._fio);
	getline(in, s); //= help_func_for_select_type_payment(s)
	rec._payment_type = help_func_for_select_type_payment(s);
	in >> rec._date_payment;
	in >> rec._amount_of_payment;
	getline(in, s);
	in >> rec._percent_fine;
	getline(in, s);
	in >> rec._number_of_days_of_delay;
	getline(in, s);
	in >> rec._address;
	return in;
}


//Перегрузка оператора вывода
ostream& operator<<(ostream& out, const Record& rec)
{
	out << rec._fio << endl
		<< rec._payment_type << endl
		<< rec._date_payment
		<< rec._amount_of_payment << endl
		<< rec._percent_fine << endl
		<< rec._number_of_days_of_delay << endl
		<< rec._address;
	return out;
}