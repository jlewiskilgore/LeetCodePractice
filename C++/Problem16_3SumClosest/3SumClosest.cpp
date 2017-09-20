/*
Problem 16 - 3Sum Closest

Given an array S of n integers, find three integers
in S such that the sum is closest to a given number, target.

Return the sum of the three integers. 

You may assume that each input would have exactly one solution.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int threeSumClosest(std::vector<int>& nums, int target) {
		int closestSum;
		int nextSum;
		int minDifference = INT_MAX;
		int nextDifference;

		std::sort(nums.begin(), nums.end());
		closestSum = nums[0] + nums[1] + nums[nums.size() - 1];

		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1;
			int k = nums.size() - 1;

			while (j < k) {
				nextSum = nums[i] + nums[j] + nums[k];
				nextDifference = nextSum - target;

				if (abs(nextDifference) < minDifference) {
					closestSum = nextSum;
					minDifference = abs(nextDifference);
				}

				if (minDifference == 0) {
					return closestSum;
				}
					
				if(nextDifference < 0) {
					j++;
				}
				else {
					k--;
				}
			}
		}

		return closestSum;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: S = {-1, 2, 1, -4}, target = 1
	Expected Ouput: 2  which is (-1 + 2 + 1 = 2)
	*/
	std::vector<int> testInput1 = { -1, 2, 1, -4 };
	int testResult1 = solution.threeSumClosest(testInput1, 1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2
	Input: S = {1, 1, 1, 0}, target = -100
	Expected Ouput: 2
	*/
	std::vector<int> testInput2 = { 1, 1, 1, 0 };
	int testResult2 = solution.threeSumClosest(testInput2, -100);
	std::cout << "Test Result 2: " << testResult2 << "\n";

	/*
	Test Case 3
	Input: S = {0, 2, 1, -3}, target = 1
	Expected Output: 0
	*/
	std::vector<int> testInput3 = { 0, 2, 1, -3 };
	int testResult3 = solution.threeSumClosest(testInput3, 1);
	std::cout << "Test Result 3: " << testResult3 << "\n";

	/*
	Test Case 4
	Input: S = { 0, 5, -1, -2, 4, -1, 0, -3, 4, -5 }, target = 1
	Expected Output: 1
	*/
	std::vector<int> testInput4 = { 0, 5, -1, -2, 4, -1, 0, -3, 4, -5 };
	int testResult4 = solution.threeSumClosest(testInput4, 1);
	std::cout << "Test Result 4: " << testResult4 << "\n";


	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}