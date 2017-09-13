/*
Problem 13 - Roman to Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>
#include <map>

class Solution {
public:
	int romanToInt(std::string s) {
		int resultInt = 0;
		std::map<char, int> romanValue;

		// Insert values Roman values into map
		romanValue['I'] = 1;
		romanValue['V'] = 5;
		romanValue['X'] = 10;
		romanValue['L'] = 50;
		romanValue['C'] = 100;
		romanValue['D'] = 500;
		romanValue['M'] = 1000;

		for (int i = 0; i < s.length(); i++) {
			if ((i != s.length() - 1) && (romanValue[s[i]] < romanValue[s[i + 1]])) {
				resultInt -= romanValue[s[i]];
			}
			else {
				resultInt += romanValue[s[i]];
			}
		}

		return resultInt;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: DCXXI
	Expected Output: 621
	*/
	int testResult1 = solution.romanToInt("DCXXI");
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}