/*
Problem 12 - Integer to Roman

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <string>
#include <iostream>

class Solution {
public:
	std::string intToRoman(int num) {
		std::string romanStr = "";
		int remainingInt = num;

		while (remainingInt > 0) {
			if (remainingInt >= 1000) {
				romanStr += "M";
				remainingInt = remainingInt - 1000;
			}
			else if (remainingInt >= 900) {
				romanStr += "CM";
				remainingInt = remainingInt - 900;
			}
			else if (remainingInt >= 500) {
				romanStr += "D";
				remainingInt = remainingInt - 500;
			}
			else if (remainingInt >= 400) {
				romanStr += "CD";
				remainingInt = remainingInt - 400;
			}
			else if (remainingInt >= 100) {
				romanStr += "C";
				remainingInt = remainingInt - 100;
			}
			else if (remainingInt >= 90) {
				romanStr += "XC";
				remainingInt = remainingInt - 90;
			}
			else if (remainingInt >= 50) {
				romanStr += "L";
				remainingInt = remainingInt - 50;
			}
			else if (remainingInt >= 40) {
				romanStr += "XL";
				remainingInt = remainingInt - 40;
			}
			else if (remainingInt >= 10) {
				romanStr += "X";
				remainingInt = remainingInt - 10;
			}
			else if (remainingInt >= 9) {
				romanStr += "IX";
				remainingInt = remainingInt - 9;
			}
			else if (remainingInt >= 5) {
				romanStr += "V";
				remainingInt = remainingInt - 5;
			}
			else if (remainingInt >= 4) {
				romanStr += "IV";
				remainingInt = remainingInt - 4;
			}
			else if(remainingInt >= 1) {
				romanStr += "I";
				remainingInt = remainingInt - 1;
			}
		}

		return romanStr;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: 1
	Expected Output: "I"
	*/
	std::string testResult1 = solution.intToRoman(1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}