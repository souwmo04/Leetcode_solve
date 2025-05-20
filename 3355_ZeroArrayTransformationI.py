#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> allowed(n + 1, 0); // Difference array

        // Process queries: for each [l, r], mark +1 at l and -1 at r+1
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            allowed[l] += 1;
            if (r + 1 < n) {
                allowed[r + 1] -= 1;
            }
        }

        // Convert difference array to prefix sum
        for (int i = 1; i < n; ++i) {
            allowed[i] += allowed[i - 1];
        }

        // Now allowed[i] means how many times we can decrement nums[i]
        for (int i = 0; i < n; ++i) {
            if (nums[i] > allowed[i]) {
                return false;
            }
        }

        return true;
    }
};
