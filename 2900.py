class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        res = []
        prev_group = None
        
        for i in range(len(words)):
            if prev_group is None or groups[i] != prev_group:
                res.append(words[i])
                prev_group = groups[i]
        
        return res
