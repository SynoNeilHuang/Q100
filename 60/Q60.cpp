#include <iostream>

using std::cout;
using std::endl;

struct Node {
	Node *pLeft;
	Node *pRight;
	int value;
};

int hight(Node* root) {
	if (!root)
		return 0;
	int Left = hight(root->pLeft);
	int Right = hight(root->pRight);
	return (Left > Right) ? Left + 1 : Right + 1;
}

bool isBalance(Node* root) {
	if (!root) {
		return true;
	}
	int Left = hight(root->pLeft);
	int Right = hight(root->pRight);
	int diff = Left > Right ? Left - Right : Right - Left;
	if (diff > 1)
		return false;

	return isBalance(root->pLeft) && isBalance(root->pRight);
}

int main() {
	Node* root = new Node();
	cout << isBalance(root) << endl;
}
