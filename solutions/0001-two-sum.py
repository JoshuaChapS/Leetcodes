"""
1. two sum · https://leetcode.com/problems/two-sum/

Patrón:  dict de complementos (valor → índice), una pasada
Señal:   "dos elementos que sumen X" + piden índices, no valores
Tiempo:  O(n)   Espacio: O(n)
Intento: ayuda con diccionarios
Repaso:   2026-08-10
"""
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i, n in enumerate(nums):
            
            if target-n in dic:
                return[dic[target-n], i]
            else:
                dic[n] = i
        return []

if __name__ == "__main__":
    s = Solution()
    print(s.twoSum([1, 2, 3, 4], 6))
    print(s.twoSum([7, 8, 10], 17))