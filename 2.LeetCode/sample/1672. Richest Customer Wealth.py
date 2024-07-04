from typing import List


class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        max = -1
        for c in accounts:
            sum = 0
            for a in c:
                sum += a
            if (sum > max):
                max = sum
        return max
        
        
        
if __name__ == "__main__":
    solution = Solution()
    test_input = [[1,2,3],[3,2,1]]
    print("Input:", test_input)
    result = solution.maximumWealth(test_input)
    print("Output:", result)            