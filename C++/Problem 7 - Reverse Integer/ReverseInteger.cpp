/*
Problem 7 - Reverse Integer

Reverse digits of an integer.

*/

#include <iostream>
#include <string>

class Solution {
public:
	int reverse(int x) {
		std::string intStr;
		std::string resultStr = "";
		int result; 
		int isNegative = 0;

		if (x < 0) {
			isNegative = 1;
			intStr = std::to_string(x * -1);
		}
		else {
			intStr = std::to_string(x);
		}

		for (int i = intStr.length() - 1; i >= 0; i--) {
			resultStr += intStr[i];
		}

		result = stoi(resultStr);

		return isNegative ? result * -1 : result;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: 123
	Expected Output: 321
	*/
	int testResult1 = solution.reverse(123);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2:
	Input: 1534236469
	Expected Output:
	*/
	int testResult2 = solution.reverse(1534236469);
	std::cout << "Test Result 2: " << testResult2 << "\n";
	
	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}