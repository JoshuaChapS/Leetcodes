from typing import List
class Solution:
    DIRS = ((1,0), (-1,0), (0,1), (0,-1))
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        total=0
        for i in range(n):
            for j in range(m):
                
                if grid[i][j] == "1":
                    
                    total+=1
                    self.busqueda(grid, i, j, n, m)
        

        return total
    def busqueda(self, grid, i, j, n, m):
        grid[i][j] = "0"
        for di, dj in self.DIRS:
            x, y = i + di, j + dj
            if 0 <= x < n and 0 <= y < m and grid[x][y] == "1":
                self.busqueda(grid, x, y, n, m)

if __name__=="__main__":
    s = Solution()
    grid = [ \
  ["1","1","1","1","0"], \
  ["1","1","0","1","0"], \
  ["1","1","0","0","0"], \
  ["0","0","0","0","0"]  \
]
    
    print(s.numIslands(grid))
    