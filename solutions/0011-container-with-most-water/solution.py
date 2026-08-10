from typing import List
class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)

        mx = [(n-1)* min(height[0], height[n-1]), 0, n-1]
        total = 0
        i = 0
        d = n-1
        while i<d:
            if height[d]> height[i]:
                i+=1
            else:
                d-=1
            total = (d-i)* min(height[i], height[d])
            if total > mx[0]:
                mx = [total, i, d]


        return mx[0]

if __name__=="__main__":
    s = Solution()

    print(s.maxArea([1,8,6,2,5,4,8,3,7]))

