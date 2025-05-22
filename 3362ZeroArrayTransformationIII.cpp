
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        // Sort the queries based on starting index
        sort(queries.begin(), queries.end());

        // Max-heap for available queries (based on end index)
        priority_queue<int> available;

        // Min-heap for running/used queries (based on end index)
        priority_queue<int, vector<int>, greater<int>> running;

        int j = 0;

        for (int i = 0; i < n; ++i) {
            // Add all queries that start at or before index i
            while (j < q && queries[j][0] <= i) {
                available.push(queries[j][1]);
                ++j;
            }

            // Remove expired queries from running heap
            while (!running.empty() && running.top() < i) {
                running.pop();
            }

            // We need at least nums[i] valid queries covering index i
            while ((int)running.size() < nums[i]) {
                if (available.empty()) return -1;
                int end = available.top(); available.pop();
                if (end < i) return -1; // This query cannot cover index i
                running.push(end);
            }
        }

        // All unused queries in `available` can be removed
        return (int)available.size();
    }
};