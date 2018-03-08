#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

double Power(double base, int exp) {
	if (0 == base || 1 == base) {
		return base;
	}

	double result = 1.0;
	if (0 < exp) {
		for (int i = 0 ; i < exp ; ++i) {
			result *= base;
		}
	} else if (0 > exp) {
		for (int i = 0 ; i < abs(exp) ; ++i) {
			result /= base;
		}
	}
	return result;

}


double PowerArray(const double& base, const int& exp) {
	if (0 == base || 1 == base) {
		return base;
	}

	int absExp = abs(exp);
	double baseMul[32] = { 0x0 };
	double CurResult(1);
	int numberOf1(0);
	for (int i = 0 ; 0 != absExp ; ++i, absExp = (absExp >> 1)) {
		++numberOf1;
		if (0 == i) {
			CurResult *= base;
		} else {
			CurResult *= CurResult;
		}
		if (absExp & 0x1) {
			baseMul[i] = CurResult;
		}
	}

	double ret(1);
	for(int i = 0, Cnt1 = 0 ; i < 32 && Cnt1 < numberOf1 ; ++i) {
		if (baseMul[i] != 0) {
			ret *= baseMul[i];
			++Cnt1;
		}
	}
	if (0 > exp) {
		ret = 1 / ret;
	}
	return ret;

}
int main() {
	cout << Power(2, 20) << endl;
}
