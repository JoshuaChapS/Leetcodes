from typing import List
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        nonVisited = set([x for x in range(len(isConnected))])
        provinces = 0

        while nonVisited:
            provinces+=1
            self.visit(isConnected, nonVisited.pop(), nonVisited)
        return provinces
    def visit(self, connections: List[List[int]], city: int, nonVisited: set[int]):
        if city in nonVisited:
            nonVisited.remove(city)
        for i in range(len(connections)):
            if i != city and i in nonVisited and connections[city][i] == 1:
                self.visit(connections, i, nonVisited)


        return

if __name__=="__main__":
    s = Solution()
    print(s.findCircleNum([[1,1,0],[1,1,0],[0,0,1]]))