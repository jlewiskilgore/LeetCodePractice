/*
Problem 22 - Generate Parentheses

Given n pairs of parentheses, write a function to generate
all combinations of well-formed parentheses.

For example, given n =3, a solution set is:
[
	"((()))",
	"(()())",
	"(())()",
	"()(()),
	"()()()
]
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> resultCombinations;

		// Return empty vector
		if (n == 0) {
			return resultCombinations;
		}

		genParenHelper("", 0, 0, n, resultCombinations);

		return resultCombinations;
	}

private:
	void genParenHelper(std::string startStr, int numLeft, int numRight, int &n, std::vector<std::string> &resCombos) {
		// Number left parentheses is greater than n, there are not enough right parentheses
		if (numLeft > n) {
			return;
		}
		// Valid String Found when parenthes counts are equal
		if (numLeft == n && numRight == n) {
			resCombos.push_back(startStr);
		}
		else {
			// Consider case adding one more left parenthesis
			genParenHelper(startStr+"(", numLeft+1, numRight, n, resCombos);
			
			// Consider case adding one more right parenthesis,
			// if there are currently more left than right parenthesis currently
			if (numLeft > numRight) {
				genParenHelper(startStr+")", numLeft, numRight+1, n, resCombos);
			}
		}
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: n = 3
	Expect Output:
		[
			"((()))",
			"(()())",
			"(())()",
			"()(()),
			"()()()
		]
	*/
	std::vector<std::string> testResult1 = solution.generateParenthesis(3);
	std::cout << "Test Result 1: [ ";
	for (int i = 0; i < testResult1.size(); i++) {
		std::cout << testResult1[i];
		if (i != testResult1.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << " ]\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}