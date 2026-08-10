class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        d = [l for l in s if (ord(l)>=ord('a') and ord(l)<=(ord('z'))) or (ord(l)>=ord('0') and ord(l) <=ord('9'))]
        n = len(d)

        for i in range(n//2):
            if(d[i] != d[n-1-i]):
                return False

        return True
class Solution2:
    def isPalindrome(self, s:str) -> bool:
        i = 0
        j = len(s)-1

        while i<=j:
            while( i<=j and not s[i].isalnum() ):
                i +=1
            while(i<=j and not s[j].isalnum()):
                j-=1
            
            if(i>j):
                return True
            if(s[i].lower() != s[j].lower()):
                return False
            i+=1
            j-=1
        return True
        


if __name__=="__main__":
    s = Solution()
    #print(s.isPalindrome("A man, a plan, a canal: Panama"))
    #print(s.isPalindrome("0P"))

    s = Solution2()
    print(s.isPalindrome("A man, a plan, a canal: Panama"))
    print(s.isPalindrome(" "))
