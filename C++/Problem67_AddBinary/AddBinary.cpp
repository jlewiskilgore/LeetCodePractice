/*
Problem 67 - Add Binary

Given two binary strings, return their sum(also a binary string).

For example,

a = "11"
b = "1"
return "100"

*/

#include <iostream>
#include <string>
#include <cmath>

class Solution {
public:
	std::string addBinary(std::string a, std::string b) {
		std::string resultBinaryStr = "";
		int carryBit = 0;
		int tempVal = 0;

		if (a.length() - b.length() != 0) {
			int strDiff = a.length() - b.length();
			std::string leadingStr = "";

			for (int i = 0; i < abs(strDiff); i++) {
				leadingStr += "0";
			}

			strDiff > 0 ? b = leadingStr + b : a = leadingStr + a;
		}

		for (int i = a.length() - 1; i >= 0; i--) {
			tempVal = (a[i] - '0') + (b[i] - '0') + carryBit;

			if (tempVal == 0) {
				resultBinaryStr += '0';
				carryBit = 0;
			}
			else if (tempVal == 1) {
				resultBinaryStr += '1';
				carryBit = 0;
			}
			else if (tempVal == 2) {
				resultBinaryStr += '0';
				carryBit = 1;
			}
			else if (tempVal == 3) {
				resultBinaryStr += '1';
				carryBit = 1;
			}
		}

		if (carryBit) {
			resultBinaryStr += '1';
		}

		return reverseStr(resultBinaryStr);
	}
private:
	std::string reverseStr(std::string startStr) {
		std::string revStr = "";

		for (int i = startStr.length() - 1; i >= 0; i--) {
			revStr += startStr[i];
		}

		return revStr;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: a = "11", b = "1"
	Expected Output: "100"
	*/
	std::string testResult1 = solution.addBinary("11", "1");
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}