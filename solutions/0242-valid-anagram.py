"""
242. valid anagram · https://leetcode.com/problems/valid-anagram/

Patrón:  ordenar ambas y comparar
Señal:   "mismos elementos sin importar el orden"
Tiempo:  O(n log n)   Espacio: O(n)  //Para la solucion 1
Intento: resuelto solo (necesité la sintaxis de sorted)
Repaso:   2026-08-10
"""
from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
class Solution2:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        d1 = {}
        d2 = {}
        for i in range(len(s)):
            if s[i] not in d1:
                d1[s[i]]= 1
            else:
                d1[s[i]]+=1
            if t[i] not in d2:
                d2[t[i]]= 1
            else:
                d2[t[i]]+=1
        return d1==d2
class Solution3:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        d1, d2 = {}, {}
        for a, b in zip(s, t):
            d1[a] = d1.get(a, 0) + 1
            d2[b] = d2.get(b, 0) + 1
        return d1 == d2
class Solution4:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)       
            
if __name__ ==  "__main__":
    s = Solution()
    print(s.isAnagram("luis", "suil"))
    print(s.isAnagram("luis", "pedr"))

    s = Solution2()
    print(s.isAnagram("luis", "suil"))
    print(s.isAnagram("luis", "pedr"))