#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int ans = 0;

        unordered_map<string, unordered_set<string>> dir;

        for (string& mail: emails){
            size_t pos = mail.find('@');
            if(pos == string::npos) throw invalid_argument("No @");
            int n = (int)mail.length();
            string domain = mail.substr(pos+1, n-pos-1);
            string local  = mail.substr(0, pos);
            size_t posPlus = local.find('+');
            if(posPlus != string::npos){
                local.erase(posPlus);
            }
            local.erase(remove_if(local.begin(), local.end(), [](const unsigned char c){
                return c == '.';
            }), local.end());
            
            dir[domain].insert(local);
            
        }
        for(const auto& [dom, loc]: dir){
            ans += (int)loc.size();
        }


        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
