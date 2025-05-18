class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        MOD = 10**9 + 7
        from itertools import product

        def is_valid(col):
            return all(col[i] != col[i+1] for i in range(len(col) - 1))

        colors = [0, 1, 2]
        states = [s for s in product(colors, repeat=m) if is_valid(s)]
        k = len(states)
        state_idx = {state: i for i, state in enumerate(states)}

        compatible = [[] for _ in range(k)]
        for i, s1 in enumerate(states):
            for j, s2 in enumerate(states):
                if all(s1[x] != s2[x] for x in range(m)):
                    compatible[i].append(j)

        dp = [1] * k
        for _ in range(1, n):
            new_dp = [0] * k
            for i in range(k):
                for j in compatible[i]:
                    new_dp[i] = (new_dp[i] + dp[j]) % MOD
            dp = new_dp

        return sum(dp) % MOD
