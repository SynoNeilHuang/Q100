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
	TreeNode(T value) : value(value) {}
};

template <typename T>
bool FindNode(const shared_ptr<TreeNode<T>> node, const shared_ptr<TreeNode<T>> pHead, vector<shared_ptr<TreeNode<T>>>& path) {
	if (nullptr == pHead) {
		return false;
	}
	if (pHead->value == node->value) {
		path.push_back(pHead);
		return true;
	} else {
		if (FindNode(node, pHead->m_pLeft, path) ||
		     FindNode(node, pHead->m_pRight, path)) {
			path.push_back(pHead);
			return true;
		} else {
			return false;
		}
	}
}

template <typename T>
shared_ptr<TreeNode<T>> getCommonParent(const shared_ptr<TreeNode<T>>& node1,
				const shared_ptr<TreeNode<T>>& node2,
				const shared_ptr<TreeNode<T>>& pHead) {
	if (nullptr == node1 || nullptr == node2) {
		return nullptr;
	}
	vector<shared_ptr<TreeNode<T>>> Node1path;
	vector<shared_ptr<TreeNode<T>>> Node2path;
	FindNode(node1, pHead, Node1path);
	FindNode(node2, pHead, Node2path);
	for (const auto& idx : Node1path) {
		cout << idx->value << " ";
	}
	cout << endl;
	for (const auto& idx : Node2path) {
		cout << idx->value << " ";
	}
	cout << endl;
	shared_ptr<TreeNode<T>> CmnNode(nullptr);
	while(Node1path.back() == Node2path.back()) {
		CmnNode = Node1path.back();
		Node1path.pop_back();
		Node2path.pop_back();
	}
	return CmnNode;
}

int main() {
	shared_ptr<TreeNode<int>> pHead = make_shared<TreeNode<int>>(10);
	shared_ptr<TreeNode<int>> pLeft = make_shared<TreeNode<int>>(20);
	shared_ptr<TreeNode<int>> pRight = make_shared<TreeNode<int>>(30);
	shared_ptr<TreeNode<int>> pLeftLeft = make_shared<TreeNode<int>>(40);
	shared_ptr<TreeNode<int>> pLeftRight = make_shared<TreeNode<int>>(50);
	shared_ptr<TreeNode<int>> pRightLeft = make_shared<TreeNode<int>>(60);
	shared_ptr<TreeNode<int>> pRightRight = make_shared<TreeNode<int>>(70);
	pHead->m_pLeft = pLeft;
	pHead->m_pRight = pRight;
	pLeft->m_pLeft = pLeftLeft;
	pLeft->m_pRight = pLeftRight;
	pRight->m_pLeft = pRightLeft;
	pRight->m_pRight = pRightRight;
	shared_ptr<TreeNode<int>> pRet = getCommonParent(pLeftLeft, pLeftRight, pHead);
	cout << pRet->value << endl;
}
