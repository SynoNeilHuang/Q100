#include <iostream>
#include <math.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

void NNumber(int input) {
	if (input < 1) {
		return;
	}
	long long int number = pow(10, input);
	for (long long int i = 1 ; i < number ; ++i) {
		cout << i << " ";
	}
	cout << endl;
}

void print(const string& output) {
	int count(0);
	int size = output.size();
	while(count < size) {
		if (output[count] != '0') {
			break;
		}
		++count;
	}
	cout << output.substr(count) << " ";
}

bool carry(string& output) {
	for (int i = output.size() - 1 ; i >= 0 ; --i) {
		if (output[i] > '9') {
			output[i] = '0';
			if ( i != 0 ) {
				output[i-1] += 1;
			} else {
				return false;
			}
		} else {
			break;
		}
	}
	return true;
}

/* iteration list array of char */
void NNumber2(int input) {
	string output(input, '0');
	while (true) {
		output[input - 1] += 1;
		if (carry(output)) {
			print(output);
		} else {
			cout << endl;
			return;
		}
	}
}

void recursiveList(string& output, int n, int cur_idx) {
	if (cur_idx == n) {
		print(output);
		return;
	}

	for (int i = 0; i < 10; ++i) {
		output[cur_idx] = '0' + i;
		recursiveList(output, n, cur_idx + 1);
	}
}

/* recursive list array of char */
void NNumber3(int input) {
	string output(input, '0');
	for (int i = 0 ; i < 10 ; ++i) {
		output[0] = '0' + i;
		recursiveList(output, input, 1);
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		NNumber3(atoi(argv[1]));
	} else {
		cout << "enter a number" << endl;
	}
}
