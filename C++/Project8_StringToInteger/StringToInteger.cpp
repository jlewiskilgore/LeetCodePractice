/*
Problem 8 - String to Integer

Implement atoi to convert a string to an integer
*/

#include <string>
#include <iostream>

class Solution {
public:
	int myAtoi(std::string str) {
		long long resultInt = 0;
		int signValue = 0;
		int startIndex = 0;

		while (isspace(str[startIndex])) {
			startIndex++;
		}

		for (int i = startIndex; i < str.length(); i++) {
			// Found non digit, non sign character
			if ((signValue && !isdigit(str[i])) ||
			   (!signValue && !isdigit(str[i]) && str[i] != '+' && str[i] != '-')) {
				
				return convertOverflowInt(resultInt * signValue);
			}

			// Check for sign
			if (!signValue && str[i] == '-') {
				signValue = -1;
			}
			else if(!signValue){
				signValue = 1;
			}
			
			if (isdigit(str[i])) {
				// Decimal representation of char '0' is 48
				resultInt = (resultInt * 10) + str[i] - '0';
			}

			if (resultInt >= INT_MAX || resultInt <= INT_MIN) {
				return convertOverflowInt(resultInt * signValue);
			}
		}

		resultInt = convertOverflowInt(resultInt * signValue);

		return resultInt;
	}

private:
	long long convertOverflowInt(long long startingInt) {
		long long convertedInt = startingInt;

		if (convertedInt >= INT_MAX) {
			convertedInt = INT_MAX;
		}
		else if (convertedInt <= INT_MIN) {
			convertedInt = INT_MIN;
		}

		return convertedInt;
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

	/*
	Test Case 2:
	Input: "123"
	Expected Output: 123
	*/
	int testResult2 = solution.myAtoi("-123");
	std::cout << "Test Result 2: " << testResult2 << "\n";

	/*
	Test Case 3:
	Input: "123abc"
	Expected Output: 0
	*/
	int testResult3 = solution.myAtoi("123abc");
	std::cout << "Test Result 3: " << testResult3 << "\n";

	/*
	Test Case 4:
	Input: "-2147483648"
	Expected Output: -2147483648
	*/
	int testResult4 = solution.myAtoi("-2147483648");
	std::cout << "Test Result 4: " << testResult4 << "\n";

	/*
	Test Case 5:
	Input: " b11228552307"
	Expected Output: 0
	*/
	int testResult5 = solution.myAtoi(" b11228552307");
	std::cout << "Test Result 5: " << testResult5 << "\n";

	/*
	Test Case 6:
	Input: "2147483648"
	Expected Output: 2147483647
	*/
	int testResult6 = solution.myAtoi("2147483648");
	std::cout << "Test Result 6: " << testResult6 << "\n";

	/*
	Test Case 7:
	Input: "9223372036854775809"
	Expected Output: 2147483647
	*/
	int testResult7 = solution.myAtoi("9223372036854775809");
	std::cout << "Test Result 7: " << testResult7 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}
