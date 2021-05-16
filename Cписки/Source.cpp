#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
struct List
{
	char* data;
	List* next; 
};
List* make(int n)
{
	if (n == 0) {
		cout << "������ �� ����� ���� ������" << endl;
		return NULL;
	}
	List* first, * p;
	first = NULL;
	p = new List;
	p->data = new char[100];
	cout << "������� 1 �������: ";
	cin >> p->data;
	first = p;
	for (int i = 2; i <= n; i++)
	{
		p->next = new List;
		p = p->next;
		p->data = new char[100];
		p->next = NULL;

		cout << "������� " << i << " �������: ";
		cin >> p->data;
	}
	return first;
}
void print(List* first)
{
	if (first == NULL)
	{
		cout << "������ ������" << endl;
	}
	else
	{
		List* p = first;
		while (p != NULL)
		{
			if (p->data != NULL) {
				cout << p->data << " ";
			}
			p = p->next;
		}
		cout << endl;
	}
}
void add(List* list)
{
	if (list == NULL)
	{
		cout << "������ ������" << endl;
	}
	else
	{
		int i = 1;
		List* p = list;
		while (p != NULL)
		{
			if (p->data != NULL && i % 2 == 1) {
				cout << "������� " << i << " �������: ";
				cin >> p->data;
			}
			p = p->next;
			i++;
		}
		cout << endl;
	}
}

int main()
{
	system("color F0");
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	do
	{
		cout << "������� ���������� ��������� ������" << endl;
		cin >> size;
	} while (size < 1);
	List* list = make(size);
	print(list);
	add(list);
	print(list);
	return 0;
}