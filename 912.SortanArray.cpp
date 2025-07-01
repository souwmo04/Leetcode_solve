#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Recursively sorts the subarray nums[left:right) using merge sort.
     * The array is split into halves, each sorted recursively,
     * then merged back into sorted order.
     *
     * @param nums Reference to the vector to be sorted.
     * @param left The start index of the subarray.
     * @param right The end index (exclusive) of the subarray.
     */
    void mergeSort(vector<int>& nums, int left, int right) {
        if (right - left <= 1) return; // Base case: single element is sorted

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);  // Sort left half
        mergeSort(nums, mid, right); // Sort right half

        vector<int> temp; // Temp vector to store merged sorted elements
        int i = left, j = mid;

        // Merge two sorted halves
        while (i < mid && j < right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        // Append remaining elements from left half
        while (i < mid) temp.push_back(nums[i++]);
        // Append remaining elements from right half
        while (j < right) temp.push_back(nums[j++]);

        // Copy back the merged result into original array
        for (int k = left; k < right; ++k) {
            nums[k] = temp[k - left];
        }
    }

    /**
     * Public function that sorts the entire input vector using merge sort.
     *
     * @param nums Vector of integers to be sorted.
     * @return Sorted vector of integers.
     */
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size());
        return nums;
    }
};

