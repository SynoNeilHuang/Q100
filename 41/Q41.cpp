#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

bool combineSmall(const vector<int>& input, string& ret) {
	if (input.size() > 2) {
		return false;
	}

	vector<string> vInput;
	for (const auto& idx : input) {
		string intToStr;
		stringstream ss;
		ss << idx;
		ss >> intToStr;
		vInput.push_back(intToStr);
	}
	string str01(vInput[0] + vInput[1]);
	string str10(vInput[1] + vInput[0]);
	for(int i = 0 ; i < str01.size() ; ++i) {
		if (str01[i] == str10[i]) {
			continue;
		} else {
			str01[i] < str10[i] ? ret = str01 : ret = str10;
			break;
		}
	}
	return true;
}

int main() {
	vector<int> input;
	string ret;
	input.push_back(32);
	input.push_back(321);
	combineSmall(input, ret);
	cout << ret << endl;
}
