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

double PowerRecursive(double base, const int& exp) {
	if (1 == base || 0 == base) {
		return base;
	}

	if (0 == exp) {
		return 1;
	}

	bool negative = false;
	int absExp = abs(exp);
	if (0 > exp) {
		negative = true;
	}

	if (1 == absExp) {
		if (negative)
			return 1/base;
		else
			return base;
	}

	double result(0);
	if (absExp & 0x1) {
		double tmp = PowerRecursive(base, (absExp - 1) >> 1);
		result = base * tmp * tmp;
	} else {
		double tmp = PowerRecursive(base , absExp >> 1);
		result = tmp * tmp;
	}
	if (negative)
		return 1/result;
	else
		return result;
}

int main() {
	cout << PowerRecursive(2, -3) << endl;
}
