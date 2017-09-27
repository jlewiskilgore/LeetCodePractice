/*
Problem 19 - Remove Nth Node From End of List

Given a linked list, remove the Nth node from the end
of list and return its head.

For example,

Given linked list: 1->2->3->4->5 and n = 2

After removing the second node from the end,
the linked list becomes 1->2->3->4->5

Note:

-Given n will always be valid
-Try to do this in one pass

*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* resultList = new ListNode(NULL);
		ListNode* zeroNode = new ListNode(0);
		int nodeNum = 1;

		while (head != zeroNode) {
			ListNode* nextNode = new ListNode(head->val);
			std::cout << head->val << "\n";

			if (nodeNum == 1 && n != 1) {
				resultList->next = nextNode;
			}

			if (head->next) {
				head = head->next;
			}
			else {
				head = zeroNode;
			}
			
			nodeNum++;
		}

		std::cout << "Result Head: " << resultList->next->val << "\n";
		return resultList->next;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: list [1], n = 1
	Expected Output: []
	*/
	ListNode* l1n1 = new ListNode(1);
	l1n1->next = NULL;
	solution.removeNthFromEnd(l1n1, 1);


	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}