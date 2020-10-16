
#include <iostream>

#include "Node.h"
#include "Number.h"
#include "Heap.h"
#include "DoubleList.h"
#include "PriorityQueue.h"

using std::cout;
using std::endl;

int main() {

	Number num(17);
	Number num1(28);
	Number num2(15);
	Number num3(20);
	Number num4(32);
	Number num5(7);
	Number num6(21);

	PriorityQueue<Number>* pQueue = new PriorityQueue<Number>();

	pQueue->insert(&num);
	pQueue->insert(&num1);
	pQueue->insert(&num2);
	pQueue->insert(&num3);
	pQueue->insert(&num4);
	pQueue->insert(&num5);
	pQueue->insert(&num6);

	cout << pQueue->toString();

	//// PRUEBA #3 monticulo y sus funciones

	//Number num(17);
	//Number num1(28);
	//Number num2(15);
	//Number num3(20);
	//Number num4(32);
	//Number num5(7);
	//Number num6(21);

	//Heap<Number>* monticulo = new Heap<Number>();


	//monticulo->insert(&num);
	//monticulo->insert(&num1);
	//monticulo->insert(&num2);
	//monticulo->insert(&num3);
	//monticulo->insert(&num4);
	//monticulo->insert(&num5);
	//monticulo->insert(&num6);

	//cout << *monticulo->deleteMax();

	//cout << monticulo->toString();

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	////Prueba: Comprobacion de funciones correctas de la lista doblemente enlazada

	//Number num(17);
	//Number num1(28);
	//Number num2(15);
	//Number num3(12);

	//DoubleList<Number>* dList = new DoubleList<Number>();

	//dList->insert(&num);
	//dList->insert(&num1);
	//dList->insert(&num2);
	//dList->insert(&num3);
	//
	//dList->deleteInfo(&num1);

	//dList->swapInfoByIndex(2, 0);

	//cout << dList->getLastIndex();

	////cout << dList->toString();

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	// Prueba correcta: creacion de nodos
	/*Number num(17);

	Node<Number>* n = new Node<Number>(&num, nullptr);

	cout << *n->getInfo();*/
	
	return 0;
}