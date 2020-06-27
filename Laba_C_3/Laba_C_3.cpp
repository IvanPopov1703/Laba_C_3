#include "pch.h"
#include <iostream>
#include "WorkWithNotes.h"
#include "Record.h"

//Функция для корректного ввода с клавиатуры
int get_value()
{
	int num;
	string tmp;
	while (!(cin >> num) || cin.get() != '\n')
	{
		cout << "Введено некоректное значение, введите целое число" << endl << "-->";
		cin.clear();
		cin.sync();
		getline(cin, tmp);
	}
	return num;
}

//Функция для ввода числа и проверки диапазона
int range_check(int min, int max)
{
	int select = -1;
	string tmp;
	cout << endl << "--> ";
	do
	{
		select = get_value();
		if (select > max || select < min)
		{
			cout << "Ошибка ввода, такого пункта не существует!" << endl << "--> ";
		}
	} while (select > max || select < min);
	return select;
}

//Вывод представления записи
void representation_record()
{
	cout << endl << "Запись представленна следующим образом (вводить строго по шаблону):";
	cout << endl << " 1. Фамилия";
	cout << endl << " 2. Вид платежа(введите номер пункта):";
	cout << endl << "      1) Наличные";
	cout << endl << "      2) Безналично";
	cout << endl << " 3. Дата платежа(дд.мм.гггг)";
	cout << endl << " 4. Сумма платежа";
	cout << endl << " 5. Процент пении";
	cout << endl << " 6. Количество дней просрочки платежа";
	cout << endl << " 7. Адрес:";
	cout << endl << "      1) Улица";
	cout << endl << "      2) Номер дома";
	cout << endl << "      3) Номер квартиры";
}

//Вывод меню для работы с контейнером
void menu_for_wort_with_container()
{
	cout << endl << "Выберите пункт меню:";
	cout << endl << "1. Добавить элемент";
	cout << endl << "2. Удалить элемент";
	cout << endl << "3. Изменить элемент";
	cout << endl << "4. Очистить контейнер";
	cout << endl << "5. Отобразить содержимое контейнера";
	cout << endl << "6. Формирование нового контейнера по заданному критерию";
	cout << endl << "0. Выход в главное меню";
}

//Меню для редактирования
void menu_for_edit()
{
	cout << endl << "Выберите пункт меню для редактирования:";
	cout << endl << " 1. Фамилия";
	cout << endl << " 2. Вид платежа";
	cout << endl << " 3. Дата платежа(дд.мм.гггг)";
	cout << endl << " 4. Сумма платежа";
	cout << endl << " 5. Процент пении";
	cout << endl << " 6. Количество дней просрочки платежа";
	cout << endl << " 7. Адрес";
	cout << endl << " 0. Выход";
}

void menu_for_search()
{
	cout << endl << "Выберите критерий по которому будет проводиться отбор:";
	cout << endl << "1. Поиск по владельцу";
	cout << endl << "2. Поиск по дате";
	cout << endl << "3. Поиск по наличию долга";
	cout << endl << "4. Поиск по номеру дома";
	cout << endl << "5. Поиск по номеру квартиры";
}

void menu_alg_for_search()
{
	cout << endl << "Выберите вид алгоритма поиска:";
	cout << endl << "1. Линейный поиск";
	cout << endl << "2. Двоичный поиск";
}

void menu_out_for_search()
{
	cout << endl << "Выберите вид алгоритма поиска:";
	cout << endl << "1. Вывести в файл";
	cout << endl << "2. Вывести на экран";
	cout << endl << "0. Выход";
}

//Стартовое меню 
void menu_start()
{
	cout << endl << "Выберите действие:";
	cout << endl << "1. Создать новую базу данных";
	cout << endl << "2. Подключиться к существующей базе данных";
	cout << endl << "0. Выход";
}

