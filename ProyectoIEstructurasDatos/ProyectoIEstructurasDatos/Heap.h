#pragma once

#include "DoubleList.h"

template<class T>

class Heap {

protected:
	DoubleList* list;

public:
	Heap();
	~Heap();
	void insert(T*);
	void deleteObj(T*);

private:
	int parent(int);
	int leaf(int);
	int right(int);
	void bubbleUp(int);
	void swap(int, int);
};



//---------------------Heap.cpp-----------------------

template<class T>
Heap<T>::Heap() {
	list = new DoubleList();
}


template<class T>
int Heap<T>::parent(int i) {
	return (i - 1) / 2;
}

template<class T>
int Heap<T>::leaf(int i) {
	return 2 * i - 1;
}

template<class T>
int Heap<T>::right(int i) {
	return 2 * i - 2;
}

template<class T>
void Heap<T>::bubbleUp(int i) {
	int tmp = parent(i);

	while (i > 0 && list->getObjByIndex())
	{


	}

}

template<class T>
void Heap<T>::swap(int x, int y) {
	T* tmpX = list->getObjByIndex(x);
	T* tmpY = list->getObjByIndex(y);
}