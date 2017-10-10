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

		long long absDividendLeft = abs((long long)dividend);
		long long absDivisor = abs((long long)divisor);

		bool dividendNegative = dividend < 0;
		bool divisorNegative = divisor < 0;

		/*
		std::cout << absDividendLeft << "\n";
		std::cout << absDivisor << "\n";

		std::cout << dividendNegative << "\n";
		std::cout << divisorNegative << "\n";
		*/

		if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
			return INT_MAX;
		}

		if (dividend == 0) {
			return 0;
		}
		else if (dividendNegative && divisorNegative) {
			signValue = 1;
		}
		else if (dividendNegative || divisorNegative) {
			signValue = -1;
		}

		while (absDividendLeft >= absDivisor) {
			divisorCount++;
			absDividendLeft -= absDivisor;
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
	int testResult1 = solution.divide(-2147483648, 1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key...\n";
	std::cin.get();
	return 0;
}