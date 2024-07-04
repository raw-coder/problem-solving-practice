class Solution:
    def numberOfSteps(self, num: int) -> int:
        steps = 0
        while num > 0:
            steps += 1
            if (num % 2 == 0):
                num /= 2
            else:
                num -= 1
        return steps
        
        
if __name__ == "__main__":
    solution = Solution()
    test_input = 123
    print("Input:", test_input)
    result = solution.numberOfSteps(test_input)
    print("Output:", result)  