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
		ListNode* currNode = resultList;
		ListNode* zeroNode = new ListNode(0);
		int carryDigit = 0;
		int sum;

		while (l1 != zeroNode || l2 != zeroNode || carryDigit) {
			sum = l1->val + l2->val + carryDigit;
			carryDigit = 0; // Reset carryDigit

			// Convert the 10 to a carryDigit
			if (sum >= 10) {
				carryDigit = 1;
				sum = sum - 10;
			}

			if (l1->next) {
				l1 = l1->next;
			}
			else {
				l1 = zeroNode;
			}

			if (l2->next) {
				l2 = l2->next;
			}
			else {
				l2 = zeroNode;
			}

			currNode->next = new ListNode(sum);
			currNode = currNode->next;
		}

		return resultList->next;
	}
};

int main() {
	Solution solution;

	// Test Case 1: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	/*
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
	*/

	// Test Case 2: (0) + (0)
	ListNode* l1n1 = new ListNode(0);
	l1n1->next = NULL;

	ListNode* l2n1 = new ListNode(0);
	l2n1->next = NULL;

	solution.addTwoNumbers(l1n1, l2n1);

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;

}