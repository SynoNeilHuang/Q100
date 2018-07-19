#include <iostream>
using std::cout;
using std::endl;
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int postorderDFS(TreeNode* root, int& left, int& right) {
    if (nullptr == root) return 0;
    if (!root->left && !root->right) {
	return root->val;
    }
    int leftLeft(0);
    int leftRight(0);
    int rightLeft(0);
    int rightRight(0);

    left = postorderDFS(root->left, leftLeft, leftRight);
    right = postorderDFS(root->right, rightLeft, rightRight);
    return max(root->val + leftLeft + leftRight + rightLeft + rightRight, left + right);
}

int rob(TreeNode* root) {
    int left(0);
    int right(0);
    return postorderDFS(root, left, right);
}

int main() {
    return 0;
}
