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
	void updateIndexList(); // update the index from the list, needed to the heap 
	T* getObjByIndex(int); // return an object through a specific index;
	void swapInfoByIndex(int, int);
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
		if (aux->getInfo() == getObjByIndex(x)) {
			aux->setInfo(tmpY);
		}
		else if (aux.getInfo() == getObjByIndex(y)) {
			aux->setInfo(tmpX);
		}
		aux = aux->getNext();
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

