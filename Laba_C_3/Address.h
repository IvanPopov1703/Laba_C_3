#pragma once
#include<string>
using namespace std;

class Address
{
public:
	Address(); //����������� ��� ����������
	Address(string street, int house, int flat); //����������� � ����������� 

	//������� ��� �����
	string get_street() const;
	int get_house_number() const;
	int get_flat_number() const;

	//������� ��� �����
	void set_street(const string& street);
	void set_house_number(const int& number);
	void set_flat_number(const int& flat);

	//���������� ���������� �����/�� �����
	friend bool operator==(const Address& addres1, const Address& addres2);
	friend bool operator!=(const Address& addres1, const Address& addres2);

	//���������� ���������� �����/������
	friend ostream& operator<<(ostream& out, const Address& address);
	friend istream& operator>>(istream& in, Address& address);

private:
	int _house_number; //����� ����
	int _flat_number; //����� ��������
	string _street; //�����
};