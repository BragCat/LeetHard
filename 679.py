class Solution:
    EPSILON = 1e-6
    TARGET = 24
    
    def judgePoint24(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return abs(nums[0] - self.TARGET) <= self.EPSILON
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                new_nums = []
                for k in range(len(nums)):
                    if k != i and k != j:
                        new_nums.append(nums[k])
                for op in range(4):
                    if op == 0:
                        new_nums.append(nums[i] + nums[j])
                        if self.judgePoint24(new_nums):
                            return True
                        new_nums.pop()
                    elif op == 1:
                        new_nums.append(nums[i] - nums[j])
                        if self.judgePoint24(new_nums):
                            return True
                        new_nums[-1] = nums[j] - nums[i]
                        if self.judgePoint24(new_nums):
                            return True
                        new_nums.pop()
                    elif op == 2:
                        new_nums.append(nums[i] * nums[j])
                        if self.judgePoint24(new_nums):
                            return True
                        new_nums.pop()
                    else:
                        if nums[j] != 0:
                            new_nums.append(nums[i] / nums[j])
                            if self.judgePoint24(new_nums):
                                return True
                            new_nums.pop()
                        if nums[i] != 0:
                            new_nums.append(nums[j] / nums[i])
                            if self.judgePoint24(new_nums):
                                return True
                            new_nums.pop()
        return False