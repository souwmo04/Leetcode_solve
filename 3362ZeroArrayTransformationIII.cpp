from typing import List

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        m = len(queries)

        # Binary search on how many queries to keep (we'll subtract from total to get max removable)
        def can_convert(keep_queries: List[List[int]]) -> bool:
            diff = [0] * (n + 1)
            for l, r in keep_queries:
                diff[l] += 1
                if r + 1 < n:
                    diff[r + 1] -= 1

            coverage = [0] * n
            coverage[0] = diff[0]
            for i in range(1, n):
                coverage[i] = coverage[i - 1] + diff[i]

            for i in range(n):
                if coverage[i] < nums[i]:
                    return False
            return True

        # Binary search: find the **minimum number of queries** needed
        low, high = 0, m
        min_needed = -1

        while low <= high:
            mid = (low + high) // 2
            from itertools import combinations
            # Try all subsets of size mid is too expensive. Instead, just take first mid queries
            # in practice, shuffle the list or sort based on range length or some heuristic
            keep = queries[:mid]
            if can_convert(keep):
                min_needed = mid
                high = mid - 1
            else:
                low = mid + 1

        if min_needed == -1:
            return -1
        return m - min_needed
