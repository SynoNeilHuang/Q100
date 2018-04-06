#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;


int maxDiffofRightSide(const vector<int>& input) {
	if (2 > input.size()) {
		return 0;
	}
	size_t size = input.size();
	int max = input.at(0);
	int maxDiff = -INT_MAX;
	for (int i = 1 ; i < size ; ++i) {
		int curV = input.at(i);
		if ((max - curV) > maxDiff) {
			maxDiff = max - curV;
		}
		if (curV > max) {
			max = curV;
		}
	}
	return maxDiff;
}

int main() {
	int inputA[] = {2,4,1,16,7,5,11,9,20,3};
	vector<int> inputV(inputA, inputA + sizeof(inputA) / sizeof(int));
	cout << maxDiffofRightSide(inputV) << endl;
}
