
#include <iostream>

#include "Node.h"
#include "Number.h"

using std::cout;


int main() {
	Number num(17);

	Node<Number>* n = new Node<Number>(&num, nullptr);

	cout << *n->getInfo();
	
	return 0;
}