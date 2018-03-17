#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int getMostCount(const vector<int>& input) {
	int number(0);
	int count(0);
	for (const auto& idx : input) {
		if (0 == count) {
			number = idx;
			count = 1;
		} else {
			if (number == idx) {
				++count;
			} else {
				--count;
			}
		}
	}
	return number;
}

int main() {
	int aInput[] = { 1, 2, 3, 3, 5, 3,1, 3, 2,2,3,3,3,3,3,3,5,4};
	vector<int> input(aInput, aInput + sizeof(aInput) / sizeof(int));
	cout << getMostCount(input) << endl;
}
