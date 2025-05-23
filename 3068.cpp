class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long baseSum = 0;
        vector<int> diffs;
        
        for (int num : nums) {
            baseSum += num;
            diffs.push_back((num ^ k) - num);
        }
        
        // Total gain if we apply XOR on selected nodes
        long long gain = 0;
        int count = 0;
        int minAbs = INT_MAX;
        
        for (int d : diffs) {
            if (d > 0) {
                gain += d;
                count++;
            }
            minAbs = min(minAbs, abs(d));
        }
        
        // If count is even, apply all positive gain diffs
        // If odd, remove the smallest absolute delta to make it even
        if (count % 2 == 0) {
            return baseSum + gain;
        } else {
            return baseSum + gain - minAbs;
        }
    }
};
