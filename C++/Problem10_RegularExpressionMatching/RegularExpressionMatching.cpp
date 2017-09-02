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
		int searchLength = s.length();
		std::string subStrToCheck;

		if (s.length() > p.length()) {
			matchFound = 0;
		}
		else if (s == p) {
			matchFound = 1;
		}
		else {
			matchFound = 0;
			for (int i = 0; i < p.length() - searchLength + 1; i++) {
				subStrToCheck = p.substr(i, searchLength);

				if (subStrToCheck == s) {
					matchFound = 1;
				}
				else if ((subStrToCheck.find('.') != std::string::npos) && !matchFound) {
					matchFound = checkDotWildcards(subStrToCheck, s);
				}
			}
		}

		return matchFound;
	}

private:
	int checkDotWildcards(std::string str, std::string checkStr) {
		int dotWildcardMatchFound = 0;
		std::string strNoWildcard = "";
		std::string checkStrNoWildcard = "";

		for (int i = 0; i < str.length(); i++) {
			if (str[i] != '.') {
				strNoWildcard += str[i];
				checkStrNoWildcard += checkStr[i];
			}
		}

		return (strNoWildcard == checkStrNoWildcard);
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: "aa", "a"
	Expected Output: false
	*/
	bool testResult1 = solution.isMatch("aa", "a");
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2:
	Input: "aa", "aa"
	Expected Output: true
	*/
	bool testResult2 = solution.isMatch("aa", "aa");
	std::cout << "Test Result 2: " << testResult2 << "\n";

	/*
	Test Case 3:
	Input: "cd", "aabbccdd"
	Expected Output: true
	*/
	bool testResult3 = solution.isMatch("cd", "aabbccdd");
	std::cout << "Test Result 3: " << testResult3 << "\n";

	/*
	Test Case 4:
	Input: "aa", "a."
	Expected Output: true
	*/
	bool testResult4 = solution.isMatch("aa", "a.");
	std::cout << "Test Result 4: " << testResult4 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}

