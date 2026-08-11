from typing import List
class Solution:
    DIRS = ((1, 0), (-1, 0), (0, 1), (0, -1))
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        newRottens = []
        oranges= 0
        minutes = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    newRottens.append((i, j))
                elif grid[i][j] ==1:
                    oranges+=1

        while newRottens and oranges>0:
            temp = set()
            for i, j in newRottens:
                for y, x in self.DIRS:
                    if 0<=y+i<n and 0 <= x+j<m and grid[y+i][x+j]==1:
                        oranges-=1
                        temp.add((y+i, x+j))
                        grid[y+i][x+j] = 2
            newRottens = temp
            minutes+=1
        if oranges>0:
            return -1
        return minutes
                        
                        


        
if __name__=="__main__":
    s = Solution()
    print(s.orangesRotting([[2,1,1],[1,1,0],[0,1,1]]))