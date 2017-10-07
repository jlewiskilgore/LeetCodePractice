/*
Problem 27 - Remove Element

Given an array and a value, remove all instances of that value
in place and return the new length.

Do not allocate extra space for another array, you must
do this in place with constant memory.

The order of elements can be changed. It doesn't mastter
what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your functioin should return length = 2, with the first
two elements of nums being 2.

*/

#include <iostream>
#include <vector>

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		int adjustIdx = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == val) {
				adjustIdx++;
			}
			else {
				nums[i - adjustIdx] = nums[i];
			}
		}


		return nums.size() - adjustIdx;
	}
};

int main() {
	Solution solution;

	/*
	Test case 1:
	Input: [3,2,2,3]
	Expected Output: 2
	*/
	std::vector<int> testInput1 = { 3,2,2,3 };
	int testResult1 = solution.removeElement(testInput1, 3);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}