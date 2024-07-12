from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        size = len(nums)
        while i < size - 1:
            if nums[i] == nums[i + 1]:
                nums.pop(i)
                size -= 1
            else:
                i += 1
        return size
        
if __name__ == "__main__":
    solution = Solution()
    nums = [0,0,1,1,1,2,2,3,3,4]
    # nums = [1,1,2]
    # Input: nums = [0,0,1,1,1,2,2,3,3,4]
    print("Input: nums = ", nums)
    result = solution.removeDuplicates(nums)
    # Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    print("Output: ", result, "nums = ", nums)