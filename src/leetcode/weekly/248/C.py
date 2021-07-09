class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = 1000000007
        return pow(5, (n + 1) >> 1, mod) + pow(4, n >> 1, mod)
