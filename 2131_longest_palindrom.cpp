class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int length = 0;
        bool hasMiddle = false;

        // Count frequency of each word
        for (string& word : words) {
            count[word]++;
        }

        for (auto& [word, freq] : count) {
            string rev = string(word.rbegin(), word.rend());

            if (word != rev) {
                if (count.find(rev) != count.end()) {
                    int pairs = min(freq, count[rev]);
                    length += pairs * 4;
                    count[word] -= pairs;
                    count[rev] -= pairs;
                }
            } else {
                int pairs = freq / 2;
                length += pairs * 4;
                count[word] -= pairs * 2;
                if (count[word] > 0) {
                    hasMiddle = true;
                }
            }
        }

        if (hasMiddle) {
            length += 2;
        }

        return length;
    }
};
