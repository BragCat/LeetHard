class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        str_n = str(N)
        l = len(str_n)
        cnt = 0
        for i in range(1, min(l, 10)):
            cnt += 9 * self.permutationNumber(9, i - 1)
        if l <= 10:
            digits = set()
            for i in range(0, l):
                t = 1 if not 0 in digits and str_n[i] != '0' and i != 0 else 0
                for j in range(1, int(str_n[i])):
                    if not j in digits:
                        t += 1
                cnt += t * self.permutationNumber(9 - i, l - i - 1) 
                if int(str_n[i]) in digits:
                    break
                digits.add(int(str_n[i]))
            if len(digits) == l:
                cnt += 1
        return N - cnt
        
    def permutationNumber(self, m: int, n: int) -> int:
        ans = 1
        for i in range(m - n + 1, m + 1):
            ans *= i
        return ans