void functional(WorkWithNotes<Record>& controller, const string& file_name)
{
	int select = -1;
	string tmp_str;
	do
	{
		menu_for_wort_with_container();
		select = range_check(0, 6);
		switch (select)
		{
		case 1:
		{
			representation_record();
			getline(cin, tmp_str);
			controller.add_elem(file_name);
			break;
		}
		case 2:
		{
			if (controller.empty())
			{
				cout << endl << "Данный контейнер пуст!" << endl;
			}
			else
			{
				representation_record();
				getline(cin, tmp_str);
				if (controller.del_elem(file_name))
				{
					cout << endl << "Элемент успешно удалён!";
				}
				else
				{
					cout << endl << "Не удалось удалить элемент!";
				}
			}
			break;
		}
		case 3:
		{
			if (controller.empty())
			{
				cout << endl << "Данный контейнер пуст!" << endl;
			}
			else
			{
				getline(cin, tmp_str);
				representation_record();
				controller.edit_elem([](Record& rec) -> void
				{
					int tmp_int, select_edit;
					double tmp_doub;
					string tmp_str;
					Date tmp_date;
					Address address;
					do
					{
						menu_for_edit();
						select_edit = range_check(0, 7);
						getline(cin, tmp_str);
						switch (select_edit)
						{
						case 1:
						{
							getline(cin, tmp_str);
							rec.set_fio(tmp_str);
							break;
						}
						case 2:
						{
							cin >> tmp_int;
							getline(cin, tmp_str);
							rec.set_payment_type(tmp_int);
							break;
						}
						case 3:
						{
							cin >> tmp_date;
							rec.set_date_payment(tmp_date);
							break;
						}
						case 4:
						{
							cin >> tmp_doub;
							getline(cin, tmp_str);
							rec.set_amount_of_payment(tmp_doub);
							break;
						}
						case 5:
						{
							cin >> tmp_doub;
							getline(cin, tmp_str);
							rec.set_percent_fine(tmp_doub);
							break;
						}
						case 6:
						{
							cin >> tmp_int;
							getline(cin, tmp_str);
							rec.set_number_of_days_of_delay(tmp_int);
							break;
						}
						case 7:
						{
							cin >> address;
							rec.set_address(address);
							break;
						}
						}
					} while (select_edit != 0);
				}, file_name);
			}
			break;
		}
		case 4:
		{
			controller.clear_vector(file_name);
			cout << endl << "Контейнер очищен!" << endl;
			break;
		}
		case 5:
		{
			controller.print_vector(controller.get_vector());
			break;
		}
		case 6:
		{
			if (controller.empty())
			{
				cout << endl << "Данный контейнер пуст!" << endl;
			}
			else
			{
				vector<Record> result;
				Record record;
				menu_for_search();
				int search_element = range_check(1, 5);
				switch (search_element)
				{
				case 1:
				{
					string surname;
					cout << endl << "Введите фамилию: ";
					getline(cin, surname);
					auto check = [surname](Record& rec)
					{
						return rec.get_fio() == surname;
					};
					menu_alg_for_search();
					if (range_check(1, 2) == 1)
					{
						result = controller.linear_search(check);
					}
					else
					{
						record.set_fio(surname);
						result = controller.binary_search(record, check, [](Record& rec1, Record& rec2) -> bool
						{
							return rec1.get_fio() < rec2.get_fio();
						});
					}
					break;
				}
				case 2:
				{
					Date date;
					cout << endl << "Введите дату в формате (дд.мм.гггг): ";
					cin >> date;
					auto check = [date](Record& rec)
					{
						return rec.get_date_payment() == date;
					};
					menu_alg_for_search();
					if (range_check(1, 2) == 1)
					{
						result = controller.linear_search(check);
					}
					else
					{
						record.set_date_payment(date);
						result = controller.binary_search(record, check, [](Record& rec1, Record& rec2) -> bool
						{
							return rec1.get_date_payment() < rec2.get_date_payment();
						});
					}
					break;
				}
				case 3:
				{
					auto check = [](Record& rec)
					{
						return rec.get_number_of_days_of_delay() == 0;
					};
					menu_alg_for_search();
					if (range_check(1, 2) == 1)
					{
						result = controller.linear_search(check);
					}
					else
					{
						result = controller.binary_search(record, check, [](Record& rec1, Record& rec2) -> bool
						{
							return rec1.get_number_of_days_of_delay() < rec2.get_number_of_days_of_delay();
						});
					}
					break;
				}
				case 4:
				{
					int number_house;
					cout << endl << "Введите номер дома: ";
					number_house = get_value();
					auto check = [number_house](Record& rec)
					{
						return rec.get_address().get_house_number() == number_house;
					};
					menu_alg_for_search();
					if (range_check(1, 2) == 1)
					{
						result = controller.linear_search(check);
					}
					else
					{
						record.get_address().set_house_number(number_house);
						result = controller.binary_search(record, check, [](Record& rec1, Record& rec2) -> bool
						{
							return rec1.get_address().get_house_number() < rec2.get_address().get_house_number();
						});
					}
					break;
				}
				case 5:
				{
					int number_flat;
					cout << endl << "Введите номер квартиры: ";
					number_flat = get_value();
					auto check = [number_flat](Record& rec)
					{
						return rec.get_address().get_flat_number() == number_flat;
					};
					menu_alg_for_search();
					if (range_check(1, 2) == 1)
					{
						result = controller.linear_search(check);
					}
					else
					{
						record.get_address().set_flat_number(number_flat);
						result = controller.binary_search(record, check, [](Record& rec1, Record& rec2) -> bool
						{
							return rec1.get_address().get_flat_number() < rec2.get_address().get_flat_number();
						});
					}
					break;
				}
				}

				if (result.empty())
				{
					cout << endl << "Ничего не найдено!";
				}
				else
				{
					do
					{
						menu_out_for_search();
						select = range_check(0, 2);
						switch (select)
						{
						case 1:
						{
							string filename;
							cout << endl << "Введите название файла" << endl << "-->";
							cin >> filename;
							controller.fill_file_from_vector(filename, result);
							break;
						}
						case 2:
						{
							cout << endl << "Результаты поиска:" << endl;
							controller.print_vector(result);
							break;
						}
						}
					} while (select != 0);
				}
				select = -1;
				break;
			}
		}
		}
	} while (select != 0);
}


int main()
{
	setlocale(0, "ru");
	WorkWithNotes<Record> controller; //Объект шаблонного класса
	int select = -1;
	string file_name; //Имя файла
	do
	{
		file_name = "";
		menu_start();
		controller.clear_vector();
		select = range_check(0, 2);
		switch (select)
		{
		case 1:
		{
			cout << endl << "Введите название новой базы данных" << endl << "-->";
			cin >> file_name;
			functional(controller, file_name);
			break;
		}
		case 2:
		{
			do
			{
				cout << endl << "Введите название базы данных" << endl << "-->";
				cin >> file_name;
			} while (!controller.fill_vector_from_file(file_name));
			functional(controller, file_name);
			break;
		}
		}
	} while (select != 0);

	system("pause");
	return 0;
}