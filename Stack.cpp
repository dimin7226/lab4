#include "TransportVehicle.h"
#include"Stack.h"

template<class T>
stack<T>::stack() {
	head = nullptr;
}

template<class T>
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
	delete p->i; // Освобождаем память, на которую указывает p->i
	delete p;
}

template<class T>
T stack<T>::pop1() {
	if (head == nullptr) {
		std::cout << "Стек пуст" << std::endl;
		return T(); // Возвращаем значение по умолчанию для T
	}
	item* p = head;
	head = head->next;
	T tmp = p->i; // Копируем значение
	delete p;     // Удаляем только узел
	return tmp;
}

template <class T>
void stack<T>::show() {
	if (head == NULL) {
		std::cout << "Стек пуст" << std::endl;
		return;
	}
	int rowNumber = 1;
	item* p = this->head;
	while (p != NULL) {
		if (p->i != nullptr) { // Проверяем, что указатель не нулевой
			p->i->show();
			std::cout << std::setw(5) << rowNumber++ << *p->i << std::endl; // Вызываем метод show() у объекта, на который указывает p->i
			std::cout << std::endl;
		}
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
	delete toDelete->i; // Освобождаем память, на которую указывает toDelete->i
	delete toDelete;
}
