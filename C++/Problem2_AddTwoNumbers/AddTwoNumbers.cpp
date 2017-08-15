/*
LeetCode - Problem 2 - Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.

The digits are stored in reverse order and each of their nodes contain
a single digit.

Add the two numbers and return it as a linked list.

Note: You may assume the two numbers do not contain any leading zero, except
the number 0 itself.

Singly Linked List is defined as:

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}

*/

#include <stddef.h>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* resultList = new ListNode(NULL);
		ListNode* lastNode = new ListNode(NULL);
		ListNode* currNode = new ListNode(NULL);
		ListNode* nextNode = new ListNode(NULL);
		ListNode* zeroNode = new ListNode(0);

		int sum = 0;
		int carryDigit = 0;

		ListNode* list1 = l1;
		ListNode* list2 = l2;

		while (list1->val && list2->val) {
			sum = list1->val + list2->val + carryDigit;

			currNode = new ListNode(sum % 10);

			if (list1->next) {
				list1 = list1->next;
			}
			else {
				list1 = zeroNode;
			}

			if (list2->next) {
				list2 = list2->next;
			}
			else {
				list2 = zeroNode;
			}

			// First time through set Head Node
			if (resultList->next == nullptr) {
				resultList = currNode;
				resultList->next = lastNode;
			}
			else {
				lastNode->val = currNode->val;
				lastNode->next = nextNode;
				lastNode = lastNode->next;
			}
		}

		std::cout << resultList->val << " ";
		std::cout << resultList->next->val << " ";
		std::cout << resultList->next->next->val << " ";
		return resultList;
	}
};

int main() {
	Solution solution;

	// Test Case: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	ListNode* l1n1 = new ListNode(2);
	ListNode* l1n2 = new ListNode(4);
	ListNode* l1n3 = new ListNode(3);
	l1n1->next = l1n2;
	l1n2->next = l1n3;
	l1n3->next = NULL;

	ListNode* l2n1 = new ListNode(5);
	ListNode* l2n2 = new ListNode(6);
	ListNode* l2n3 = new ListNode(4);
	l2n1->next = l2n2;
	l2n2->next = l2n3;
	l2n3->next = NULL;

	solution.addTwoNumbers(l1n1, l2n1);

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;

}