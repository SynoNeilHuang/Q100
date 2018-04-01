#include <iostream>

using std::cout;
using std::endl;

int addWithoutArithmetic(int num1, int num2) {
	if (!num1 || !num2) {
		return num1 ? num1 : num2;
	}

	int num = num1 ^ num2;
	int carry = (num1 & num2) << 1;
	return addWithoutArithmetic(num, carry);
}

int main () {
	cout << addWithoutArithmetic(5 , 10) << endl;
}
