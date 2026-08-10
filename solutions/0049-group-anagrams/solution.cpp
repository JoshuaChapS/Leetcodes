#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& p : groups) res.push_back(p.second);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> in = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (auto& g : sol.groupAnagrams(in)) {
        for (auto& s : g) cout << s << " ";
        cout << endl;
    }
}
