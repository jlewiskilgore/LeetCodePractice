/*
Problem 26 - Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place
such that each element appear only once and return the
new length.

Do not allocate extra space for another array, you must
do this in place with constant memory.

For example,
Given input array nums = [1,1,2]

Your function should return length = 2, with the first two
elements of nums being 1 and 2 respectively. It doesn't
matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		int lastVal;
		int i = 0;

		if (nums.size() == 0) {
			return i;
		}

		lastVal = nums[i];

		for (int j = 1; j < nums.size(); j++) {
			if (nums[j] > lastVal) {
				i++;
				nums[i] = nums[j];
				lastVal = nums[j];
			}
		}

		return i + 1;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: [1,1,2]
	Expected Output: 2
	*/
	std::vector<int> testInput1 = { 1,1,2 };
	int testResult1 = solution.removeDuplicates(testInput1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}