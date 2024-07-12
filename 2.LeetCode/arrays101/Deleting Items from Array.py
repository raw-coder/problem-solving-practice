from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        i = 0
        end = len(nums)
        while i < end:
            if nums[i] == val:
                for j in range(i, end - 1):
                    nums[j] = nums[j + 1]
                end -= 1
            else:
                k += 1
                i += 1
        return k

if __name__ == "__main__":
    
    nums = [3,2,3,3]
    val = 3
    solution = Solution()
    print("Input: nums = ", nums, ", val = ", val)
    result = solution.removeElement(nums, val)
    print("Output:", result, "nums = ", nums)        