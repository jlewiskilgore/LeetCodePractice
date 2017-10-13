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

class Solution {
public:
	int maxSubArray(std::vector<int>& nums) {
		int largestSum = INT_MIN;
		int tempSum;
		int largestTempSum;

		if (nums.size() == 1) {
			return nums[0];
		}

		for (int i = 0; i < nums.size(); i++) {
			tempSum = nums[i];
			largestTempSum = nums[i];

			for (int j = i + 1; j < nums.size(); j++) {
				tempSum += nums[j];

				if (tempSum > largestTempSum) {
					largestTempSum = tempSum;
				}
			}

			if (largestTempSum > largestSum) {
				largestSum = largestTempSum;
			}
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