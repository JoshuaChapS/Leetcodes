class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        longest = 0
        used = {}
        moreUsed = 0
        l= 0
        for r in range(len(s)):
            used[s[r]] = used.get(s[r], 0) + 1
            moreUsed = max(moreUsed, used[s[r]])
            win = r-l+1
            usesLeft = win - moreUsed
            if usesLeft > k:
                used[s[l]]-=1
                l+=1
            longest = max(longest, r-l+1)
        
        return longest


if __name__ == "__main__":
    s= Solution()
    print(s.characterReplacement("AB", 0))