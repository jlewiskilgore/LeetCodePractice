/*
Problem 8 - String to Integer

Implement atoi to convert a string to an integer
*/

#include <string>
#include <iostream>

class Solution {
public:
	int myAtoi(std::string str) {
		int resultInt = 0;
		int signValue = 0;
		int startIndex = 0;

		while (isspace(str[startIndex])) {
			startIndex++;
		}

		for (int i = startIndex; i < str.length(); i++) {
			if (!signValue && str[i] == '-') {
				signValue = -1;
			}
			else if(!signValue){
				signValue = 1;
			}
		}

		return (resultInt * signValue);
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: ""
	Expected Output: 0
	*/
	int testResult1 = solution.myAtoi("");
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}
