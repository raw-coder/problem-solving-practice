class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        s = {}
        for str in magazine:
            if s.get(str) is None:
                s[str] = 1
            else:
                s[str] += 1
        for str in ransomNote:
            if s.get(str) is None or s[str] == 0:
                return False
            else:
                s[str] -= 1
        return True
    

if __name__ == '__main__':
    solution = Solution()
    inp = {"ransomNote":"a", "magazine":"b"}
    print("Input:", inp)
    result = solution.canConstruct(**inp)
    print("Output:", result)