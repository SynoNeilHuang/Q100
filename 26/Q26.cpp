#include <iostream>

using namespace std;

unsigned int sumOfSeq(unsigned int small, unsigned int big) {
	unsigned int ret(0);
	for (int i = small; i <= big ; ++i) {
		ret += i;
	}
	return ret;
}

void seqOfSum(unsigned int n) {
	if(n < 3)
		return;
	unsigned int small = 1, big = 2;

	while(small <= (n+1)/2) {
		unsigned int sum = sumOfSeq(small, big);
		if (sum < n) {
			++big;
		} else if (sum > n) {
			++small;
		} else {
			for (int i = small ; i <= big ; ++i) {
				cout << i << " ";
			}
			cout << endl;
			++small;
		}
	}
}

int main (int argc, char* argv[]) {
	if (argc < 2) {
		cout << "enter number" << endl;
		exit(1);
	}
	seqOfSum(stoi(argv[1]));
}
