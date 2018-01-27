#include <iostream>
#include <string>

using namespace std;

void swap(char &ch1, char &ch2) {
	ch1 ^= ch2 ^= ch1 ^= ch2;
}

void permuataionOfChar(string &input, size_t cur, size_t size) {
	if (cur == (size - 1)) {
		cout << " " << input << endl;
		return;
	}

	for (int i = cur ; i < size ; ++i) {
		if (cur != i)
			swap(input[cur], input[i]);
		permuataionOfChar(input, cur + 1, size);
		if (cur != i)
			swap(input[cur], input[i]);
	}
}

int main (int argc, char* argv[]) {
	string input("abc");
	permuataionOfChar(input, 0, input.length());
}
