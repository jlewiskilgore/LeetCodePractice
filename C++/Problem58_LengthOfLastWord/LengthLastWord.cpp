/*
Problem 58 - Length of Last Word

Given a string s consists of upper/lower-case alphabets and
empty space characters ' ', return the length of last word
in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists
of non-space characters only.

For example,
Given s = "Hello World",
return 5
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	int lengthOfLastWord(std::string s) {
		int resultLength = 0;

		if (s.length() == 0) {
			return resultLength;
		}
		
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				resultLength++;
			}
			else {
				if (resultLength > 0) {
					return resultLength;
				}
			}
		}
		return resultLength;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: "Hello World"
	Expected Output: 5
	*/
	int testResult1 = solution.lengthOfLastWord("Hello World");
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}