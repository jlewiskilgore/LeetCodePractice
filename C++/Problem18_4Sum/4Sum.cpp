/*
Problem 18 - 4 Sum

Given an array S of n integers, are there elements a,b,c and d
in S such that a + b + c + d = target?

Find all unique quadruplets in the array which gives
the sum of target.

Note: The solution set must not contain duplicate quadruplets.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
		std::vector<std::vector<int>> resultQuads = {};
		std::vector<int> checkQuad;
		int checkSum;
		int k;
		int l;

		if (nums.size() < 4) {
			return resultQuads;
		}

		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 3; i++) {
			for (int j = i + 1; j < nums.size() - 2; j++) {
				k = j + 1;
				l = nums.size() - 1;

				while (k < l) {
					checkSum = nums[i] + nums[j] + nums[k] + nums[l];

					if (checkSum == target) {
						checkQuad = { nums[i], nums[j], nums[k], nums[l] };
						resultQuads.push_back(checkQuad);

						j++;
						k--;
					}
					else if (checkSum < target) {
						k++;
					}
					else {
						l--;
					}
				}
			}
		}

		return resultQuads;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: S = [1, 0, -1, 0, -2, 2], target = 0
	Expected Output:
	[
		[-1, 0, 0, 1],
		[-2, -1, 1, 2],
		[-2, 0, 0, 2]
	}
	*/
	std::vector<int> testInput1 = { 1, 0, -1, 0, -2, 2 };
	std::vector<std::vector<int>> testResult1 = solution.fourSum(testInput1, 0);
	std::cout << "[ \n";
	for (int i = 0; i < testResult1.size(); i++) {
		std::cout << "  [";
		for (int j = 0; j < testResult1[i].size(); j++) {
			std::cout << testResult1[i][j] << " ";
		}
		std::cout << "] \n";
	}
	std::cout << "] \n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}