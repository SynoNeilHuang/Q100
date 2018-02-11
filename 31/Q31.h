#ifndef __Q31__
#define __Q31__
#include <iostream>

using std::cout;
using std::endl;

struct LSTNode {
		int m_nKey;
		LSTNode* m_pNext;
		LSTNode() : m_nKey(0), m_pNext(NULL) {}
		LSTNode(int value) { m_nKey = value; }
};

class LSTList {
	public:
		LSTList() : head(NULL), tail(NULL) {}
		LSTList(int value) : head(NULL), tail(NULL) {
			add(value);
		}
		virtual ~LSTList() {
			LSTNode *iter;
			while (head) {
				iter = head;
				head = head->m_pNext;
				delete iter;
			}
		}
		void add(int value) {
			LSTNode *node = new LSTNode(value);
			if (!head) {
				head = node;
				tail = node;
			} else {
				tail->m_pNext = node;
				tail = node;
			}
		}
		void printList() {
			LSTNode *iter = head;
			while (iter) {
				cout << iter->m_nKey << " ";
				iter = iter->m_pNext;
			}
			cout << endl;
		}
		LSTNode *getHEAD() { return head; }
	private:
		LSTNode *head;
		LSTNode *tail;
		LSTList& operator=(const LSTList& source);
		LSTList(const LSTList&);
};

#endif /* __Q31__ */
