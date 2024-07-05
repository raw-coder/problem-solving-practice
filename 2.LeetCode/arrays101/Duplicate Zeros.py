from typing import List


class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        n = len(arr) - 1
        while i < n:
            if arr[i] == 0:
                for j in range(n, i + 1, -1):
                    arr[j] = arr[j - 1]
                arr[i + 1] = 0
                i += 1
            i += 1
                
if __name__ == "__main__":
    solution = Solution()
    input = [1,0,2,3,0,4,5,0]
    print("Input:", input)
    solution.duplicateZeros(input)
    print("Output:", input)        