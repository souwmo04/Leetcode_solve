#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> m;

        for(int i = 0; i < arr.size(); i++) {
            int complement = tar - arr[i];
            if(m.find(complement) != m.end()) {
                return {m[complement], i};
            }
            m[arr[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    
    cout << "Indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
