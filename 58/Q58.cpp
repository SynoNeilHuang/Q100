#include <iostream>

using std::cout;
using std::endl;

const static int x_size = 8;
const static int y_size = 8;

void print(int checkerBoard[x_size][y_size]) {
	cout << endl;
	for (int y = 0 ; y < y_size ; ++y) {
		for (int x = 0 ; x < x_size ; ++x) {
			cout << checkerBoard[x][y] << " ";
		}
		cout << endl;
	}
}

void eightQueen(int checkerBoard[x_size][y_size], int x, int& count) {
	if (x == (x_size -1)) {
		for (int y = 0 ; y < y_size ; ++y) {
			if (checkerBoard[x][y] == 0) {
				++count;
			}
		}
		return;
	}
	for (int y = 0 ; y < y_size ; ++y) {
		if (checkerBoard[x][y] == 0) {
			checkerBoard[x][y] = x + 1;
			for (int z = x ; z < x_size ; ++z) {
				if (checkerBoard[z][y] == 0)
					checkerBoard[z][y] = x + 1;
			}
			for (int z = x, w = y ; w >= 0 && z < x_size ; --w, ++z) {
				if (checkerBoard[z][w] == 0)
					checkerBoard[z][w] = x + 1;
			}
			for (int z = x, w = y ; w < y_size && z < x_size ; ++w, ++z) {
				if (checkerBoard[z][w] == 0)
					checkerBoard[z][w] = x + 1;
			}
			eightQueen(checkerBoard, x+1, count);
			for (int z = x; z < x_size ; ++z) {
				if (checkerBoard[z][y] == (x + 1))
					checkerBoard[z][y] = 0;
			}
			for (int z = x, w = y ; w >= 0 && z < x_size ; --w, ++z) {
				if (checkerBoard[z][w] == (x + 1))
					checkerBoard[z][w] = 0;
			}
			for (int z = x, w = y ; w < y_size && z < x_size ; ++w, ++z) {
				if (checkerBoard[z][w] == (x + 1))
					checkerBoard[z][w] = 0;
			}
		}
	}
}

bool check(int checkerBoard[x_size]) {
	for (int x = 0 ; x < x_size ; ++x) {
		for (int y = x + 1 ; y < x_size ; ++y) {
			if ( y - x == checkerBoard[y] - checkerBoard[x]
					|| x - y == checkerBoard[y] - checkerBoard[x]) {
				return false;
			}
		}
	}
	return true;
}

void eightQueen1D(int checkerBoard[x_size], int x, int& count) {
	if (x == (x_size - 1)) {
		if (check(checkerBoard)) {
			++count;
		}
	}

	for (int index = x ; index < x_size ; ++index) {
		int tmp = checkerBoard[index];
		checkerBoard[index] = checkerBoard[x];
		checkerBoard[x] = tmp;

		eightQueen1D(checkerBoard, x + 1, count);

		tmp = checkerBoard[index];
		checkerBoard[index] = checkerBoard[x];
		checkerBoard[x] = tmp;
	}
}

int main () {
	int checkerBoard[x_size][y_size] = { 0x0 };
	int count(0);
	int count1D(0);
	int checkerBoard1D[x_size] = { 0x0 };
	for (int i = 0 ; i < x_size ; ++i) {
		checkerBoard1D[i] = i;
	}
	eightQueen(checkerBoard, 0, count);
	eightQueen1D(checkerBoard1D, 0, count1D);
	cout << count << endl;
	cout << count1D << endl;
}
