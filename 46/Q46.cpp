#include <iostream>
#include <string>
#include <stack>
#include <algorithm>


using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::max;

bool isSymmetric(const string& input) {
	int iSize = input.size();
	if (iSize < 2) {
		return false;
	}
	int mid(iSize / 2);
	stack<char> cStack;

	for (int i = 0 ; i < mid ; ++i) {
		cStack.push(input.at(i));
	}

	for (int i = (iSize & 1) ? mid + 1 : mid ; i < iSize ; ++i) {
		if (input.at(i) == cStack.top()) {
			cStack.pop();
		} else {
			break;
		}
	}
	return cStack.empty();
}

bool isSymmetrical(const string& input) {
	int iSize(input.size());
	if (iSize < 2)
		return false;

	int mid(iSize / 2);
	for (int i = 0 ; i < mid ; ++i) {
		if (input.at(i) != input.at(iSize - i - 1)) {
			return false;
		}
	}
	return true;
}

int getLongestSymmtricalSizeN3(const string& input) {
	if (input.size() < 2) {
		return 0;
	}

	int SymmetricSize(1);
	int iSize = input.size();
	for (int i = 0 ; i < iSize ; ++i) {
		for (int j = 2 ; (i + j) < iSize ; ++j) {
			if(isSymmetrical(input.substr(i, j))) {
				if (j > SymmetricSize) {
					SymmetricSize = j;
				}
			}
		}
	}
	return SymmetricSize;
}

int getLongestSymmtricalSizeN32(const string& input) {
	int iSize = input.size();

	int SymCnt[iSize][iSize] = { 0x0 };
	for (int i = 0 ; i < iSize ; ++i) {
		for (int j = 0 ; j < iSize ; ++j) {
			SymCnt[i][j] = 0;
		}
	}
	for (int i = 0 ; i < (iSize - 2) ; ++i) {
		if (isSymmetrical(input.substr(i, 2))) {
			SymCnt[i][i+1] = 2;
		}
	}
	for (int i = 3 ; i <= iSize ; ++i) {
		for (int j = 0 ; j < (iSize - i + 1) ; ++j) {
			int CurSize(0);
			if(isSymmetrical(input.substr(j, i))) {
				CurSize = i;
			}
			SymCnt[j][j+i-1] = max(max(SymCnt[j][j+i-2], SymCnt[j+1][j+i-1]) , CurSize);
		}
	}
	return SymCnt[0][iSize-1];
}

int getLongestSymmtricalSizeN2(const string& input) {
	if (input.size() < 2) {
		return 0;
	}
	int iSize = input.size();

	int MaxSize(0);
	for (int i = 0 ; i < (iSize - 1) ; ++i) {
		int begin = i;
		int end = i+1;
		while (begin >= 0 && end < iSize) {
			if (input.at(begin) == input.at(end)) {
				--begin;
				++end;
			} else {
				break;
			}
		}
		MaxSize = (end - begin - 1) > MaxSize ? (end - begin - 1) : MaxSize;
	}
	for (int i = 0 ; i < iSize ; ++i) {
		int begin = i - 1;
		int end = i + 1;
		while(begin >= 0 && end < iSize) {
			if (input.at(begin) == input.at(end)) {
				--begin;
				++end;
			} else {
				break;
			}
		}
		MaxSize = (end - begin - 1) > MaxSize ? (end - begin - 1) : MaxSize;
	}
	return MaxSize;
}

int main() {
	string input("abdeedcc");
	cout << isSymmetrical(input) << endl;
	cout << getLongestSymmtricalSizeN3(input) << endl;
	cout << getLongestSymmtricalSizeN32(input) << endl;
	cout << getLongestSymmtricalSizeN2(input) << endl;
}
