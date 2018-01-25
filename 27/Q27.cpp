#include <iostream>

using namespace std;

typedef struct _BSTNode {
	_BSTNode *left;
	_BSTNode *right;
	int value;
} BSTNode;

int depthOfBST(BSTNode *root) {

	if (!root)
		return 0;
	int dLeft = depthOfBST(root->left);
	int dRight = depthOfBST(root->right);
	return dLeft > dRight ? (dLeft + 1) : (dRight + 1);
}

int main (int argc, char* argv[]) {
}
