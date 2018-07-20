#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::pow;

int reduce(int val) {
    if (1 == val) return 0;
    int log = log2(val);
    if (val == pow(2, log)) {
	val -= pow(2, log-1);
    } else {
	val -= pow(2, log);
    }
    return reduce(val) == 0 ? 1 : 0;
}

int kthGrammar(int N, int K) {
    return reduce(K);
}

int main() {
    cout << kthGrammar(3, 3) << endl;
    return 0;
}
