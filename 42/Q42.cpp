#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


int findMin(const vector<int>& input) {
	if (input.size() < 1) {
		return 0;
	} else if ( input.size() == 1) {
		return input.back();
	}

	int big = 0;
	int small = input.size() - 1;

	if (input[big] <= input[small]) {
		return input[big];
	}
	while (1 < (small - big)) {
		int mid = (big + small) / 2;
		if (input[mid] <= input[small]) {
			small = mid;
		} else if (input[mid] > input[big]) {
			big = mid;
		}
	}
	return input[small];
}

int main() {
	int aInput[7] = {4, 5, 6, 7, 1, 2, 3};
	vector<int> vInput(aInput, aInput + sizeof(aInput) / sizeof(int));
	cout << findMin(vInput) << endl;
}

