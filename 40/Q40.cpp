#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

bool pokerStraight(vector<int>& poker) {
	if (poker.empty()) {
		return false;
	}

	sort(poker.begin(), poker.end());

	int zeroCount(0);

	while(0 == poker.at(zeroCount)) {
		++zeroCount;
	}

	for (int i = zeroCount ; i < 4 ; ++i) {
		if (poker.at(i) == poker.at(i+1)) {
			return false;
		}
	}

	if (4 == (poker.at(4) - poker.at(zeroCount))) {
		return true;
	}
	int NumDiff = poker.at(4) - poker.at(zeroCount);
	if (zeroCount && ((4 - NumDiff) == zeroCount)) {
			return true;
	} else {
		return false;
	}

}

int main() {
	int array[5] = {0 , 2, 4, 3, 7};
	vector<int> input(array, array + sizeof(array) / sizeof(int));
	cout << pokerStraight(input) << endl;

}
