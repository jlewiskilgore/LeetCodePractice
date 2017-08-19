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
		int searchCounter;
		double medianValue;
		double firstEvenMedianValue;
		int nums1Index = 0;
		int nums2Index = 0;

		// Find index of median number(s)
		if (totalNums % 2) {
			isEven = 0;
			medianIndex1 = (totalNums / 2) + 0.5;
			searchCounter = medianIndex1;
		}
		else {
			isEven = 1;
			medianIndex1 = (totalNums / 2) - 1;
			medianIndex2 = (totalNums / 2);
			searchCounter = medianIndex2;
		}
		
		for (int i = 0; i <= searchCounter; i++) {

			if (isEven && i == searchCounter) {
				firstEvenMedianValue = medianValue;
			}

			// Check if either array has been fully searched already
			if (nums1Index >= nums1.size()) {
				medianValue = nums2[nums2Index];
				nums2Index++;
			}
			else if (nums2Index >= nums2.size()){
				medianValue = nums1[nums1Index];
				nums1Index++;
			}
			// Compare elements to find next "searched"
			else if (nums1[nums1Index] < nums2[nums2Index]) {
				medianValue = nums1[nums1Index];
				nums1Index++;
			}
			else if (nums1[nums1Index] > nums2[nums2Index]) {
				medianValue = nums2[nums2Index];
				nums2Index++;
			}
		}

		return isEven ? (firstEvenMedianValue + medianValue) / 2.0 : medianValue;
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
	
	std::vector<int> test1_nums1 = { 1, 3 };
	std::vector<int> test1_nums2 = { 2 };

	double test1_result = solution.findMedianSortedArrays(test1_nums1, test1_nums2);
	std::cout << "Result: " << test1_result << "\n";

	/*
	Test Case 2:
	 nums1 = [1, 2]
	 nums2 = [3, 4]
	 Expected Median: 2.5
	*/

	std::vector<int> test2_nums1 = { 1, 2 };
	std::vector<int> test2_nums2 = { 3, 4 };

	double test2_result = solution.findMedianSortedArrays(test2_nums1, test2_nums2);
	std::cout << "Result: " << test2_result << "\n";

	/*
	Test Case 3:
	nums1 = []
	nums2 = [2]
	Expected Median: 2
	*/

	std::vector<int> test3_nums1 = { };
	std::vector<int> test3_nums2 = { 2 };

	double test3_result = solution.findMedianSortedArrays(test3_nums1, test3_nums2);
	std::cout << "Result: " << test3_result << "\n";

	/*
	Test Case 4:
	nums1 = [1]
	nums2 = [1]
	Expected Median: 1
	*/

	std::vector<int> test4_nums1 = { 1 };
	std::vector<int> test4_nums2 = { 1 };

	//double test4_result = solution.findMedianSortedArrays(test4_nums1, test4_nums2);
	//std::cout << "Result: " << test4_result << "\n";



	std::cout << "Press any key to exit...\n";
	std::cin.get();
	return 0;
}