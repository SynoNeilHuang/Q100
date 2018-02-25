#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::cout;
using std::endl;

bool nthUglyNumber(int input, vector<int>& ret) {
	if (input <= 0) {
		return false;
	}

	ret.push_back(1);
	if (input == 1) {
		return true;
	}

	int idx2(0), idx3(0), idx5(0);
	while(ret.size() < input) {
		ret.push_back(min(ret[idx2] * 2, min(ret[idx3] * 3, ret[idx5] * 5)));
		if (ret.back() == ret[idx2] * 2) ++idx2;
		if (ret.back() == ret[idx3] * 3) ++idx3;
		if (ret.back() == ret[idx5] * 5) ++idx5;
	}
	return true;
}

int main() {
	vector<int> ret;
	nthUglyNumber(30, ret);
	for (const auto& idx : ret) {
		cout << idx << " ";
	}
	cout << endl;
}
