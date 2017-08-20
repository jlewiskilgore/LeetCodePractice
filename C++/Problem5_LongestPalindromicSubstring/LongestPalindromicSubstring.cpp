/*
Problem 5 - Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s.
You may assume the maximum length of s is 1000.

*/

#include <stddef.h>
#include <string>
#include <iostream>

class Solution {
public:
	std::string longestPalindrome(std::string s) {
		//int result = isSubstringPalindrome(s, 1, 3);
		//std::cout << "result: " << result << "\n";
		return "test";
	}

private:
	int isSubstringPalindrome(std::string subStr, int startIndex, int endIndex) {
		std::cout << subStr;
		for (int i = 0; i < (subStr.length())/2; i++) {
			std::cout << i;
		}
		return 1;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: "babad"
	Expected Output: "bab" or "aba"
	*/
	std::string testInput1("babad");
	solution.longestPalindrome("babad");

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}