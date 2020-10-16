#pragma once
#include <sstream>

#include "Heap.h"

using std::string;

template<class T>
class PriorityQueue {
private:
	Heap<T>* heapInit;

public:
	PriorityQueue();
	PriorityQueue(DoubleList<T>&);
	~PriorityQueue();
	void insert(T*);
	T* deleteGetMax();
	string toString();
};


//------------------PriorityQueue.cpp---------------------

template<class T>
PriorityQueue<T>::PriorityQueue() {
	heapInit = new Heap<T>();
}

template<class T>
PriorityQueue<T>::PriorityQueue(DoubleList<T>& list) {
	heapInit = new Heap<T>(list);
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
	delete heapInit;
}

template<class T>
void PriorityQueue<T>::insert(T* obj) {
	heapInit->insert(obj);
}

template<class T>
T* PriorityQueue<T>::deleteGetMax() {
	return heapInit->deleteMax();
}

template<class T>
string PriorityQueue<T>::toString() {
	return heapInit->toString();
}