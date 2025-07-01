#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * This function recursively applies merge sort on the input array `nums` from index `left` to `right`,
     * and counts the number of reverse pairs (i < j and nums[i] > 2 * nums[j]) during the merge step.
     * The array is split into two halves, and each half is sorted recursively. While merging the two halves,
     * we count the number of reverse pairs where an element from the left half is greater than twice an element
     * from the right half. After counting, we merge both sorted halves into a single sorted array.
     */
    int mergeSort(vector<int>& nums, int left, int right) {
        if (right - left <= 1) return 0; // Base case: one or no element

        int mid = left + (right - left) / 2;
        int count = 0;

        // Count reverse pairs in left and right halves recursively
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid, right);

        // Count reverse pairs across the halves
        int j = mid;
        for (int i = left; i < mid; ++i) {
            while (j < right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - mid);
        }

        // Merge two sorted halves
        vector<int> temp;
        int i = left;
        j = mid;
        while (i < mid && j < right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while (i < mid) temp.push_back(nums[i++]);
        while (j < right) temp.push_back(nums[j++]);

        // Copy merged result back into original array
        for (int k = left; k < right; ++k) {
            nums[k] = temp[k - left];
        }

        return count;
    }

    /**
     * The reversePairs function serves as the entry point to count all reverse pairs in the input array.
     * It initializes the recursive merge sort from index 0 to n and returns the total number of reverse pairs.
     * This function avoids brute-force pair comparisons by utilizing an efficient divide-and-conquer strategy.
     */
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size());
    }
};

