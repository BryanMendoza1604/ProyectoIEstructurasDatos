#pragma once

#include <sstream>
#include <iostream>

#include "Number.h"


using std::stringstream;
using std::string;
using std::ostream;

template<class T>
class Node
{
private:
	T* info;
	Node<T>* next;

public:
	Node();
	Node(T*, Node<T>*);
	T* getInfo();
	Node<T>* getNext();
	void setInfo(T*);
	void setNext(Node<T>*);
	string toString();
	~Node();

};



//-------------------Node.cpp----------------------

template<class T>
Node<T>::Node() {

}

template<class T>
Node<T>::Node(T* info, Node<T>* next): info(info), next(next) {

}

template<class T>
T* Node<T>::getInfo() {
	return info;
}

template<class T>
Node<T>* Node<T>::getNext() {
	return next;
}

template<class T>
void Node<T>::setInfo(T* info) {
	this->info = info;
}

template<class T>
void Node<T>::setNext(Node<T>* next) {
	this->next = next;
}

template<class T>
string Node<T>::toString() {
	stringstream s;
	s << info << '\n';
	return s.str();
}

template<class T>
Node<T>::~Node() {
	delete next;
	info = nullptr;
}
