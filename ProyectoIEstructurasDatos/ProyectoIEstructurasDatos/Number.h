#pragma once

#include <sstream>
#include <iostream>

using std::ostream;


class Number
{
private:
	int value;

public:
	Number(int);
	int getValue();
	void setValue(int);
	~Number();

};

ostream& operator<<(ostream& o, Number &n);

