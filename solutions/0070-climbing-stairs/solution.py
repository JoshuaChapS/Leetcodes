class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1:
            return 1
        elif n==2:
            return 2
        elif n<=0:
            return 0
        else:
            return self.climbStairs(n-1)+self.climbStairs(n-2)

class Solution2:
    def climbStairs(self, n: int) -> int:
        steps = 0
        if n == 1:
            return 1
        if n == 2:
            return 2
        data = [1, 2]
        for _ in range(2,n):
            steps = sum(data)
            data[0] =  data[1]
            data[1] = steps
        return steps

if __name__ == "__main__":
    s = Solution2()
    print(s.climbStairs(3))