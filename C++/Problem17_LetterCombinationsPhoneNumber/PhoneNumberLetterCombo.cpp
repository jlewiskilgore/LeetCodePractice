/*
Problem 17 - Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations
that the number could represent.

A mapping of digit letters (just like on the telephone buttons)
is given below:

1: none
2: a b c
3: d e f
4: g h i
5: j k l
6: m n o
7: p q r s
8: t u v
9: w x y z

*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	std::vector<std::string> letterCombinations(std::string digits) {
		std::vector<std::string> resultLetterCombos = {};
		std::vector<std::string> newCombos;
		int digit;
		std::string digitString;

		if (digits == "") {
			return resultLetterCombos;
		}

		std::vector<std::string> numberToLetter = {
			"",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz"
		};

		resultLetterCombos.push_back("");

		for (int i = 0; i < digits.length(); i++) {
			digit = digits[i] - '0';
			digitString = numberToLetter[digit - 1];
			newCombos = {};

			for (int j = 0; j < digitString.length(); j++) {
				for (int k = 0; k < resultLetterCombos.size(); k++) {
					newCombos.push_back(resultLetterCombos[k] + digitString[j]);
				}
			}
			resultLetterCombos.swap(newCombos);
		}

		return resultLetterCombos;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1
	Input: "23"
	Expected Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
	*/
	std::vector<std::string> testResult1 = solution.letterCombinations("23");
	std::cout << "[ ";
	for (int i = 0; i < testResult1.size(); i++) {
		std::cout << '\"' << testResult1[i] << '\"' << " ";
	}
	std::cout << "]\n";

	/*
	Test Case 2
	Input: ""
	Expected Output: []
	*/
	std::vector<std::string> testResult2 = solution.letterCombinations("");
	std::cout << "[ ";
	for (int i = 0; i < testResult2.size(); i++) {
		std::cout << '\"' << testResult2[i] << '\"';
	}
	std::cout << " ]\n";


	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}