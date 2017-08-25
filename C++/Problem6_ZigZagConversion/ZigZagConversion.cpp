/*
LeetCode - Problem 6 - Zig Zag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given
number of rows like this:

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given
a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

*/

#include <stddef.h>
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
	std::string convert(std::string s, int numRows) {
		std::string resultStr = "";
		int currRow = 1;
		int fillDirection = 0; // 0 = down, 1 = up
		std::vector<std::string> strArr = {};

		if (numRows == 1) {
			return s;
		}

		for (int i = 0; i < numRows; i++) {
			std::string newRow = "";
			strArr.push_back(newRow);
		}

		for (int i = 0; i < s.length(); i++) {
			std::cout << currRow << "\n";
			strArr[currRow - 1] += s[i];

			if (currRow == numRows || (currRow == 1 && fillDirection)) {
				fillDirection ? fillDirection = 0 : fillDirection = 1;
			}

			fillDirection ? currRow-- : currRow++;
		}

		resultStr = strArr[0] + strArr[1] + strArr[2];

		return resultStr;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: PAYPALISHIRING, 3
	Expected Output: PAHNAPLSIIGYIR
	*/
	std::string testInput1 = "PAYPALISHIRING";
	int test1NumRows = 3;
	std::string testResult1 =  solution.convert(testInput1, test1NumRows);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}

