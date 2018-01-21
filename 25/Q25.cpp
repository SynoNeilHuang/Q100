#include <iostream>
#include <assert.h>
#include <cmath>
#include <stdlib.h>

using namespace std;

int numOf1(int input) {
	assert(input > 0);

	int ret(0);
	int index(0);

	while (input/pow(10, index) > 1) {
		int base = pow(10 ,index);
		int cur_loc = (input / base) % 10;
		int iter(0);
		if (0 == cur_loc) {
			iter = (input / (base * 10)) * base;
		} else if (1 == cur_loc) {
			iter = ((input / (base * 10)) * base) + (input % base + 1);
		} else {
			iter = ((input / (base * 10)) + 1) * base;
		}
		ret += iter;
		++index;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	if (!argv[1]) {
		cout << "should enter some value" << endl;
		exit(1);
	}
	cout << numOf1(atoi(argv[1])) << endl;
}
