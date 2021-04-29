#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Data {
	int a;
};

struct List {
	Data d;
	List* next;
};

void Print(List* u);
void Insert(List** u, Data& ex);

int main() {
	List* u = NULL;

	u = new List;
	u->d.a = 1;

	u->next = NULL;

	List* x;
	x = u;

	x->next = new List;
	x = x->next;
	x->d.a = 2;
	x->next = NULL;

	x->next = new List;
	x = x->next;
	x->d.a = 3;
	x->next = NULL;

	x->next = new List;
	x = x->next;
	x->d.a = 2;
	x->next = NULL;

	x->next = new List;
	x = x->next;
	x->d.a = 1;
	x->next = NULL;

	Data ex;
	ex.a = 5;

	Print(u);
	Insert(&u, ex);
	Print(u);
}
void Print(List* u) {
	List* p = u;
	cout << "List:" << endl;
	while (p) {
		cout << p->d.a << endl;
		p = p->next;
	}
}
void Insert(List** u, Data& x) {
	List* p = new List;
	p->d.a = x.a;
	List* t = *u;
	List* t1 = t->next;

	while (t1) {
		if (t->d.a == 2) {
			t->next = p;
			p->next = t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}