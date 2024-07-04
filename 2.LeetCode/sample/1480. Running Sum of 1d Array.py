from typing import List


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        sum = 0
        sums = []
        for i in range(len(nums)):
            sum += nums[i]
            sums.append(sum)
        
        return sums

if __name__ == "__main__":
    solution = Solution()
    test_input = [1, 2, 3, 4]
    print("Input:", test_input)
    result = solution.runningSum(test_input)
    print("Output:", result)    