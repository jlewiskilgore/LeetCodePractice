/*
Problem 53 - Maximum Subarray

Find the contiguous subarray within an array 
(containing at least one number)
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contigous subarray [4,-1,2,1] has the largest sum = 6.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int maxSubArray(std::vector<int>& nums) {
		int largestSum = nums[0];
		int tempSum = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			tempSum = std::max(nums[i], tempSum + nums[i]);
			largestSum = std::max(largestSum, tempSum);
		}

		return largestSum;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: [-2,1,-3,4,-1,2,1,-5,4]
	Expected output: [4,-1,2,1]
	*/
	std::vector<int> testInput1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int testResult1 = solution.maxSubArray(testInput1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2
	Input: [1,2]
	Expected output: [1,2]
	*/
	std::vector<int> testInput2 = { 1, 2 };
	int testResult2 = solution.maxSubArray(testInput2);
	std::cout << "Test Result 2: " << testResult2 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}