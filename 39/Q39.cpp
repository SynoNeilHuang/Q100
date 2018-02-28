#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T>
void addToBottom(vector<T>& stack, const T& back) {
	if ( stack.empty() ) {
		stack.push_back(back);
	} else {
		T top = stack.back();
		stack.pop_back();
		addToBottom(stack, back);
		stack.push_back(top);
	}
}

template <typename T>
void reverseStack(vector<T>& input) {
	if (input.empty()) {
		return;
	}
	int back = input.back();
	input.pop_back();
	reverseStack(input);
	addToBottom<T>(input, back);
}

template void reverseStack<int>(vector<int>& input);
template void addToBottom<int>(vector<int>& input, const int& back);

int main() {
	int array[5] = {1, 2, 3, 4, 5};
	vector<int> input( array , array + sizeof(array)/sizeof(int));


	for (const auto& idx : input) {
		cout << idx << " ";
	}
	cout << endl;
	reverseStack(input);
	for (const auto& idx : input) {
		cout << idx << " ";
	}
	cout << endl;

}
