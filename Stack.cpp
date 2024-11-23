#include "TransportVehicle.h"
#include"Stack.h"

template<class T>
stack<T>::stack() {
	head = NULL;
}

template <class T>
stack<T>::~stack() {
	clear();
}

template<class T>
void stack<T>::push(T value) {
	item* newitem = new item();
	newitem->i = value;
	newitem->next = head;
	head = newitem;
}

template<class T>
void stack<T>::pop() {
	if (head == NULL) {
		std::cout << "Стек пуст" << std::endl;
		return;
	}
	item* p = head;
	head = head->next;
	delete p;
}

template<class T>
T stack<T>::pop1() {
	if (head == NULL) {
		std::cout << "Стек пуст" << std::endl;
		return T(); // Возвращаем значение по умолчанию
	}
	item* p = head;
	head = head->next;
	T tmp = p->i;
	delete p;
	return tmp;
}

template <class T>
void stack<T>::show(T& obj) {
	if (head == NULL) {
		std::cout << "Стек пуст" << std::endl;
		return;
	}
	obj.show();
	std::cout << std::endl;
	int rowNumber = 1;
	item* p = this->head;
	while (p != NULL) {
		std::cout << std::setw(5) << rowNumber++ << p->i << std::endl;
		p = p->next;
	}
}

template <class T>
bool stack<T>::empty() {
	return head == NULL;
}

template <class T>
void stack<T>::clear() {
	while (!empty()) {
		pop();
	}
}

template <class T>
void stack<T>::removeAt(int index) {
	if (index < 0 || head == NULL) {
		std::cout << "Неверный индекс или стек пуст" << std::endl;
		return;
	}

	if (index == 0) {
		pop();
		return;
	}

	item* current = head;
	for (int i = 0; i < index - 1 && current->next != NULL; ++i) {
		current = current->next;
	}

	if (current->next == NULL) {
		std::cout << "Индекс вне диапазона" << std::endl;
		return;
	}

	item* toDelete = current->next;
	current->next = toDelete->next;
	delete toDelete;
}

