#pragma once
#include <string>
#include "Address.h"
#include "Date.h"

using namespace std;

const string CASH_PAYMENT = "��������";
const string CASHLESS_PAYMENT = "����������";
const string NOT_CHOSEN = "�� �������";

class Record
{
public:
	Record(); //����������� ��� ����������
	Record(string fio, string paymentView, Date date, double amount, double percentFine, int delay, Address address); //�����������

	//������� ��� �����
	string get_fio() const;
	string get_payment_type(const int& num) const;
	Date get_date_payment() const;
	double get_amount_of_payment() const;
	double get_percent_fine() const;
	int get_number_of_days_of_delay() const;
	Address& get_address();

	//������� ��� �����
	void set_fio(const string& fio);
	void set_payment_type(const int& num);
	void set_date_payment(const Date& date);
	void set_amount_of_payment(const double& amount);
	void set_percent_fine(const double& fine);
	void set_number_of_days_of_delay(const double& delay);
	void set_address(const Address& address);

	//���������� ���������� �����/�� �����
	friend bool operator==(const Record& r1, const Record& r2);
	friend bool operator!=(const Record& r1, const Record& r2);

	//���������� ���������� �����/������
	friend ostream& operator << (ostream& out, const Record& record);
	friend istream& operator >> (istream& in, Record& record);

private:
	string _fio; //���
	string _payment_type; //��� ������� (��������, �����������)
	Date _date_payment; //���� �������
	double _amount_of_payment; //����� �������
	double _percent_fine; //������� ����� (������)
	int _number_of_days_of_delay; //���������� ��� ��������� �������
	Address _address; //�����
};