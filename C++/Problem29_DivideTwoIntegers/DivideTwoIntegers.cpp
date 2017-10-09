/*
Problem 29 - Divide Two Integers

Divide two integers without using multiplication,
division and mod operator.

If it is overflow, return MAX_INT
*/

#include <iostream>

class Solution {
public:
	int divide(int dividend, int divisor) {
		int divisorCount = 0;
		int tempDivisor = divisor;
		int dividendLeft = dividend;
		int signValue = 1;

		if (dividend == 0) {
			return 0;
		}
		else if (dividend < 0 && divisor < 0) {
			tempDivisor = tempDivisor * -1;
			dividendLeft = dividendLeft * -1;
		}
		else if (dividend < 0 || divisor < 0) {
			signValue = -1;

			if (divisor < 0) {
				tempDivisor = tempDivisor * -1;
			}
			else {
				dividendLeft = dividendLeft * -1;
			}

			std::cout << dividendLeft << " " << tempDivisor << "\n";
		}

		while (dividendLeft >= tempDivisor) {
			divisorCount++;
			dividendLeft -= tempDivisor;
		};

		return divisorCount * signValue;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: 6 / 2
	Expected Output: 3
	*/
	int testResult1 = solution.divide(-1, -1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key...\n";
	std::cin.get();
	return 0;
}