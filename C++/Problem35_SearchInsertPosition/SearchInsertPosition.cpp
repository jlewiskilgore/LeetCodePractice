/*
Problem 35 - Search Insert Position

Given a sorted array and a target value, return the index
if the target is found. If not, return the index where it 
would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples:

[1,3,5,6], 5->2
[1,3,5,6], 2->1
[1,3,5,6], 7->4
[1,3,5,6], 0->0

*/

#include <vector>
#include <iostream>

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		int j = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				return i;
			}
		}

		if (target > nums[nums.size() - 1]) {
			return nums.size();
		}

		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] > target) {
				return j;
			}
		}

		return 0;
	}
};

int main() {
	Solution solution;

	std::vector<int> testInput1 = { 1, 3, 5, 6 };
	int testResult1 = solution.searchInsert(testInput1, 2);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}