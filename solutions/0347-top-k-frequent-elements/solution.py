from collections import defaultdict
from typing import List
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for n in nums:
            d[n] = d.get(n, 0) + 1
        res = sorted(d, key=lambda x:d[x], reverse=True)
        return res[:k]

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for n in nums:
            d[n] = d.get(n, 0) + 1

        bucket = [[] for _ in range(len(nums) + 1)]
        for num, freq in d.items():
            bucket[freq].append(num)

        sol = []
        for i in range(len(bucket) - 1, 0, -1):
            for num in bucket[i]:
                sol.append(num)
                if len(sol) == k:
                    return sol
        return sol
        
        

if __name__=="__main__":
    s = Solution()

    #print(s.topKFrequent([1,1,1,2,2,3], 2))

    s = Solution2()
    
    print(s.topKFrequent([1,1,1,2,2,3], 2))