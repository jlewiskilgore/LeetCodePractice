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
		ListNode* mergedList = NULL;
		ListNode* resultList = NULL;
		ListNode* l1Temp = l1;
		ListNode* l2Temp = l2;

		if (!l1) {
			return l2;
		}
		else if (!l2) {
			return l1;
		}

		// Set first element
		if (l1Temp->val <= l2Temp->val) {
			resultList = l1Temp;
			mergedList = l1Temp;
			l1Temp = l1Temp->next;
		}
		else {
			resultList = l2Temp;
			mergedList = l2Temp;
			l2Temp = l2Temp->next;
		}

		// Find which list next element should be from
		while (l1Temp && l2Temp) {
			if (l1Temp->val <= l2Temp->val) {
				mergedList->next = l1Temp;
				mergedList = l1Temp;
				l1Temp = l1Temp->next;
			}
			else {
				mergedList->next = l2Temp;
				mergedList = l2Temp;
				l2Temp = l2Temp->next;
			}
		}

		// Empty remaining list
		if(l1Temp) {
			mergedList->next = l1Temp;
		}
		if(l2Temp) {
			mergedList->next = l2Temp;
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

	/*
	ListNode* testResult1 = solution.mergeTwoLists(l1n1, l2n1);
	std::cout << testResult1->val << "\n";
	*/

	/*
	Test Case 2
	Input: [2] and [1]
	Expected Output: [1, 2]
	*/
	ListNode* t2l1n1 = new ListNode(2);

	ListNode* t2l2n1 = new ListNode(1);

	ListNode* testResult1 = solution.mergeTwoLists(t2l1n1, t2l2n1);
	std::cout << testResult1->val << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}