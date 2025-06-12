class Solution {
public:
    int maxDifference(string s) {
        int counts[26] = {};  // Array to store count of each lowercase letter
      
        // Count occurrences of each character in the string
        for (char c : s) {
            ++counts[c - 'a'];
        }
      
        int maxOddCount = 0;              // Maximum count of characters with odd occurrence
        int minEvenCount = 1 << 30;       // Minimum count of characters with even occurrence

        // Iterate through the counts array
        for (int count : counts) {
            // If the count is odd and greater than current maxOddCount, update maxOddCount
            if (count % 2 == 1) {
                maxOddCount = max(maxOddCount, count);
            }
            // If the count is even and greater than zero, update minEvenCount with the smaller value
            else if (count > 0) {
                minEvenCount = min(minEvenCount, count);
            }
        }
      
       return maxOddCount - minEvenCount;  // Return the difference between max odd count and min even count
    }
};