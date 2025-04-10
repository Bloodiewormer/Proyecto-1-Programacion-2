#pragma once
#include <iostream>
#include "Nodo.h"
#include "CustomExeception.h"

template <class T>
class Lista {
private:
	Nodo<T>* first;
	int length;
public:

	Lista() {
		first = nullptr;
		length = 0;
	}

	~Lista() {
		while (first != nullptr) {
			Nodo<T>* aux = first;
			first = first->getNext();
			delete aux; 
			aux = nullptr;
		}
	}

	int getLength() const {
		return length;
	}

	bool isEmpty() const {
		return first == nullptr;
	}

	void addBegin(T* data) {
		Nodo<T>* aux = new Nodo<T>(data);
		if (data == nullptr) {
			throw InvalidInputException("Data cannot be null");
		}
		if (!isEmpty()) {
			aux->setNext(first);
			first = aux;
			length++;
		}
		else
		{
			first = aux;
			length++;
		}
	}


	T* get(int index) const {
		Nodo<T>* aux = first;
		if (index >= length) {
			throw IndexOutOfBoundsException("Index out of bounds");
		}
		if (index == 0) {
			return aux->getData(); 
		}
		for (unsigned int idx = 0; idx < index; idx++) {
			aux = aux->getNext();
		}
		return aux->getData();
	}


	void remove(T* data) {
		if (first == nullptr) {
			return;
		}
		if (first->getData() == data) {
			Nodo<T>* aux = first;
			first = first->getNext();
			delete aux;
			length--;
			return;
		}
		Nodo<T>* aux = first;
		while (aux->getNext() != nullptr) {
			if (aux->getNext()->getData() == data) {
				Nodo<T>* aux2 = aux->getNext();
				aux->setNext(aux2->getNext());
				delete aux2;
				length--;
				return;
			}
			aux = aux->getNext();
		}
	}

	void remove(unsigned int index) {
		if (first == nullptr) {
			return;
		}
		if (index >= length) {
			throw IndexOutOfBoundsException("Index out of bounds");
		}
		if (index == 0) {
			Nodo<T>* aux = first;
			first = first->getNext();
			delete aux;
			length--;
			return;
		}
		Nodo<T>* aux = first;
		for (unsigned int idx = 0; idx < index - 1; idx++) {
			aux = aux->getNext();
		}
		Nodo<T>* aux2 = aux->getNext();
		aux->setNext(aux2->getNext());
		delete aux2;
		length--;
	}

	int getLength() {
		return length;
	}

	bool contains(T* data) {
		Nodo<T>* aux = first;
		while (aux != nullptr) {
			if (aux->getData() == data) {
				return true;
			}
			aux = aux->getNext();
		}
		return false;
	}


	std::string CSV() {
		std::string csv = "";
		Nodo<T>* aux = first;
		while (aux != nullptr) {
			csv += aux->getData()->toStringCSV() + "\n";
			aux = aux->getNext();
		}
		return csv;
	}
	






};

//funny
// with this  you can acces a tostring method in string XD

//class string :public std::string {
//public:
//	string(std::string str) : std::string(str) {}
//	string() : std::string() {}
//	~string() {}
//	std::string toString() {
//		return *this;
//	}
//};

