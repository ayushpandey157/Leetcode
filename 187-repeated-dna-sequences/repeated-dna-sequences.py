class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        ans = set()
        values = set()
        for i in range(len(s)-9):
            f =s[i:i+10] 
            if f in values:
                ans.add(f)
                continue 
            values.add(f)
        return list(ans)