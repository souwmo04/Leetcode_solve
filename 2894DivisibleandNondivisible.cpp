class Solution {
public:
    int differenceOfSums(int n, int m) {
        // Total sum from 1 to n
        int totalSum = n * (n + 1) / 2;

        // Number of integers divisible by m
        int k = n / m;

        // Sum of numbers divisible by m
        int divSum = m * k * (k + 1) / 2;

        // Sum of numbers not divisible by m
        int nonDivSum = totalSum - divSum;

        // Return the difference
        return nonDivSum - divSum;
    }
};
