from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        last = m + n - 1
        i, j = m - 1, n - 1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[last] = nums1[i]
                i -= 1
            else:
                nums1[last] = nums2[j]
                j -= 1
            last -= 1
        while j >= 0:
            nums1[last] = nums2[j]
            j -= 1
            last -= 1

if __name__ == "__main__":
    solution = Solution()
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    print("Input: num1 = ", nums1, ", m = ", m , ", num2 = ", nums2, ", n = ", n)
    solution.merge(nums1, m, nums2, n)
    print("Output:", nums1)