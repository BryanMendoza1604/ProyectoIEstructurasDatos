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
	DoubleList(DoubleList&);
	~DoubleList();
	Node<T>* getFirst();
	void insert(T*);
	void deleteInfo(T*);
	void deleteByIndex(int);
	void updateIndexList(); // update the index from the list, needed to the heap 
	T* getObjByIndex(int); // return an object through a specific index;
	void swapInfoByIndex(int, int);
	int getLastIndex(); // return the last object's index
	bool compare(T&, T&);
	bool isEmpty();
	string toString();
};



//--------------DoubleList.cpp-----------------

template<class T>
DoubleList<T>::DoubleList() {
	first = nullptr;
}

template<class T>
DoubleList<T>::DoubleList(DoubleList<T>& dList) {
	Node<T>* aux = first;
	while (dList.first != nullptr && aux == nullptr)
	{
		aux->setInfo(dList.getFirst()->getInfo());
		aux->setPrior(dList.getFirst()->getPrior());
		aux->setNext(dList.getFirst()->getNext());
		dList.first = dList.first->getNext();
		aux = aux->getNext();
	}
}


template<class T>
DoubleList<T>::~DoubleList() {
	Node<T>* aux;

	while (first != nullptr) {
		aux = first;
		first = first->getNext();
		delete aux;
	}
}

template<class T>
Node<T>* DoubleList<T>::getFirst() {
	return first;
}

template<class T>
void DoubleList<T>::insert(T* info) {
	Node<T>* aux = first;
	Node<T>* newNode = new Node<T>(info, nullptr, nullptr);

	if (isEmpty()) {
		first = newNode;
	}
	else {
		while (aux->getNext() != nullptr)
		{
			aux = aux->getNext();
		}
		aux->setNext(newNode);
		newNode->setPrior(aux);
	}
	updateIndexList();


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
	/*else
		throw "Lista Vacia";*/
	updateIndexList();
}

template<class T>
void DoubleList<T>::deleteByIndex(int i) {
	Node<T>* aux = first;
	Node<T>* tempNext;
	Node<T>* tempPrior;

	if (!isEmpty()) {
		if (i == first->getIndex() && first->getNext() == nullptr) {
			first = nullptr;
		}
		else if (i == first->getIndex() && first->getNext() != nullptr) {
			first = first->getNext();
			first->setPrior(nullptr);
			first->setNext(first->getNext());

		}
		else {
			while (aux->getNext() != nullptr) {
				if (aux->getIndex() == i) {
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
	/*else
		throw "Lista Vacia";*/
	updateIndexList();
}

template<class T>
void DoubleList<T>::updateIndexList() {
	Node<T>* aux = first;
	int index = 0;
	while (aux != nullptr)
	{
		aux->setIndex(index);
		index++;
		aux = aux->getNext();
	}
}

template<class T>
T* DoubleList<T>::getObjByIndex(int index) {
	Node<T>* aux = first;
	T* auxObj = nullptr;
	while (aux != nullptr) {
		if (aux->getIndex() == index)
			auxObj = aux->getInfo();
		aux = aux->getNext();
	}
	return auxObj;
}

template<class T>
void DoubleList<T>::swapInfoByIndex(int x, int y) {
	T* X = getObjByIndex(x);
	T* Y = getObjByIndex(y);
	Node<T>* aux = first;
	
	while (aux != nullptr)
	{
		if (aux->getInfo() == X)
			aux->setInfo(Y);
		else if (aux->getInfo() == Y)
			aux->setInfo(X);
		aux = aux->getNext();
	}

}

template<class T>
int DoubleList<T>::getLastIndex() {
	Node<T>* aux = first;
	int last;

	while (aux != nullptr)
	{
		if (aux->getNext() == nullptr)
			last = aux->getIndex();
		aux = aux->getNext();
	}
	return last;
}

template<class T>
bool DoubleList<T>::compare(T& a, T& b) {
	return (a < b) ? true : false;
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

