from collections import defaultdict
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        d = i
        l = 0
        dic = set()
        while d <len(s):
            
            if s[d] in dic:
                while s[i] != s[d]:
                    dic.remove(s[i])
                    i+=1
                i+=1
            else:
                dic.add(s[d])
            d+=1
            l =  max(d-i, l)


        return l

if __name__ == "__main__":
    s = Solution()
    print(s.lengthOfLongestSubstring("abcabcbb"))