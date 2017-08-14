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
		ListNode* resultList = &ListNode(NULL);
		int sum;
		int carryDigit;
		ListNode* list1 = l1;
		ListNode* list2 = l2;
		
		while(list1 && list2) {
			std::cout << list1->val;
			//sum = l1->val + l2->val;

			//resultList->val = sum;
			list1 = list1->next;
			list2 = list2->next;
		}

		return resultList;
	}
};

int main() {
	Solution solution;

	// Test Case: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	ListNode* l1n1 = &ListNode(2);
	ListNode* l1n2 = &ListNode(4);
	ListNode* l1n3 = &ListNode(3);
	l1n1->next = l1n2;
	l1n2->next = l1n3;

	ListNode* l2n1 = &ListNode(5);
	ListNode* l2n2 = &ListNode(6);
	ListNode* l2n3 = &ListNode(4);
	l2n1->next = l2n2;
	l2n2->next = l2n3;

	solution.addTwoNumbers(l1n1, l2n1);

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;

}