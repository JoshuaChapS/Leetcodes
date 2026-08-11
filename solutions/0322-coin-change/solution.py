from typing import List
class Solution:
    
    def coinChange(self, coins: List[int], amount: int) -> int:
        datos = [float("inf")] * (amount + 1)
        datos[0] = 0

        for x in range(1, amount+1):
            for m in coins:
                if m<=x:
                    datos[x] = min(datos[x], datos[x-m] + 1)

        if datos[amount] == float("inf"):
            return -1

        return datos[amount]





if __name__=="__main__":
    s = Solution()

    print(s.coinChange([1,2,5], 11))
