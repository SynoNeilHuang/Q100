#include "Q31.h"
#include <vector>

using std::vector;

void reversePrint(LSTNode* head) {
	vector<int> print;
	LSTNode *iter = head;
	while (iter) {
		print.push_back(iter->m_nKey);
		iter = iter->m_pNext;
	}
	while(!print.empty()) {
		cout << print.back()  << endl;
		print.pop_back();
	}
}

void recurReversePrint(LSTNode* head) {
	if (!head) {
		return;
	}

	recurReversePrint(head->m_pNext);
	cout << head->m_nKey << endl;
	return;
}

int main() {
	LSTList list(10);
	list.add(9);
	list.add(8);
	list.add(7);
	list.add(6);
	list.add(5);
	list.printList();

	recurReversePrint(list.getHEAD());
	reversePrint(list.getHEAD());

}
