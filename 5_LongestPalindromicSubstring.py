class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expandAroundCenter(left: int, right: int) -> str:
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1:right]  # The actual palindrome

        longest = ""
        for i in range(len(s)):
            # Odd length palindrome
            p1 = expandAroundCenter(i, i)
            # Even length palindrome
            p2 = expandAroundCenter(i, i + 1)

            if len(p1) > len(longest):
                longest = p1
            if len(p2) > len(longest):
                longest = p2

        return longest       

        