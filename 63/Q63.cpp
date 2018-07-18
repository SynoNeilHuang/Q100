#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

int lastBitOf1(int number) {
    return number & ~(number-1);
}

void getTwoUnique(vector<int>::iterator begin, vector<int>::iterator end, vector<int>& unique) {
    int xorResult = 0;
    for (auto iter = begin ; iter != end ; ++iter) {
	xorResult ^= *iter;
    }

    int diff = lastBitOf1(xorResult);

    int first = 0;
    int second = 0;

    for (auto iter = begin ; iter != end ; ++iter) {
	if (diff & *iter) {
	    first ^= *iter;
	} else {
	    second ^= *iter;
	}
    }
    unique.emplace_back(first);
    unique.emplace_back(second);
}

void getThreeUnique(vector<int>& numbers, vector<int>& unique) {
    if (numbers.size() < 3) {
	return;
    }
    int xorResult = 0;
    for (const auto& val : numbers) {
	xorResult ^= val;
    }

    int flags = 0;
    for (const auto& val : numbers) {
	flags ^= lastBitOf1(xorResult ^ val);
    }
    flags = lastBitOf1(flags); // f(f(x^a) ^ f(x^b) ^ f(x^c))

    // get first unique number
    int first = 0;
    for (const auto& val : numbers) {
	if (lastBitOf1(val ^ xorResult) == flags) {
	    first ^= val;
	}
    }
    unique.emplace_back(first);

    // move the first unique number to the end of array
    for (int i = 0 ; i < numbers.size() ; ++i) {
	if (numbers.at(i) == first) {
	    swap(numbers.at(i), numbers.back());
	    break;
	}
    }
    getTwoUnique(numbers.begin(), numbers.end()-1, unique);
}

int main() {
    vector<int> input = {1,1,2,2,3,3,4,4,5,6,6,7,8,8,9,10,10,11,11};
    vector<int> ret;
    getThreeUnique(input, ret);
    for (const auto& val : ret) {
	cout << val << " ";
    }
    cout << endl;
}
