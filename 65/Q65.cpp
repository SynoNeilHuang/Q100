#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::pair;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ret(temperatures.size(), 0);
    if (temperatures.empty()) return ret;
    stack<int> st;

    for (int i = 0 ; i < temperatures.size() ; ++i) {
	while (!st.empty()) {
	    if (temperatures.at(i) > temperatures.at(st.top())) {
		ret.at(st.top()) = i - st.top();
		st.pop();
	    } else {
		break;
	    }
	}
	st.emplace(i);
    }
    return ret;
}

int main() {
    vector<int> input = {73,74, 75, 71, 69, 72, 76,73};
    auto ret = dailyTemperatures(input);
    for (const auto& val : ret) {
	cout << val << " ";
    }
    cout << endl;
}
