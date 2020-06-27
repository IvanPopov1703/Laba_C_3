#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <functional>
#include <list>

using namespace std;

template<typename T>
int distance(typename vector<T>::iterator first, typename vector<T>::iterator last, const vector<T>& vect);

template <typename T>
class WorkWithNotes
{
public:
	void add_elem(const string& filename); //���������� ��������
	bool del_elem(const string& filename); //�������� ��������
	bool edit_elem(function<void(T&)> change, const string& filename); //��������� ��������
	void clear_vector(const string& filename); //������� ����������
	void clear_vector(); //������������� ������� ������� ����������
	bool empty(); //�������� �� �������
	void fill_file_from_vector(const string& file_name, const vector<T>& vect); //���������� ���� ���������� ����������
	bool fill_vector_from_file(const string& file_name); //���������� �� ���� � ������
	void print_vector(const vector<T>& vect); //������ �������
	vector<T> get_vector(); //��������� ����������

	vector<T> linear_search(function<bool(T&)> check);
	vector<T> binary_search(T& value, function<bool(T&)> check, function<bool(T&, T&)> compare);

private:
	vector<T> _vector;
};

//������� ���������� ��������
template<typename T>
void WorkWithNotes<T>::add_elem(const string& filename)
{
	T tmpEl;
	cout << endl << "������� �������:" << endl;
	cin >> tmpEl;
	_vector.push_back(tmpEl);
	try
	{
		fill_file_from_vector(filename, _vector);
		cout << endl << "������� ������� ��������!" << endl;
	}
	catch (const char* msg)
	{
		cout << endl << msg;
	}
}

template<typename T>
vector<T> WorkWithNotes<T>::get_vector()
{
	return _vector;
}

//������� �������� ��������
template<typename T>
bool WorkWithNotes<T>::del_elem(const string& filename)
{
	T tmpEl;
	cout << endl << "������� �������, ������� ���������� �������:";
	cin >> tmpEl;
	auto iter = find(_vector.begin(), _vector.end(), tmpEl);
	if (iter == _vector.end())
	{
		return false;
	}
	try
	{
		_vector.erase(iter);
		fill_file_from_vector(filename, _vector);
		return true;
	}
	catch (const char* msg)
	{
		cout << endl << msg;
	}
	return false;
}

//������� ��������� ��������
template<typename T>
bool WorkWithNotes<T>::edit_elem(function<void(T&)> change, const string& filename)
{
	cout << endl << "������� �������, ������� ���������� ��������:" << endl;
	T tmp;
	cin >> tmp;
	auto iter = find(_vector.begin(), _vector.end(), tmp);
	if (iter != _vector.end())
	{
		cout << endl << "�������� ������� ������" << endl;
		change(*iter);
		try
		{
			fill_file_from_vector(filename, _vector);
			cout << endl << "�������� ������� ������� ������" << endl;
			return true;
		}
		catch (const char* msg)
		{
			cout << endl << msg;
		}
	}
	else
	{
		cout << endl << "�������� ������� �����������" << endl;
		return false;
	}
}

//������� ������� �������
template<typename T>
void WorkWithNotes<T>::clear_vector(const string& filename)
{
	_vector.clear();
	fill_file_from_vector(filename, _vector);
}

//������������� ������� ������� �������
template<typename T>
void WorkWithNotes<T>::clear_vector()
{
	_vector.clear();
}

//������� �������� ������� �� �������
template<typename T>
bool WorkWithNotes<T>::empty()
{
	return _vector.empty();
}

template<typename T>
int distance(const typename vector<T>::iterator _first, const typename vector<T>::iterator _last, const vector<T>& vect)
{
	typename vector<T>::iterator first = _first;
	typename vector<T>::iterator last = _last;
	int dist = 0;
	while ((first != vect.end()) && (first != last))
	{
		++first;
		dist++;
	}
	if (first != last)
	{
		dist = -1;
	}
	return dist;
}

//���������� ���� ���������� ����������
template<typename T>
void WorkWithNotes<T>::fill_file_from_vector(const string& file_name, const vector<T>& vect)
{
	ofstream fout(file_name);
	if (!fout.is_open())
	{
		throw "���� ������ �� �������!";
	}
	ostream_iterator<T> ositer(fout, "\n");
	copy(vect.begin(), vect.end(), ositer);
	fout.close();
}

//���������� ���������� �� �����
template<typename T>
bool WorkWithNotes<T>::fill_vector_from_file(const string& file_name)
{
	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cout << endl << "�� ������ ������������ � ���� ������!" << endl;
		return false;
	}
	else
	{
		if (fin.peek() == EOF)
		{
			cout << endl << "������������ ���� �� ���������!" << endl;
		}
		else
		{
			_vector.clear();
			copy(istream_iterator<T>(fin), istream_iterator<T>(), back_inserter(_vector));
			cout << endl << "���������� ������� �����������!" << endl;
		}
		fin.close();
		return true;
	}
}

//������ ��������� ����������
template<typename T>
void WorkWithNotes<T>::print_vector(const vector<T>& vect)
{
	if (vect.empty())
	{
		cout << endl << "��������� ����!" << endl;
	}
	else
	{
		ostream_iterator<T> ositer(cout, "\n");
		cout << endl << "��������� �������� ��������� ��������:" << endl;
		copy(vect.begin(), vect.end(), ositer);
	}
}

//�������� �����
template<typename T>
vector<T> WorkWithNotes<T>::linear_search(function<bool(T&)> check)
{
	vector<T> result;
	for (T elem : _vector)
	{
		if (check(elem))
		{
			result.push_back(elem);
		}
	}
	return result;
}

//�������� �����
template<typename T>
vector<T> WorkWithNotes<T>::binary_search(T& value, function<bool(T&)> check,
	function<bool(T&, T&)> compare)
{
	sort(_vector.begin(), _vector.end(), compare);
	auto left_border = _vector.begin();
	auto right_border = _vector.end();
	--right_border;
	int dist = distance(left_border, right_border, _vector);

	while (dist > 0)
	{
		auto mid = left_border;
		int offset = dist / 2;
		for (int i = 0; i < offset; i++)
		{
			++mid;
		}
		if (compare(value, *mid))
		{
			right_border = mid;
			--right_border;
		}
		else
		{
			left_border = mid;
			++left_border;
		}
		dist = distance(left_border, right_border, _vector);
	}

	vector<T> result;
	for (; (right_border != _vector.begin() && check(*right_border)); --right_border)
	{
		result.insert(result.begin(), *right_border);
	}
	if (check(*right_border))
	{
		result.insert(result.begin(), *right_border);
	}
	return result;
}