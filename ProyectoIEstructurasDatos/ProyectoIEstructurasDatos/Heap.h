#pragma once

#include <sstream>

#include "DoubleList.h"
#include "Number.h"

using std::string;

template<class T>
class Heap {

protected:
	DoubleList<T>* list;

public:
	Heap();
	Heap(DoubleList<T>&);
	~Heap();
	void insert(T*);
	void deleteObj(T*);
	void maxHeapify(int i);
	T* deleteMax();  // return and delete the Max element on the heap
	string toString();

private:
	int parent(int);
	int left(int);
	int right(int);
	void bubbleUp(int);
	void swap(int, int);
	bool compare(int, int);
};



//---------------------Heap.cpp-----------------------



template<class T>
Heap<T>::Heap() {
	list = new DoubleList<T>();
}

template<class T>
Heap<T>::Heap(DoubleList<T>& dlist) {
	list = new DoubleList<T>(DoubleList<T>& dlist);
}

template<class T>
Heap<T>::~Heap() {
	delete list;
}



template<class T>
void Heap<T>::insert(T* obj) {
	list->insert(obj);
	bubbleUp(list->getLastIndex());
}

template<class T>
void Heap<T>::deleteObj(T*) {

}

template<class T>
void Heap<T>::maxHeapify(int i) {
	int leftNode = left(i);
	int rightNode = right(i);
	int tmp = 0;

	if (leftNode > list->getLastIndex() && compare(i, leftNode)) {
		tmp = leftNode;
	}
	else
		tmp = i;

	if (rightNode > list->getLastIndex() && compare(i, rightNode))
		tmp = rightNode;

	if (tmp != i) {
		swap(i, tmp);
		maxHeapify(tmp);
	}
}

template<class T>
T* Heap<T>::deleteMax() {
	int maxIndex = list->getLastIndex();
	
	T* tmp = list->getObjByIndex(0);
	swap(0, maxIndex);
	list->deleteByIndex(0);
	maxHeapify(0);
	return tmp;
}

template<class T>
string Heap<T>::toString() {
	return list->toString();
}


template<class T>
int Heap<T>::parent(int i) {
	return (i - 1) / 2;
}

template<class T>
int Heap<T>::left(int i) {
	return 2 * i - 1;
}

template<class T>
int Heap<T>::right(int i) {
	return 2 * i - 2;
}

template<class T>
void Heap<T>::bubbleUp(int i) {
	int tmp = parent(i);

	while (i > 0 && compare(tmp, i))
	{
		swap(i, tmp);
		i = tmp;
		tmp = parent(i);
	}
	

}

template<class T>
void Heap<T>::swap(int x, int y) {
	list->swapInfoByIndex(x, y);
}

template<class T>
bool Heap<T>::compare(int x, int y) {
	return list->compare(*list->getObjByIndex(x), *list->getObjByIndex(y));
}