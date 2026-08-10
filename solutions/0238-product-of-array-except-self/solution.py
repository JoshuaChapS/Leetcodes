from typing import List
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        izq= [1]*n
        der = [1]*n
        ans = [0]* n
        for i in range(1, n):
            izq[i] = izq[i-1] * nums[i-1]
        for i in range(n-2, -1, -1):
            der[i] = der[i+1] * nums[i+1]
        for i in range(0, n):
            ans[i] = izq[i] * der[i]

        
        return ans
    
class Solution2:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n
        for i in range(1, n):
            ans[i] = ans[i-1] * nums[i-1]
        der = 1
        for i in range(n-1, -1, -1):
            ans[i] *= der
            der *= nums[i]
        return ans

if __name__ == "__main__":
    s = Solution()

    print(s.productExceptSelf([1,2,3,4]))

