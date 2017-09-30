/*
Problem 21 - Merge Two Sorted Lists

Merge two sorted linkedin lists and reuturn it as a new list.

This new list should be made by splicing together the nodes
of the first two lists.
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* mergedList = new ListNode(NULL);
		ListNode* resultList = NULL;

		if (!l1) {
			return l2;
		}
		else if (!l2) {
			return l1;
		}

		// Set first element
		if (l1->val < l2->val) {
			resultList = l1;
			l1 = l1->next;
		}
		else {
			resultList = l2;
			l2 = l2->next;
		}

		// Find which list next element should be from
		while (l1 && l2) {
			if (l1->val < l2->val) {
				mergedList = l1;
				l1 = l1->next;
			}
			else {
				mergedList = l2;
				l2 = l2->next;
			}
			mergedList = mergedList->next;
		}

		// Empty remaining list
		while (l1) {
			mergedList = l1;
			l1 = l1->next;
			mergedList = mergedList->next;
		}
		while (l2) {
			mergedList = l2;
			l2 = l2->next;
			mergedList = mergedList->next;
		}

		return resultList;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: [1, 3, 5] and [2, 4, 6]
	Expected Output: [1, 2, 3, 4, 5, 6]
	*/
	ListNode* l1n1 = new ListNode(1);
	ListNode* l1n2 = new ListNode(3);
	ListNode* l1n3 = new ListNode(5);
	l1n1->next = l1n2;
	l1n2->next = l1n3;
	l1n3->next = NULL;

	ListNode* l2n1 = new ListNode(2);
	ListNode* l2n2 = new ListNode(4);
	ListNode* l2n3 = new ListNode(6);
	l2n1->next = l2n2;
	l2n2->next = l2n3;
	l2n3->next = NULL;

	ListNode* testResult1 = solution.mergeTwoLists(l1n1, l2n1);
	std::cout << testResult1->val << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}