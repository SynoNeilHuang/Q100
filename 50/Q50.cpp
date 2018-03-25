#include <iostream>
#include <vector>
#include <memory>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

template <typename T>
struct TreeNode {
	T value;
	shared_ptr<TreeNode> m_pLeft;
	shared_ptr<TreeNode> m_pRight;
	TreeNode(T val) : value(val) {}
};

bool CompareTree(const shared_ptr<TreeNode<int>>& pRoot, const shared_ptr<TreeNode<int>>& pCompRoot) {
	if (!pCompRoot) {
		return true;
	}
	if (!pRoot && pCompRoot) {
		return false;
	}

	if (pRoot->value == pCompRoot->value) {
		bool result = true;
		if (pCompRoot->m_pLeft) {
			result = result && CompareTree(pRoot->m_pLeft, pCompRoot->m_pLeft);
		}
		if (pCompRoot->m_pRight) {
			result = result && CompareTree(pRoot->m_pRight, pCompRoot->m_pRight);
		}
		return result;
	} else {
		return false;
	}
}

bool hasSubTree(const shared_ptr<TreeNode<int>>& pRoot, const shared_ptr<TreeNode<int>>& pCompRoot) {
	if (pRoot == nullptr) {
		return false;
	}

	if (pCompRoot == nullptr) {
		return true;
	}

	bool result = false;
	if (pRoot->value == pCompRoot->value) {
		result = CompareTree(pRoot, pCompRoot);
	}

	if (!result && pRoot->m_pLeft) {
		result = hasSubTree(pRoot->m_pLeft, pCompRoot);
	}

	if (!result && pRoot->m_pRight) {
		result = hasSubTree(pRoot->m_pRight, pCompRoot);
	}

	return result;
}

int main() {
	shared_ptr<TreeNode<int>> pRoot = make_shared<TreeNode<int>>(11);
	shared_ptr<TreeNode<int>> pLeft = make_shared<TreeNode<int>>(12);
	shared_ptr<TreeNode<int>> pRight = make_shared<TreeNode<int>>(13);
	pRoot->m_pLeft = pLeft;
	pRoot->m_pRight = pRight;
	shared_ptr<TreeNode<int>> pLeftLeft = make_shared<TreeNode<int>>(14);
	shared_ptr<TreeNode<int>> pLeftRight = make_shared<TreeNode<int>>(15);
	shared_ptr<TreeNode<int>> pRightLeft = make_shared<TreeNode<int>>(16);
	shared_ptr<TreeNode<int>> pRightRight = make_shared<TreeNode<int>>(17);

	pLeft->m_pLeft = pLeftLeft;
	pLeft->m_pRight = pLeftRight;
	pRight->m_pLeft = pRightLeft;
	pRight->m_pRight = pRightRight;

	shared_ptr<TreeNode<int>> pCRoot = make_shared<TreeNode<int>>(13);
	shared_ptr<TreeNode<int>> pCLeft = make_shared<TreeNode<int>>(16);
	shared_ptr<TreeNode<int>> pCRight = make_shared<TreeNode<int>>(17);
	pCRoot->m_pLeft = pCLeft;
	pCRoot->m_pRight = pCRight;

	cout << hasSubTree(pRoot, pCRoot) << endl;

}
