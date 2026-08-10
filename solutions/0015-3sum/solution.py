class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        sol = []
        data = nums.sort()
        n = len(nums)
        i = 0
        while i < n-2:
            izq = i+1
            der = n-1
            
            while izq < der:
                total = nums[i] + nums[izq] + nums[der]
                if total > 0:
                    der-=1
                elif total <0:
                    izq+=1
                else:
                    sol.append([nums[i], nums[izq], nums[der]])
                    
                    while izq < der and nums[izq+1]==nums[izq]:
                        izq+=1
                    izq+=1
                    
                        
                
           
            while i < n-2 and nums[i+1]==nums[i]:
                i+=1
            i+=1

        
        return sol

if __name__ == "__main__":
    s = Solution()
    print(s.threeSum([-1,0,1,2,-1,-4]))

