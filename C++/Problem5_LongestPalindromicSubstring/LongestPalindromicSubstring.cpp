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
		int lengthLongSubstr = 0;
		
		std::string result = isSubstringPalindrome(s, 1, 3);
		lengthLongSubstr = result.length();
		std::cout << "result: " << result << "\n";
		return result;
	}

private:
	std::string isSubstringPalindrome(std::string fullStr, int startIndex, int endIndex) {
		std::string subStr = fullStr.substr(startIndex, (endIndex - startIndex + 1));
		std::string revStr;

		for (int i = (subStr.length() - 1); i >= 0; i--) {
			revStr += subStr[i];
		}

		return (subStr == revStr)? subStr : "";
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