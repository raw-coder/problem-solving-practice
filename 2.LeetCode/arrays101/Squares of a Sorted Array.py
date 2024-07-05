from typing import List 

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = 0
        right = n - 1
        pos = right
        arr = [0] * n
        while left <= right:
            leftSquare = nums[left] * nums[left]
            rightSquare = nums[right] * nums[right]
            if (leftSquare > rightSquare):
                arr[pos] = leftSquare
                left += 1
            else:
                arr[pos] = rightSquare
                right -= 1
            pos -= 1 
        return arr
    
if __name__ == "__main__":
    solution = Solution()
    input = [-4,-1,0,3,10]
    print("Input:", input)
    result = solution.sortedSquares(input)
    print("Output:", result)