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
			for (int i = 0; i < p.length(); i++) {
				for (int j = 0; j < p.length(); j++) {
					subStrToCheck = p.substr(i, j);

					if (subStrToCheck == s) {
						matchFound = 1;
					}
					else if ((subStrToCheck.find('.') != std::string::npos) && !matchFound) {
						matchFound = checkDotWildcards(subStrToCheck, s);
					}
					else if ((subStrToCheck.find('*') != std::string::npos) && !matchFound) {
						matchFound = checkStarWildcards(subStrToCheck, s);
					}
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

	int checkStarWildcards(std::string str, std::string checkStr) {
		std::cout << str << ", checking: "<< checkStr << "\n";

		int starWildcardMatchFound = 0;
		int useWildcard = 0;
		char prevChar;
		std::string strNoWildcard = "";
		std::string checkStrNoWildcard = "";

		for (int i = 0; i < str.length(); i++) {
			if (i != 0 && str[i] == '*') {
				if (!useWildcard) {
					useWildcard = 1;
					prevChar = str[i - 1];
				}

				checkStrNoWildcard += checkStr[i];
				
				if (checkStr[i] != str[i] && prevChar == checkStr[i] && useWildcard) {
					strNoWildcard += prevChar;
				}
				else if(checkStr[i] == str[i]) {
					strNoWildcard += str[i];
				}
				else {
					return starWildcardMatchFound;
				}
			}
			else if (i == 0 && str[i] == '*') {
				return starWildcardMatchFound;
			}
			else if (useWildcard) {
				strNoWildcard += prevChar;
				checkStrNoWildcard += checkStr[i];
			}
			else {
				strNoWildcard += str[i];
				checkStrNoWildcard += checkStr[i];
			}
		}

		std::cout << "no wc: " << strNoWildcard << ", check no wc: " << checkStrNoWildcard << "\n";

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

	/*
	Test Case 5:
	Input: "abc", "a*c"
	Expected Output: false
	*/
	bool testResult5 = solution.isMatch("abc", "*a*c");
	std::cout << "Test Result 5: " << testResult5 << "\n";

	/*
	Test Case 6:
	Input: "aab", "c*a*b"
	Expected Output: true
	*/
	bool testResult6 = solution.isMatch("aab", "c*a*b");
	std::cout << "Test Result 6: " << testResult6 << "\n";

	/*
	Test Case 7:
	Input: "aaab", "a*b
	Expected Output: true
	*/
	bool testResult7 = solution.isMatch("aaab", "a*b");
	std::cout << "Test Result 7: " << testResult7 << "\n";


	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}

