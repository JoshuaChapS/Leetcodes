from typing import List

from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dics = []
        res = []
        temp2 = []
        for i, s in enumerate(strs):
            dics.append({})
            for l in s:
                dics[i][l] = dics[i].get(l, 0) + 1

        for i in range(len(dics)):
            if dics[i] not in temp2:
                temp2.append(dics[i])
                temp = [strs[i]]
                for j in range(i+1, len(dics)):
                    if dics[i] == dics[j]:
                        temp2.append(dics[j])
                        temp.append(strs[j])
                res.append(temp)
        return res

class Solution2:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for x in strs:
            d["".join(sorted(x))].append(x)
            
        return list(d.values())
        


if __name__ == "__main__":
    #s = Solution()
    #print(s.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))

    s = Solution2()
    print(s.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))

            


