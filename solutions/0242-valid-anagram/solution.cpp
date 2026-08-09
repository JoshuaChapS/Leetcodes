#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> count;
        for (size_t i = 0; i < s.size(); i++) {
            count[s[i]]++;
            count[t[i]]--;
        }
        for (auto& p : count)
            if (p.second != 0) return false;
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl;
    cout << sol.isAnagram("rat", "car") << endl;
    cout << sol.isAnagram("aab", "abb") << endl;
}
