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
	std::string longestPalindrome(std::string s) {
		int leftIndex;
		int rightIndex;
		std::string longSubstr = "";
		std::string currSubstr;

		// Odd palidromes (one center)
		for (int i = 0; i <= s.length(); i++) {
			currSubstr = "";
			leftIndex = i;
			rightIndex = i;

			while (leftIndex >= 0 && rightIndex <= s.length() && (s[leftIndex] == s[rightIndex])) {
				currSubstr = s.substr(leftIndex, (rightIndex - leftIndex + 1));
				leftIndex--;
				rightIndex++;
			}

			if (currSubstr.length() == 0) {
				currSubstr = s.substr(leftIndex, (rightIndex - leftIndex + 1));
			}

			if (currSubstr.length() > longSubstr.length()) {
				longSubstr = currSubstr;
			}
		}

		// Even palidromes (two centers)
		for (int i = 1; i <= s.length(); i++) {
			currSubstr = "";
			leftIndex = i - 1;
			rightIndex = i;

			while (leftIndex >= 0 && rightIndex <= s.length() && (s[leftIndex] == s[rightIndex])) {
				currSubstr = s.substr(leftIndex, (rightIndex - leftIndex + 1));
				leftIndex--;
				rightIndex++;
			}

			if (currSubstr.length() == 0 && (s[leftIndex] == s[rightIndex])) {
				currSubstr = s.substr(leftIndex, (rightIndex - leftIndex + 1));
			}

			if (currSubstr.length() > longSubstr.length()) {
				longSubstr = currSubstr;
			}
		}

		return longSubstr;
	}

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
	//std::string testResult1 = solution.longestPalindromeBruteForce(testInput1);
	std::string testResult1 = solution.longestPalindrome(testInput1);
	std::cout << "Test Result 1: " << testResult1 << "\n";

	/*
	Test Case 2:
	Input: "cbbd"
	Expected Output: "bb"
	*/
	
	std::string testInput2("cbbd");
	std::string testResult2 = solution.longestPalindrome(testInput2);
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
	std::string testResult3 = solution.longestPalindrome(testInput3);
	std::cout << "Test Result 3: " << testResult3 << "\n";

	/*
	Test Case 4:
	Input: "ccc"
	Expected Output: "ccc"
	*/
	
	std::string testInput4("ccc");
	std::string testResult4 = solution.longestPalindrome(testInput4);
	std::cout << "Teste Result 4: " << testResult4 << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}