/*
LeetCode - Problem 1 - Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume each input would have exactly one solution, and you may not use the same element twice.
*/

#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> indexVals;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					indexVals.push_back(i);
					indexVals.push_back(j);
					return indexVals;
				}
			}
		}
	}
};

int main() {
	Solution solution;

	// Test Case: Expected result [0, 1]
	std::vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;

	std::vector<int> result = solution.twoSum(nums, target);

	std::cout << "Expected Result: [0, 1]\n";
	std::cout << "Result: ";
	std::cout << "[" << result[0] << ", " << result[1] << "]";
	std::cout << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}