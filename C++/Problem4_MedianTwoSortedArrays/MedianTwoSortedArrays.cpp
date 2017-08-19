/*
LeetCode - Problem 4 - Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size
m and n respectively.

Find the median of the two sorted arrays.
The overall run time complexity should be
O(log(m+n)).

*/

#include <stddef.h>
#include <vector>
#include <iostream>

class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		int totalNums = nums1.size() + nums2.size();
		int isEven;
		int medianIndex1;
		int medianIndex2;
		double medianValue;
		int nums1Index = 0;
		int nums2Index = 0;

		// Find index of median number(s)
		if (totalNums % 2) {
			isEven = 0;
			medianIndex1 = (totalNums / 2) + 1;
		}
		else {
			isEven = 1;
			medianIndex1 = (totalNums / 2) - 1;
			medianIndex2 = totalNums / 2;
		}

		for (int i = 0; i < medianIndex1; i++) {
			if ((nums2Index >= nums2.size()) || (nums1[nums1Index] < nums2[nums2Index])) {
				medianValue = nums1[nums1Index];
				nums1Index++;
			}
			else if ((nums1Index >= nums1.size()) || (nums1[nums1Index] > nums2[nums2Index])) {
				medianValue = nums2[nums2Index];
				nums2Index++;
			}
		}

		return medianValue;
	}
};


int main() {
	Solution solution;

	/* 
	Test Case 1:
	 nums1 = [1, 3]
	 nums2 = [2]
	 Expected Median: 2.0
	 */
	
	std::vector<int> nums1 = { 1, 3 };
	std::vector<int> nums2 = { 2 };

	double result = solution.findMedianSortedArrays(nums1, nums2);
	std::cout << "Result: " << result << "\n";

	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}