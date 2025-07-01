#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * Custom merge sort to sort the input array `nums` without using any built-in sort functions.
     * This is needed as per the assignment rules, and helps us sort the array for later binary search.
     */
    void mergeSort(vector<int>& nums, int left, int right) {
        if (right - left <= 1) return;

        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid, right);

        vector<int> temp;
        int i = left, j = mid;
        while (i < mid && j < right) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while (i < mid) temp.push_back(nums[i++]);
        while (j < right) temp.push_back(nums[j++]);

        for (int i = left; i < right; ++i) {
            nums[i] = temp[i - left];
        }
    }

    /**
     * Given a sorted array `nums`, this function returns how many pairs (i, j)
     * exist such that nums[j] - nums[i] <= mid. The two-pointer approach
     * is efficient here because the array is sorted.
     */
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > mid) {
                left++;
            }
            count += (right - left);
        }
        return count;
    }

    /**
     * This is the main function to find the k-th smallest pair distance.
     * It first sorts the array using merge sort, and then uses binary search
     * on the distance value (not index) to find the smallest value where
     * there are at least k pairs with distance <= mid.
     */
    int smallestDistancePair(vector<int>& nums, int k) {
        mergeSort(nums, 0, nums.size());  // Sort the array manually

        int low = 0;
        int high = nums.back() - nums.front(); // Max possible distance

        // Binary search to find the minimum distance such that
        // at least k pairs have distance <= mid
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countPairs(nums, mid);

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

// ---------------- DRIVER CODE (for local testing) ----------------
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1};
    int k = 1;

    int result = sol.smallestDistancePair(nums, k);

    cout << "The " << k << "-th smallest pair distance is: " << result << endl;

    return 0;
}
