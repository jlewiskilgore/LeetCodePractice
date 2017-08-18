/*
LeetCode - Problem 3 - Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring
without repeating characters.

*/

#include <stddef.h>
#include <map>
#include <iostream>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int longSubstrLen;
		int currSubstrLen;

		if (s.length() == 0) {
			longSubstrLen = 0;
		}
		else if (s.length() == 1) {
			longSubstrLen = 1;
		}
		else {
			std::map<char, int> isLetterUsed;
			longSubstrLen = 0;

			for (int i = 0; i < s.length(); i++) {
				currSubstrLen = 0;
				isLetterUsed.clear();

				for (int j = i; j < s.length(); j++) {
					if (isLetterUsed[s[j]]) {
						break;
					}
					else {
						isLetterUsed[s[j]] = 1;
						currSubstrLen++;
					}
				}
				if (currSubstrLen > longSubstrLen) {
					longSubstrLen = currSubstrLen;
				}
			}
		}

		return longSubstrLen;
	}
};

int main() {
	Solution solution;

	// Test Case 1:
	// expected: "abc" with length 3
	std::cout << solution.lengthOfLongestSubstring("abc") << "\n";

	// Test Case 2:
	// expected: "b" with length 1
	std::cout << solution.lengthOfLongestSubstring("b") << "\n";

	// Test Case 3:
	// expected: "wke" with length 3
	std::cout << solution.lengthOfLongestSubstring("pwwkew") << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}