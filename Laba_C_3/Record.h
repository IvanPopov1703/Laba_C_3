#pragma once
#include <string>
#include "Address.h"
#include "Date.h"

using namespace std;

const string CASH_PAYMENT = "Наличные";
const string CASHLESS_PAYMENT = "Безналично";
const string NOT_CHOSEN = "Не выбрано";

class Record
{
public:
	Record(); //Конструктор без параметров
	Record(string fio, string paymentView, Date date, double amount, double percentFine, int delay, Address address); //Конструктор

	//Геттеры для полей
	string get_fio() const;
	string get_payment_type(const int& num) const;
	Date get_date_payment() const;
	double get_amount_of_payment() const;
	double get_percent_fine() const;
	int get_number_of_days_of_delay() const;
	Address& get_address();

	//Сеттеры для полей
	void set_fio(const string& fio);
	void set_payment_type(const int& num);
	void set_date_payment(const Date& date);
	void set_amount_of_payment(const double& amount);
	void set_percent_fine(const double& fine);
	void set_number_of_days_of_delay(const double& delay);
	void set_address(const Address& address);

	//Перегрузка операторов равно/не равно
	friend bool operator==(const Record& r1, const Record& r2);
	friend bool operator!=(const Record& r1, const Record& r2);

	//Перегрузка операторов ввода/вывода
	friend ostream& operator << (ostream& out, const Record& record);
	friend istream& operator >> (istream& in, Record& record);

private:
	string _fio; //Фио
	string _payment_type; //Вид платежа (наличный, безналичный)
	Date _date_payment; //Дата платежа
	double _amount_of_payment; //Сумма платежа
	double _percent_fine; //Процент пении (штрафа)
	int _number_of_days_of_delay; //Количество дне просрочки платежа
	Address _address; //Адрес
};