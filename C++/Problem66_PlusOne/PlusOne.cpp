/*
Problem 66 - Plus One

Given a non-negative integer represented as a non-empty
array of digits, plus one to the integer.

You may assum the integer do not contain any leading zero,
except the number 0 itself.

The digits are stored such that the most significant digit
is at the head of the list.
*/

#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& digits) {
		std::vector<int> resultVector = {};
		int carryDigit = 0;
		int tempValue;

		// Add one to last digit and carry digit
		if (digits[digits.size() - 1] == 9) {
			carryDigit = 1;
			digits[digits.size() - 1] = 0;
		}
		else {
			digits[digits.size() - 1] += 1;
		}
		resultVector.insert(resultVector.begin(), digits[digits.size() - 1]);

		for (int i = digits.size() - 1; i > 0; i--) {
			tempValue = digits[i - 1] + carryDigit;

			if (tempValue == 10) {
				carryDigit = 1;
				tempValue = 0;
			}
			else {
				carryDigit = 0;
			}

			resultVector.insert(resultVector.begin(), tempValue);
		}

		// Add extra value if carry still exists
		if (carryDigit) {
			resultVector.insert(resultVector.begin(), 1);
		}

		return resultVector;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: [0, 1, 2]
	Expected Output: [0, 1, 3]
	*/
	std::vector<int> testInput1 = { 0, 1, 2 };
	std::vector <int> testResult1 = solution.plusOne(testInput1);

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}