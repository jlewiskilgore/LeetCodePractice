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
			if (i == 0 || nums[i] > nums[i - 1]) {
				for (int j = i + 1; j < nums.size() - 2; j++) {
					if (j == i + 1 || nums[j] > nums[j - 1]) {
						k = j + 1;
						l = nums.size() - 1;

						while (k < l) {
							checkSum = nums[i] + nums[j] + nums[k] + nums[l];

							if (checkSum == target) {
								std::cout << "i: " << i << " j: " << j << " k: " << k << " l: " << l << "\n";

								checkQuad = { nums[i], nums[j], nums[k], nums[l] };
								resultQuads.push_back(checkQuad);

								k++;
								l--;

								while (k < l && nums[k] == nums[k - 1]) {
									k++;
								}
								while (k < l && nums[l] == nums[l + 1]) {
									l--;
								}
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

	/*
	Test Case 2
	Input: S = [-3, -2, -1, 0, 0, 1, 2, 3], target = 0
	Expected Output:
	[
		[-1, 0, 0, 1],
		[-2, -1, 1, 2],
		[-2, 0, 0, 2]
	]
	*/
	std::vector<int> testInput2 = { -3, -2, -1, 0, 0, 1, 2, 3 };
	std::vector<std::vector<int>> testResult2 = solution.fourSum(testInput2, 0);
	std::cout << "[ \n";
	for (int i = 0; i < testResult2.size(); i++) {
		std::cout << "  [";
		for (int j = 0; j < testResult2[i].size(); j++) {
			std::cout << testResult2[i][j] << " ";
		}
		std::cout << "] \n";
	}
	std::cout << "] \n";

	/*
	Test Case 3
	Input: S = [-1, 0, 1, 2, -1, -4], target = -1
	Expected Output: 
	[
		[-4, 0, 1, 2], 
		[-1, -1, 0, 1]
	]
	*/
	std::vector<int> testInput3 = { -1, 0, 1, 2, -1, -4 };
	std::vector<std::vector<int>> testResult3 = solution.fourSum(testInput3, -1);
	std::cout << "[ \n";
	for (int i = 0; i < testResult3.size(); i++) {
		std::cout << "  [";
		for (int j = 0; j < testResult3[i].size(); j++) {
			std::cout << testResult3[i][j] << " ";
		}
		std::cout << "] \n";
	}
	std::cout << "] \n";

	/*
	Test Case 4
	Input: S = [-1, -5, -5, -3, 2, 5, 0, 4], target = -7
	Expected Output:
	[
	[-5, -5, -1, 4],
	[-5, -3, -1, 2]
	]
	*/
	std::vector<int> testInput4 = { -1, -5, -5, -3, 2, 5, 0, 4 };
	std::vector<std::vector<int>> testResult4 = solution.fourSum(testInput4, -7);
	std::cout << "[ \n";
	for (int i = 0; i < testResult4.size(); i++) {
		std::cout << "  [";
		for (int j = 0; j < testResult4[i].size(); j++) {
			std::cout << testResult4[i][j] << " ";
		}
		std::cout << "] \n";
	}
	std::cout << "] \n";

	/*
	Test Case 5
	Input: S = [-1, 0, -5, -2, -2, -4, 0, 1, -2], target = -9
	Expected Output:
	[
	[-5, -4, -1, 1],
	[-5, -4, 0, 0],
	[-5, -2, -2, 0],
	[-4, -2, -2, -1]
	]
	*/
	std::vector<int> testInput5 = { -1, 0, -5, -2, -2, -4, 0, 1, -2 };
	std::vector<std::vector<int>> testResult5 = solution.fourSum(testInput5, -9);
	std::cout << "[ \n";
	for (int i = 0; i < testResult5.size(); i++) {
		std::cout << "  [";
		for (int j = 0; j < testResult5[i].size(); j++) {
			std::cout << testResult5[i][j] << " ";
		}
		std::cout << "] \n";
	}
	std::cout << "] \n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}