/*
Problem 9 - Palindrome Number

Determine whether an integer is a palindrome. Do this without extra space.

*/

#include <iostream>
#include <string>

class Solution {
public:
	bool isPalindrome(int x) {
		std::string intStr = std::to_string(x);
		std::string revIntStr = "";

		for (int i = intStr.length() - 1; i >= 0; i--) {
			revIntStr += intStr[i];
		}

		return (intStr == revIntStr) ? 1 : 0;
	}

};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: 12321
	Expected Output: 1
	*/
	bool testResult1 = solution.isPalindrome(12321);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2:
	Input: 12345
	Expected Output: 0
	*/
	bool testResult2 = solution.isPalindrome(12345);
	std::cout << "Test Result 2: " << testResult2 << "\n";


	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}