#pragma once
#include<string>
using namespace std;

class Address
{
public:
	Address(); //Конструктор без параметров
	Address(string street, int house, int flat); //Конструктор с параметрами 

	//Геттеры для полей
	string get_street() const;
	int get_house_number() const;
	int get_flat_number() const;

	//Сеттеры для полей
	void set_street(const string& street);
	void set_house_number(const int& number);
	void set_flat_number(const int& flat);

	//Перегрузка операторов равно/не равно
	friend bool operator==(const Address& addres1, const Address& addres2);
	friend bool operator!=(const Address& addres1, const Address& addres2);

	//Перегрузка операторов ввода/вывода
	friend ostream& operator<<(ostream& out, const Address& address);
	friend istream& operator>>(istream& in, Address& address);

private:
	int _house_number; //Номер дома
	int _flat_number; //Номер квартиры
	string _street; //Улица
};