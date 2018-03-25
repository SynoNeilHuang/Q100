#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

const int xSize = 5;
const int ySize = 4;
void clockWiselyPrint(int entryX, int entryY, int LUx, int LUy, int RDx, int RDy, int (&matrix)[xSize][ySize]) {
	int i = entryX;
	int j = entryY;
	if ((LUx < RDx) && (LUy > RDy)) {
		cout << endl;
		return;
	}
	if (i == LUx && j == LUy) { /* left up, should X plus */
		for (; i <= RDx ; ++i) {
			cout << matrix[i][j] << " ";
		}
		++LUy;
		entryX = i - 1;
		entryY = j + 1;
	} else if (i == RDx && j == RDy) { /* right down, should X minus */
		for (; i >= LUx ; --i) {
			cout << matrix[i][j] << " ";
		}
		--RDy;
		entryX = i + 1;
		entryY = j - 1;
	} else if (i == RDx && j == LUy) { /* right up, should Y plus */
		for (; j <= RDy ; ++j) {
			cout << matrix[i][j] << " ";
		}
		--RDx;
		entryX = i - 1;
		entryY = j - 1;
	} else if (i == LUx && j == RDy) { /* left down, should Y minus */
		for (; j >= LUy ; --j) {
			cout << matrix[i][j] << " ";
		}
		++LUx;
		entryX = i + 1;
		entryY = j + 1;
	}
	clockWiselyPrint(entryX, entryY, LUx, LUy, RDx, RDy, matrix);
	return;
}

int main() {
	int array[xSize][ySize] = {0x0};
	int val = 1;
	for (int y = 0 ; y < ySize ; ++y) {
		for (int x = 0 ; x < xSize ; ++x, ++val) {
			array[x][y] = val;
		}
	}

	for (int y = 0 ; y < ySize ; ++y) {
		for (int x = 0 ; x < xSize ; ++x) {
			cout << array[x][y] << " ";
		}
		cout << endl;
	}
	clockWiselyPrint(0, 0, 0, 0, xSize - 1, ySize - 1, array);
}
