#include "Q45.h"
#include <iostream>

using std::cout;
using std::endl;

Singleton* Singleton::getInstance() {
	static Singleton _instance;
	return &_instance;
}

int main() {
	Singleton *s = Singleton::getInstance();
	Singleton *r = Singleton::getInstance();
	cout << s << endl;
	cout << r << endl;
}
