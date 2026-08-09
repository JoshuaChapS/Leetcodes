
"""
217. contains duplicate · https://leetcode.com/problems/contains-duplicate/

Patrón:  hash set para membresía O(1)
Señal:   "¿existe un duplicado / ya vi este valor?"
Tiempo:  O(n)   Espacio: O(n)
Intento: resuelto solo
Repaso:  no urgente
"""
from typing import List
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        r = set()
        for x in nums:
            if x in r:
                return True
            r.add(x)
        return False

if __name__ == "__main__":
    s = Solution()
    print(s.containsDuplicate([1, 2, 3, 1]))   
    print(s.containsDuplicate([1, 2, 3, 4]))   
    print(s.containsDuplicate([]))             
