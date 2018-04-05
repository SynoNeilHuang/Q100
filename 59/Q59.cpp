#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void output_combination(const string& input, int index, vector<char> result) {
	if (index == (input.size() - 1)) {
		result.push_back(input.at(index));
		for (const auto index : result)
			cout << index;
		cout << endl;
		result.pop_back();
		if (!result.empty()) {
			for (const auto index : result)
				cout << index;
			cout << endl;
		}
		return;
	}

	output_combination(input, index + 1, result);
	result.push_back(input.at(index));
	output_combination(input, index + 1, result);
}

void printAllcombination(const string& input, vector<char> result) {
	output_combination(input, 0 , result);
}

int main() {
	string input("abcdefg");
	vector<char> result;
	printAllcombination(input, result);
}

