#include <iostream>

struct ListNode {
	int m_nKey;
	ListNode *m_pNext;
};

ListNode *FirstCmnNode(ListNode *List1, ListNode *List2) {
	int Len1 = 0, Len2 = 0;
	ListNode *iter = List1;
	while (iter != NULL) {
		++Len1;
		iter = iter->m_pNext;
	}
	iter = List2;
	while (iter != NULL) {
		++Len2;
		iter = iter->m_pNext;
	}
	int offset = 0;
	ListNode *start1 = List1;
	ListNode *start2 = List2;
	if ( Len1 > Len2 ) {
		offset = Len1 - Len2;
		for (int i = 0; i < offset ; ++i) {
			start1 = start1->m_pNext;
		}
	} else {
		offset = Len2 - Len1;
		for (int i = 0; i < offset ; ++i) {
			start2 = start2->m_pNext;
		}
	}

	for (;start1 != NULL && start2 != NULL; start1 = start1->m_pNext, start2 = start2->m_pNext) {
		if ((start1->m_nKey == start2->m_nKey) && (start1 == start2)) {
			break;
		}
	}
	return start1;
}

int main() {
	return 0;
}
