#pragma once

#include <sstream>

#include "Node.h"

using std::string;

template <class T>
class DoubleList
{
private:
	Node<T>* first;
public:
	DoubleList();
	~DoubleList();
	void insert(T*);
	void deleteInfo(T*);
	bool isEmpty();
	string toString();
};



//--------------DoubleList.cpp-----------------

template<class T>
DoubleList<T>::DoubleList() {
	first = nullptr;
}



template<class T>
DoubleList<T>::~DoubleList() {

}

template<class T>
void DoubleList<T>::insert(T* info) {
	Node<T>* aux = first;
	Node<T>* newNode = new Node<T>(info, nullptr, nullptr);

	if (isEmpty()) {
		first = newNode;
		first->setIndex(0);
	}
	else {
		while (aux->getNext() != nullptr)
		{
			aux = aux->getNext();
		}
		aux->setNext(newNode);
		newNode->setPrior(aux);
	}


}

template<class T>
void DoubleList<T>::deleteInfo(T* info) {
	Node<T>* aux = first;
	Node<T>* tempNext;
	Node<T>* tempPrior;

	if (!isEmpty()) {
		if (info == first->getInfo() && first->getNext() == nullptr) {
			first = nullptr;
		}
		else if (info == first->getInfo() && first->getNext() != nullptr) {
			first = first->getNext();
			first->setPrior(nullptr);
			first->setNext(first->getNext());
			
		}
		else {
			while (aux->getNext() != nullptr) {
				if (aux->getInfo() == info) {
					tempNext = aux->getNext();
					tempPrior = aux->getPrior();
					tempNext->setPrior(tempPrior);
					tempPrior->setNext(tempNext);
					delete aux;
					break;
				}
				else
					aux = aux->getNext();
			}
		}
	
	}
	else
		throw "Lista Vacia";
}

template<class T>
bool DoubleList<T>::isEmpty() {
	if (!first)
		return true;
	return false;
}



template<class T>
string DoubleList<T>::toString() {
	Node<T>* aux = first;
	stringstream s;

	if (!isEmpty()) {
		while (aux != nullptr) {
			s << *aux->getInfo() << "\t";
			aux = aux->getNext();
		}
	}
	else
		s << "Lista Vacia!" << "\t";
	

	return s.str();
	
}

