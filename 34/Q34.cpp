#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

template <typename T>
vector<T> findOnce(vector<T> input) {
	unordered_map<T, unsigned int> count;
	for ( const auto& idx : input ) {
		++count[idx];
	}
	vector<T> ret;
	for ( const auto& idx : count ) {
		if ( idx.second == 1 ) {
			ret.push_back(idx.first);
		}
	}
	return ret;
}

template
vector<int> findOnce<int>(vector<int>);

unsigned int FindFirstBit1(int result) {
	int shiftCnt = 0;
	while (((result & 0x1) == 0) && (shiftCnt < 32)) {
		result = result >> 1;
		++shiftCnt;
	}
	return shiftCnt;
}

void FindNumAppearOnce(int data[], int length, int &num1, int &num2) {
	if (length < 2) {
		return;
	}

	int resultXor = 0;
	for (int i = 0 ; i < length ; ++i) {
		resultXor ^= data[i];
	}

	unsigned int idxOf1 = FindFirstBit1(resultXor);

	num1 = num2 = 0;
	for (int i = 0 ; i < length ; ++i) {
		int shiftNum = (data[i] >> idxOf1);
		if ( (shiftNum & 0x1) == 1 ) {
			num1 ^= data[i];
		} else {
			num2 ^= data[i];
		}
	}
}

int main() {
	int inputA[10] = {4, 4, 6, 7, 8, 6, 7, 3, 5, 5};
	vector<int> inputV(inputA, inputA + sizeof(inputA) / sizeof(int));
	vector<int> ret = findOnce<int>(inputV);
	int ret1 , ret2;
	FindNumAppearOnce(inputA, 10, ret1, ret2);
	cout << ret1 << " " << ret2 << endl;
	return 0;
}
