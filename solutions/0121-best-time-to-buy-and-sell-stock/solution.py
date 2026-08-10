from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        d = i+1
        profit = 0
        n = len(prices)

        while i < n and d < n:
            
            profit = max(profit, prices[d] - prices[i])
            if prices[d]<prices[i]:
                i = d
                d = i + 1
            else:
                d += 1
        

        return profit

if __name__=="__main__":
    s = Solution()

    print(s.maxProfit([7,1,5,3,6,4]))