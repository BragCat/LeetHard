class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        intervals = []
        for i, r in enumerate(ranges):
            intervals.append([i - r, i + r])
        intervals = sorted(intervals, key = lambda interval: interval[0])
        ans = 0
        position = 0
        i = 0
        while i < n + 1 and position < n:
            next_position = position
            while i < n + 1 and position >= intervals[i][0]:
                next_position = max(next_position, intervals[i][1])
                i += 1
            if next_position == position:
                return -1
            position = next_position
            ans += 1
        if position < n:
            return -1
        else:
            return ans