/*
Problem 15 - 3Sum

Given an array S of n integers, are three elements
a, b, c in S such that a + b + c = 0?

Find all unique triplets in the array which gives the
sum of zero.

Note: The solution set must not contain duplicate triplets.
*/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> solutionTriplets = { };
		std::vector<int> checkTriplet;
		int checkSum;

		if (nums.size() < 3) {
			return solutionTriplets;
		}

		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++) {
			if (i == 0 || nums[i] > nums[i - 1]) {
				int j = i + 1;
				int k = nums.size() - 1;

				while (j < k) {
					if (nums[i] + nums[j] + nums[k] == 0) {
						checkTriplet = { nums[i], nums[j], nums[k] };
						solutionTriplets.push_back(checkTriplet);

						j++;
						k--;

						// Look for a different value for j and k
						while (j < k && nums[j] == nums[j - 1]) {
							j++;
						}
						while (j < k && nums[k] == nums[k + 1]) {
							k--;
						}
					}
					else if (nums[i] + nums[j] + nums[k] < 0) {
						j++;
					}
					else {
						k--;
					}
				}
			}
		}

		return solutionTriplets;
	}
// Note: Private methods used for brute force method
/*
private:
	int vectorSum(std::vector<int> vect) {
		int sum = 0;

		for (int i = 0; i < vect.size(); i++) {
			sum += vect[i];
		}

		return sum;
	}

	int isTripletDuplicate(std::vector<int> testVect, std::vector<std::vector<int>> vectList) {
		std::vector<int> vect1 = testVect;
		std::vector<int> vect2;

		std::sort(vect1.begin(), vect1.begin() + 3);

		for (int i = 0; i < vectList.size(); i++) {
			vect2 = vectList[i];
			std::sort(vect2.begin(), vect2.begin() + 3);

			if (vect1 == vect2) {
				return 1;
			}
		 }

		return 0;
	}
	*/
};


int main() {
	Solution solution;

	std::vector<int> test1 = { -1, 0, 1 };
	std::vector<int> test2 = { 1, 0, -1 };

	/*
	Test Case 1
	Input: [-1, 0, 1, 2, -1, -4]
	Expected Output:
	[
		[-1, 0, 1],
		[-1, -1, 2]
	]
	*/
	std::vector<int> testInput1 = { -1, 0, 1, 2, -1, -4 };
	std::vector<std::vector<int>> testResult1 = solution.threeSum(testInput1);
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