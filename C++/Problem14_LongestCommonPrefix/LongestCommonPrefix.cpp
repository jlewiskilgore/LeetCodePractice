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
		std::string longestCommonPrefix;
		std::string commonPrefix;

		if (strs.size() == 0) {
			longestCommonPrefix = "";
		}
		else if (strs.size() == 1) {
			longestCommonPrefix = strs[0];
		}
		else {
			longestCommonPrefix = strs[0];

			for (int i = 1; i < strs.size(); i++) {
				commonPrefix = "";
				for (int j = 0; j < longestCommonPrefix.length(); j++) {
					if (longestCommonPrefix[j] == strs[i][j]) {
						commonPrefix += strs[i][j];
					}
					else {
						break;
					}
				}
				if (commonPrefix < longestCommonPrefix) {
					longestCommonPrefix = commonPrefix;
				}
			}
		}

		return longestCommonPrefix;
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

	/*
	Test Case 3
	Input: ["abc", "abd"]
	Expected Output: "ab"
	*/
	std::vector<std::string> testInput3 = { "abc", "abd" };
	std::string testResult3 = solution.longestCommonPrefix(testInput3);
	std::cout << "Test Result 3: " << testResult3 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}