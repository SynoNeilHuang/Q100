
struct ListNode {
	int m_nKey;
	ListNode *m_pNext;
};

void DeleteNode(ListNode *pListHead, ListNode *pToBeDeleted) {
	if (!pListHead || !pToBeDeleted)
		return;
	/* if deleted node is head */
	if (pToBeDeleted == pListHead) {
		if (pListHead->m_pNext == NULL) {
			pListHead = NULL;
		} else {
			pListHead = pListHead->m_pNext;
		}
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	} else { /* if deleted node is not head node */
		if (pToBeDeleted->m_pNext) {
			ListNode *pNext = pToBeDeleted->m_pNext;
			pToBeDeleted->m_nKey = pNext->m_nKey;
			pToBeDeleted->m_pNext = pNext->m_pNext->m_pNext;
			delete pNext;
			pNext = NULL;
		} else {
			ListNode *iter = pListHead;
			while (iter->m_pNext != pToBeDeleted) {
				iter = iter->m_pNext;
			}
			delete pToBeDeleted;
			pToBeDeleted = NULL;
			iter->m_pNext = NULL;
		}
	}
}
