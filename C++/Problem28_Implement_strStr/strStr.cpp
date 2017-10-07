/*
Implement strStr()

Returns the index of the first occurance of needle
in haystack, or -1 if needle is not part of haystack.
*/

#include <string>
#include <iostream>

class Solution {
public:
	int strStr(std::string haystack, std::string needle) {
		int needleFound = -1;
		std::string testStr;

		if (haystack.length() < needle.length()) {
			return needleFound;
		}

		if (haystack.length() == 0 && needle.length() == 0 || haystack == needle) {
			needleFound = 0;
		}

		for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
			testStr = haystack.substr(i, needle.length());
			if (testStr == needle) {
				return i;
			}
		}

		return needleFound;
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: "abcdefghi", "def"
	Expected Output: 3
	*/
	int testResult1 = solution.strStr("abcdefghi", "def");
	std::cout << "Test Result 1: " << testResult1 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}