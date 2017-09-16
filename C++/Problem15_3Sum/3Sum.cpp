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

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> solutionTriplets = { };
		std::vector<int> checkTriplet;
		int checkSum;

		if (nums.size() < 3) {
			return solutionTriplets;
		}

		for (int i = 0; i < nums.size() - 2; i++) {
			for (int j = i + 1; j < nums.size() - 1; j++) {
				for (int k = j + 1; k < nums.size(); k++) {
					checkTriplet = {};
					checkTriplet.push_back(nums[i]);
					checkTriplet.push_back(nums[j]);
					checkTriplet.push_back(nums[k]);
					checkSum = vectorSum(checkTriplet);

					if (checkSum == 0) {
						solutionTriplets.push_back(checkTriplet);
					}
				}
			}
		}

		return solutionTriplets;
	}
private:
	int vectorSum(std::vector<int> vect) {
		int sum = 0;

		for (int i = 0; i < vect.size(); i++) {
			sum += vect[i];
		}

		return sum;
	}
};


int main() {
	Solution solution;

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