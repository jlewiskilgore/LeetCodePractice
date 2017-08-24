/*
Problem 5 - Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s.
You may assume the maximum length of s is 1000.

*/

#include <stddef.h>
#include <string>
#include <iostream>

class Solution {
public:
	std::string longestPalindromeBruteForce(std::string s) {
		int lengthLongSubstr = 0;
		std::string longSubstr = "";
		
		for (int i = 0; i < s.length(); i++) {
			for (int j = i; j < s.length(); j++) {
				std::string result = isSubstringPalindrome(s, i, j);
				if (result.length() > lengthLongSubstr) {
					lengthLongSubstr = result.length();
					longSubstr = result;
					//std::cout << "new result: " << longSubstr << "\n";
				}
			}
		}
		return longSubstr;
	}

private:
	std::string isSubstringPalindrome(std::string fullStr, int startIndex, int endIndex) {
		std::string subStr = fullStr.substr(startIndex, (endIndex - startIndex + 1));
		std::string revStr = subStr;

		std::reverse(revStr.begin(), revStr.end());

		return (subStr == revStr)? subStr : "";
	}
};

int main() {
	Solution solution;

	/*
	Test Case 1:
	Input: "babad"
	Expected Output: "bab" or "aba"
	*/
	std::string testInput1("babad");
	std::string testResult1 = solution.longestPalindromeBruteForce(testInput1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2:
	Input: "cbbd"
	Expected Output: "bb"
	*/
	std::string testInput2("cbbd");
	std::string testResult2 = solution.longestPalindromeBruteForce(testInput2);
	std::cout << "Test Result 2: " << testResult2 << "\n";

	/*
	Test Case 3:
	Input: "jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkq
	jqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovi
	lthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgj
	ryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfytt
	evqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatud
	jihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshx
	qkgbhoscjgpiel"
	*/
	std::string testInput3("jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel");
	std::string testResult3 = solution.longestPalindromeBruteForce(testInput3);
	std::cout << "Test Result 3: " << testResult3 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}