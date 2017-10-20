/*
Proble 69 - Sqrt(x)

Implement int sqrt(int x)

Compute and return the square root of x
*/

#include <iostream>

class Solution {
public:
	int mySqrt(int x) {
		int resultSqrt;
		if (x == 0 || x == 1) {
			return x;
		}
		else if (x == 2) {
			return 1;
		}

		for (int i = 1; i < x; i++) {
			if ((i * i) == x) {
				return i;
			}
			else if ((i * i) > x) {
				resultSqrt = i - 1;
				break;
			}
		}

		return resultSqrt;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: 0
	Expected Output: 0
	*/
	int testResult1 = solution.mySqrt(0);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}