#include "pch.h"
#include "Address.h"
#include <string>

//����������� ��� ����������
Address::Address() :
	_street(""),
	_house_number(0),
	_flat_number(0) { }

//����������� � �����������
Address::Address(string street, int house, int flat) :
	_street(street),
	_house_number(house),
	_flat_number(flat) { }

//������� ��� �����
string Address::get_street() const { return _street; }
int Address::get_house_number() const { return _house_number; }
int Address::get_flat_number() const { return _flat_number; }

//������� ��� �����
void Address::set_street(const string& street)
{
	this->_street = street;
}

void Address::set_house_number(const int& number)
{
	this->_house_number = number;
}

void Address::set_flat_number(const int& flat)
{
	this->_flat_number = flat;
}

//���������� ��������� "�����"
bool operator==(const Address& addr1, const Address& addr2)
{
	return (addr1._street == addr2._street && addr1._house_number == addr2._house_number
		&& addr1._flat_number == addr2._flat_number);
}

//���������� ��������� "�� �����"
bool operator!=(const Address& addr1, const Address& addr2)
{
	return !(addr1 == addr2);
}

//���������� ��������� ������
ostream& operator<<(ostream& out, const Address& address)
{
	out << address._street << endl
		<< address._house_number << endl
		<< address._flat_number;
	return out;
}

//���������� ��������� �����
istream& operator>>(istream& in, Address& address)
{
	string s;
	getline(in, address._street);
	in >> address._house_number;
	getline(in, s);
	in >> address._flat_number;
	getline(in, s);
	return in;
}
