#pragma once 
#include <iostream>

template <class T>
class stack {
	struct item {
		T i;
		item* next;
	};
	item* head;
public:
	void push(T);
	void pop();
	T pop1();
	stack();
	~stack();
	void show(T&);
	void clear();
	void removeAt(int index);
	bool empty();
};

