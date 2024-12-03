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
		std::cout << "���� ����" << std::endl;
		return;
	}
	item* p = head;
	head = head->next;
	delete p->i; // ����������� ������, �� ������� ��������� p->i
	delete p;
}

template<class T>
T stack<T>::pop1() {
	if (head == nullptr) {
		std::cout << "���� ����" << std::endl;
		return T(); // ���������� �������� �� ��������� ��� T
	}
	item* p = head;
	head = head->next;
	T tmp = p->i; // �������� ��������
	delete p;     // ������� ������ ����
	return tmp;
}

template <class T>
void stack<T>::show() {
	if (head == NULL) {
		std::cout << "���� ����" << std::endl;
		return;
	}
	int rowNumber = 1;
	item* p = this->head;
	while (p != NULL) {
		if (p->i != nullptr) { // ���������, ��� ��������� �� �������
			p->i->show();
			std::cout << std::setw(5) << rowNumber++ << *p->i << std::endl; // �������� ����� show() � �������, �� ������� ��������� p->i
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
		std::cout << "�������� ������ ��� ���� ����" << std::endl;
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
		std::cout << "������ ��� ���������" << std::endl;
		return;
	}
	item* toDelete = current->next;
	current->next = toDelete->next;
	delete toDelete->i; // ����������� ������, �� ������� ��������� toDelete->i
	delete toDelete;
}
