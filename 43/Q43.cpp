#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <iomanip>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

void diceRecursive(int n, int tmpSum, unordered_map<int, int>& count) {
	if ( 1 == n ) {
		for ( int i = 1 ; i <= 6 ; ++i) {
			++count[tmpSum+i];
		}
	} else {
		for ( int i = 1 ; i <= 6 ; ++i) {
			diceRecursive(n - 1, tmpSum + i, count);
		}
	}
}

void diceOfN(int n) {
	if (0 > n) {
		return;
	}
	unordered_map<int, int> count;
	diceRecursive(n, 0, count);
	//int allCount = pow(6, n);
	//for (int i = n; i <= 6 * n ; ++i) {
	//	cout << "point[" << i  << "] : " << (static_cast<double>(count[i] * 100) / allCount) << "%" << endl;
	//}
	for(int i = n ; i <= 6*n ; ++i) {
		cout << count[i] << " ";
	}
	cout << endl;
}
void diceOfN2(int n) {
	if (0 > n) {
		return;
	}
	vector<int> count(7*n, 0);
	for (int diceIdx = 1 ; diceIdx <= n ; ++diceIdx) {
		if (1 == diceIdx) {
			for (int i = 0 ; i < 6 ; ++i) {
				count[i] = 1;
			}
			continue;
		}
		vector<int> lastCount(6*diceIdx , 0);
		for(int pIdx = diceIdx ; pIdx <= (6*diceIdx) ; ++pIdx) {
			//count[pIdx,2] = count[pIdx-1, 1] + .... + count[pIdx-6, 1];
			int tmp(0);
			for (int last = 1 ; last <= 6 ; ++last) {
				int idx = pIdx - last;
				if (0 < idx && idx >= (diceIdx - 1)) {
					tmp += count[idx - 1];
				}
			}
			lastCount[pIdx - 1] = tmp;
		}
		for (int i = diceIdx ; i <= (6 *diceIdx) ; ++i) {
			count[i-1] = lastCount[i - 1];
		}
	}
	for (int i = n ; i <= 6*n ; ++i) {
		cout << count[i-1] << " ";
	}
	cout << endl;
	//int allCount = pow(6, n);
	//for (int i = n; i <= 6 * n ; ++i) {
	//	cout << "point[" << i  << "] : " << (static_cast<double>(count[i - 1] * 100) / allCount) << "%" << endl;
	//}
}

int main(int argc, char* argv[]) {
	if ( argc < 3 ) {
		cout << "enter a number" << endl;
		return 1;
	}
	int a = atoi(argv[1]);
	int n = atoi(argv[2]);
	if (1 == a)
		diceOfN(n);
	else
		diceOfN2(n);
}
