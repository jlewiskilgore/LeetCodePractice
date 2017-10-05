/*
Problem 24 - Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return
its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3

Your algorithm should use only constant space.

You may not modify the values in the list, only nodes itself
can be changed.
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* resultHead = new ListNode(0);
		resultHead->next = head;
		ListNode* tempHead = resultHead; // Copy of head argument

		ListNode* tempNode1 = NULL;
		ListNode* tempNode2 = NULL;

		// Check if there is a pair available for swap
		while (tempHead->next && tempHead->next->next) {
			tempNode1 = tempHead;		
			tempHead = tempHead->next;
			tempNode1->next = tempHead->next;

			tempNode2 = tempHead->next->next;
			tempHead->next->next = tempHead;
			tempHead->next = tempNode2;
		}
		
		return resultHead->next;
	}
};

int main() {
	Solution solution;

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}