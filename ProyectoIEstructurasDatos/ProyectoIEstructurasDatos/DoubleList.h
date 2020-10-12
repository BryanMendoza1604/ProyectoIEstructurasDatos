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
bool DoubleList<T>::isEmpty() {
	if (!first)
		return true;
	return false;
}



template<class T>
string DoubleList<T>::toString() {
	Node<T>* aux = first;
	stringstream s;

	while (aux != nullptr) {
		s << *aux->getInfo() << "\t";
		aux = aux->getNext();
	}

	return s.str();
}

