#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        // Apply difference array logic for range updates
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l] += 1;
            if (r + 1 < n) {
                diff[r + 1] -= 1;
            }
        }

        // Apply prefix sum to get total decrements at each index
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1];
        }

        // Check if nums[i] == number of decrements applied
        for (int i = 0; i < n; ++i) {
            if (nums[i] != diff[i]) {
                return false;
            }
        }

        return true;
    }
};
