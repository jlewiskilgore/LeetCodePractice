/*
Problem 14 - Longest Common Prefix

Write a function to find the longest common prefix
string amongst an array of string.

*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		std::string longestPrefix;

		if (strs.size() == 0) {
			longestPrefix = "";
		}
		else if (strs.size() == 1) {
			longestPrefix = strs[0];
		}

		return longestPrefix;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: []
	Expected Output: ""
	*/
	std::vector<std::string> testInput1;
	std::string testResult1 = solution.longestCommonPrefix(testInput1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2
	Input: ["a"]
	Expected Output: "a"
	*/
	std::vector<std::string> testInput2 = { "a" };
	std::string testResult2 = solution.longestCommonPrefix(testInput2);
	std::cout << "Test Result 2: " << testResult2 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}