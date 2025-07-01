#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * This function recursively sorts the prefix sum array from index left to right,
     * and simultaneously counts the number of valid range sums that fall within [lower, upper].
     * A valid range sum is found by checking, for each left-half element, how many right-half
     * elements fall within the difference range [prefix[j] - upper, prefix[j] - lower].
     * This is done efficiently using two pointers since both halves are sorted during merge sort.
     */
    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;  // Base case: one element → no range sum

        int mid = (left + right) / 2;
        int count = mergeSort(prefix, left, mid, lower, upper) +
                    mergeSort(prefix, mid, right, lower, upper);

        int j = mid, k = mid;
        for (int i = left; i < mid; ++i) {
            // Move k until prefix[k] - prefix[i] >= lower
            while (k < right && prefix[k] - prefix[i] < lower) ++k;
            // Move j until prefix[j] - prefix[i] > upper
            while (j < right && prefix[j] - prefix[i] <= upper) ++j;
            count += (j - k);
        }

        // Standard merge step to keep prefix sorted
        vector<long long> temp;
        int i = left, r = mid;
        while (i < mid && r < right) {
            if (prefix[i] <= prefix[r]) temp.push_back(prefix[i++]);
            else temp.push_back(prefix[r++]);
        }
        while (i < mid) temp.push_back(prefix[i++]);
        while (r < right) temp.push_back(prefix[r++]);

        // Copy back sorted result
        for (int i = left; i < right; ++i) {
            prefix[i] = temp[i - left];
        }

        return count;
    }

    /**
     * This function first converts the input array into a prefix sum array,
     * which allows calculation of any subarray sum in O(1). Then it calls
     * the modified merge sort to count the number of subarray sums that lie
     * within the range [lower, upper]. The result is returned as the final count.
     */
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0); // Prefix sum array with prefix[0] = 0

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i]; // Build prefix sum
        }

        return mergeSort(prefix, 0, prefix.size(), lower, upper);
    }
};

// ------------- DRIVER CODE (for local testing) ----------------
int main() {
    Solution sol;

    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;

    int result = sol.countRangeSum(nums, lower, upper);

    cout << "Count of range sums within [" << lower << ", " << upper << "]: " << result << endl;

    return 0;
}
