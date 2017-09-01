/*
Problem 10 - Regular Expression Matching

Implement regular expression matching with support
for '.' and '*'.

'.' - Matches any single character
'*' - Matches zero or more of the preceding elements;

The matching should cover the entire input string (not partial)

*/

#include <iostream>
#include <string>

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		bool matchFound;

		if (s.length() > p.length()) {
			matchFound = 0;
		}
		else if (s == p) {
			matchFound = 1;
		}

		return matchFound;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: 
	*/
	bool testResult1 = solution.isMatch("aa", "a");
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2:
	Input:
	*/
	bool testResult2 = solution.isMatch("aa", "aa");
	std::cout << "Test Result 2: " << testResult2 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}

