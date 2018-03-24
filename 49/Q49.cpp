#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::unordered_map;
using std::make_pair;

template <typename T>
struct ComplexNode {
	T m_value;
	shared_ptr<ComplexNode> m_pNext;
	shared_ptr<ComplexNode> m_pSibling;
};

shared_ptr<ComplexNode<int>> Clone(shared_ptr<ComplexNode<int>> pHead) {

	if (!pHead)
		return nullptr;

	unordered_map<shared_ptr<ComplexNode<int>>, shared_ptr<ComplexNode<int>>> mapping;
	shared_ptr<ComplexNode<int>> it = pHead;
	shared_ptr<ComplexNode<int>> cloneHead = make_shared<ComplexNode<int>>();
	cloneHead->m_value = it->m_value;
	cloneHead->m_pSibling = it->m_pSibling;
	shared_ptr<ComplexNode<int>> cloneIt = cloneHead;
	mapping.insert(make_pair(it,cloneIt));

	for (shared_ptr<ComplexNode<int>> iter = pHead->m_pNext ; iter != nullptr ; iter = iter->m_pNext) {
		shared_ptr<ComplexNode<int>> node = make_shared<ComplexNode<int>>();
		mapping.insert(make_pair(iter,node));
		node->m_value = iter->m_value;
		node->m_pSibling = iter->m_pSibling;
		cloneIt->m_pNext = node;
		cloneIt = cloneIt->m_pNext;
	}

	cloneIt = cloneHead;
	for(shared_ptr<ComplexNode<int>> iter = cloneIt ; iter != nullptr ; iter = iter->m_pNext) {
		if (iter->m_pSibling) {
			iter->m_pSibling = mapping[iter->m_pSibling];
		}
	}
	return cloneHead;
}

shared_ptr<ComplexNode<int>> CloneN(shared_ptr<ComplexNode<int>> pHead) {
	shared_ptr<ComplexNode<int>> iter = pHead;
	while (iter) {
		shared_ptr<ComplexNode<int>> node = make_shared<ComplexNode<int>>();
		node->m_value = iter->m_value;
		node->m_pSibling = iter->m_pSibling;
		node->m_pNext = iter->m_pNext;
		iter->m_pNext = node;
		iter = node->m_pNext;
	}
	iter = pHead;
	shared_ptr<ComplexNode<int>> RetHead = pHead->m_pNext;
	for (shared_ptr<ComplexNode<int>> it = RetHead ; it != nullptr ;
			(it->m_pNext != nullptr) ? it = it->m_pNext->m_pNext : it = nullptr)
	{
		it->m_pSibling = it->m_pSibling->m_pNext;
	}

	for (shared_ptr<ComplexNode<int>> RetIt = RetHead ; iter != nullptr ; iter = iter->m_pNext, RetIt = RetIt->m_pNext) {
		iter->m_pNext = iter->m_pNext->m_pNext;
		RetIt->m_pNext = RetIt->m_pNext ? RetIt->m_pNext->m_pNext : nullptr;
	}
	return RetHead;
}

int main() {

}
