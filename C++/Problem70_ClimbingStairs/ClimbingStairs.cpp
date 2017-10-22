/*
Problem 70 - Climbing Stairs

You are climbing a stair case. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer
*/

#include <iostream>

class Solution {
public:
	int climbStairs(int n) {
		int temp;
		int prevSum;
		int nextToPrevSum;

		if (n == 1) {
			return 1;
		}
		else if (n == 2) {
			return 2;
		}

		nextToPrevSum = 1;
		prevSum = 2;

		for (int i = 3; i <= n; i++) {
			// f(n) = f(n-1) + f(n-2)
			temp = prevSum + nextToPrevSum;
			nextToPrevSum = prevSum;
			prevSum = temp;
		}

		return prevSum;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: 3
	Expected Output: 3
	*/
	int testResult1 = solution.climbStairs(3);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 1
	Input: 4
	Expected Output: 5
	*/
	int testResult2 = solution.climbStairs(4);
	std::cout << "Test Result 2: " << testResult2 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}