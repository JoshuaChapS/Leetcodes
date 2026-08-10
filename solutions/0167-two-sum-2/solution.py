from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        izq = 0
        n = len(nums)
        der = n-1

        while izq<der and nums[izq] + nums[der] !=  target:
            if(nums[izq] + nums[der] > target):
                der-=1
            elif (nums[izq] + nums[der] < target):
                izq+=1
            else:
                return []

        return [izq+1, der+1]

if __name__=="__main__":
    s = Solution()
    print(s.twoSum([2,7,11,15], 9))