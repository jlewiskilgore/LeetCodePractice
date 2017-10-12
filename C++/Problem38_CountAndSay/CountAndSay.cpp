/*
Problem 38 - Count and Say

The count-and-say sequence is the sequence of integers
with the first five terms as following:

1.	1
2.	11
3.	21
4.	1211
5.	111221

1 is read off as "one 1" of 11
11 is read off as "two 1s" or 21
21 is read off as "one 2, then one 1" or 1211

Given an integer n, generate the nth term of the
count-and-say sequence.

Note: Each term of the sequence of integers will
be represented as a string
*/

#include <string>
#include <iostream>

class Solution {
public:
	std::string countAndSay(int n) {
		if (n == 0) {
			return "";
		}
		std::string resultStr = "1";

		for (int i = 0; i < n; i++) {
			std::string tempStr = "";
			
			//Loop through resultStr

			//Count number of repeated values

			//Print to tempStr in from count of int adjacent + value of int

			//Set resultStr to tempStr just built
		}

		return resultStr;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: 4
	Expected Output: 1211
	*/
	std::string testResult1 = solution.countAndSay(4);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}