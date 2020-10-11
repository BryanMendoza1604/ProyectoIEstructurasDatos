#include "Number.h"

Number::Number(int value) : value(value) {

}

int Number::getValue() {
	return value;
}

void Number::setValue(int value) {
	this->value = value;
}

Number::~Number() {

}

ostream& operator<<(ostream& o,  Number &n) {
	o << n.getValue();

	return o;
}