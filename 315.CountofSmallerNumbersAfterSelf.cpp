class Solution {
public:
    struct Pair {
        int val;
        int index;
    };

    void mergeSort(vector<Pair>& pairs, int left, int right, vector<int>& counts) {
        if (right - left <= 1) return;

        int mid = left + (right - left) / 2;
        mergeSort(pairs, left, mid, counts);
        mergeSort(pairs, mid, right, counts);

        vector<Pair> temp;
        int i = left, j = mid;
        int rightCount = 0;

        while (i < mid && j < right) {
            if (pairs[i].val <= pairs[j].val) {
                counts[pairs[i].index] += rightCount;
                temp.push_back(pairs[i++]);
            } else {
                rightCount++;
                temp.push_back(pairs[j++]);
            }
        }

        while (i < mid) {
            counts[pairs[i].index] += rightCount;
            temp.push_back(pairs[i++]);
        }

        while (j < right) {
            temp.push_back(pairs[j++]);
        }

        for (int k = left; k < right; ++k) {
            pairs[k] = temp[k - left];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<Pair> pairs(n);
        vector<int> counts(n, 0);

        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums[i], i};
        }

        mergeSort(pairs, 0, n, counts);

        return counts;
    }
};
