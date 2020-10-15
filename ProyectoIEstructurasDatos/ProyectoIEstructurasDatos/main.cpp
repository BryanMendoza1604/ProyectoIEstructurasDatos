
#include <iostream>

#include "Node.h"
#include "Number.h"
#include "DoubleList.h"

using std::cout;


int main() {


	//Prueba: Comprobacion de funciones correctas de la lista doblemente enlazada

	Number num(17);
	Number num1(28);
	Number num2(15);
	Number num3(12);

	DoubleList<Number>* dList = new DoubleList<Number>();

	dList->insert(&num);
	dList->insert(&num1);
	dList->insert(&num2);
	dList->insert(&num3);

	dList->swapInfoByIndex(0, 1);

	cout << dList->toString();


	// Prueba correcta: creacion de nodos
	/*Number num(17);

	Node<Number>* n = new Node<Number>(&num, nullptr);

	cout << *n->getInfo();*/
	
	return 0;
}