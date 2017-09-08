/*
Problem 11 - Container With Most Water

Give n non-negative integers, where each represents a point
at coordinate (i, a_i).

n vertical lines are drawn such that the two endpoints of line
i is at (i, a_i) and (i, 0).

Find two lines, which together with x-axis forms a container,
such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int minHeight = height[0];
		int area = 0;

		for (int i = 1; i < height.size(); i++) {
			if (height[i] < minHeight) {
				minHeight = height[i];
			}
		}

		area = minHeight * (height.size() - 1);

		return area;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: [1,1]
	Expected Output: 1
	*/
	std::vector<int> test1 = { 1, 1 };
	int testResult1 = solution.maxArea(test1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2
	Input: [1,2,4,3]
	Expected Output: 4
	*/
	std::vector<int> test2 = { 1, 2, 4, 3 };
	int testResult2 = solution.maxArea(test2);
	std::cout << "Test Result 2: " << testResult2 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}