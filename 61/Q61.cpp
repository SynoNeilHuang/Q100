#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::max;

int maxDiffofRightSide(const vector<int>& input) {
	if (2 > input.size()) {
		return 0;
	}
	size_t size = input.size();
	int max = input.at(0);
	int maxDiff = INT_MIN;
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

// dp.at(i) : max diff of dp(x) - dp(i) which x < i
int maxDiffofRightSide2(const vector<int>& input) {
    vector<int> dp(input.size(), 0);

    int maxV = input.at(0);
    dp.at(1) = maxV - input.at(1);
    int maxDiff = dp.at(1);
    for (int i = 2; i < input.size() ; ++i) {
	maxV = max(maxV, input.at(i-1));
	dp.at(i) = maxV - input.at(i);
	maxDiff = max(maxDiff, dp.at(i));
    }
    return maxDiff;
}

int main() {
	int inputA[] = {2,4,1,16,7,5,11,9,20,3};
	vector<int> inputV(inputA, inputA + sizeof(inputA) / sizeof(int));
	vector<int> input2 = {60,28,29,49,20};
	cout << maxDiffofRightSide(input2) << endl;
	cout << maxDiffofRightSide2(input2) << endl;
}
