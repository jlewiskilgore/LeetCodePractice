/*
Problem 20 - Valid Parenthesis

Given a string containing just the characters '(', ')', '{', '}',
'[' and ']', determine if the input string is valid.

The brackets must close in the correct order "()" and 
"()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
	bool isValid(std::string s) {
		std::vector<char> leftCharArr = {};
		char testChar;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				leftCharArr.push_back('(');
			}
			else if (s[i] == '{') {
				leftCharArr.push_back('{');
			}
			else if (s[i] == '[') {
				leftCharArr.push_back('[');
			}
			else {
				if (leftCharArr.size() == 0) {
					return 0;
				}

				if (s[i] == ')') {
					testChar = leftCharArr.back();
					leftCharArr.pop_back();

					if (testChar != '(') {
						return 0;
					}
				}
				else if (s[i] == '}') {
					testChar = leftCharArr.back();
					leftCharArr.pop_back();

					if (testChar != '{') {
						return 0;
					}
				}
				else if (s[i] == ']') {
					testChar = leftCharArr.back();
					leftCharArr.pop_back();

					if (testChar != '[') {
						return 0;
					}
				}
			}

		}

		if (leftCharArr.size() > 0) {
			return 0;
		}

		return 1;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: "["
	Expected Output: False
	*/
	bool testResult1 = solution.isValid("[");
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}