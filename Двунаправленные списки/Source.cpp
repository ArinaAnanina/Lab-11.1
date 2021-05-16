#include <iostream>
#include <string>
#include <Windows.h>
#include <iterator>
#include <list>
using namespace std;
 // с помощью STL библиотеки
list<int> makeSTL(int n)
{
	list<int> res;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cout << "¬ведите элемент " << i + 1 << ": ";
		cin >> tmp;
		res.push_back(tmp);
	}
	return res;
}

void printSTL(list<int> a)
{
	if (a.size() == 0)
		cout << "Cписок пустой" << endl;
	else
	{
		for (list<int>::iterator it = a.begin(); it != a.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
}
void deletionSTL(list<int> &a)
{
	if (a.size() == 0)
		cout << "Cписок пустой" << endl;
	else
	{
		bool f = true;
		list<int>::reverse_iterator itr = a.rbegin();
		while (itr != a.rend())
		{
			if (*itr % 2 == 0)
			{
				a.erase(next(itr).base());
				break;
			}
			itr++;
		}			
		cout << endl;
	}
}

// с помощью структур
struct List
{
	int data;
	List* next;
	List* prev;
};
List* make(int n)
{
	if (n == 0) {
		cout << "—писок не может быть создан" << endl;
		return NULL;
	}
	List* first, * p;
	first = NULL;
	cout << "¬ведите 1 элемент: ";
	p = new List;
	cin >> p->data;
	first = p;
	p->prev = NULL;
	for (int i = 2; i <= n; i++)
	{
		p->next = new List;
		p->next->prev = p;
		p = p->next;
		cout << "¬ведите " << i << " элемент: ";
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}
void print(List* first)
{
	if (first == NULL)
	{
		cout << "—писок пустой" << endl;
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
void deletion(List* list)
{
	if (list == NULL)
	{
		cout << "—писок пустой" << endl;
	}
	else
	{
		List* evenItem = NULL;
		while (list != NULL)
		{
			if (list->data != NULL && list->data % 2 == 0) {
				evenItem = list;
			}
			list = list->next;
		}
		if (evenItem != NULL) {
			if (evenItem->prev != NULL) {
				evenItem->prev->next = evenItem->next;
			}
			if (evenItem->next != NULL) {
				evenItem->next->prev = evenItem->prev;
			}
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

	// с помощью STL 
    cout << "ƒвунаправленный список через STL" << endl;
	int size;
	do
	{
		cout << "¬ведите количество элементов списка ";
		cin >> size;
	} while (size < 1);
	list<int> myList = makeSTL(size);
	printSTL(myList);
	deletionSTL(myList);
	printSTL(myList);

	// с помощью структур
	cout << "ƒвунаправленный список через структуры " << endl;
	int size2;
	do
	{
		cout << "¬ведите количество элементов списка" << endl;
		cin >> size2;
	} while (size2 < 1);
	List* list = make(size2);
	List* list2;
	print(list);
	deletion(list);
	print(list);

	return 0;
}




/*
listEven->prev->next = listEven->next;
listEven->next->prev = listEven->prev;

f = false;
while (f) {
	if (list->next == NULL) {
		f = true;
	}
	else {
		list = list->next();
	}
}

while (list != NULL) {
	if (list->data % 2 == 0) {

	}
	list = list->prev;
}
*/