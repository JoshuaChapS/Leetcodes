#include <bits/stdc++.h>
using namespace std;


struct Cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if(a.first>b.first) return true;
        if(a.first<b.first) return false;
        if(a.second<b.second) return true;
        return false;
    }
};
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        

        priority_queue<pair<int, string>, vector<pair<int,string>>, Cmp> pq;
        unordered_map<string, int> dic;

        for(auto& word: words){
            dic[word]++;
        }

        for(auto& [word, freq]: dic){
            pq.push({freq, word});
            if(pq.size()>k) pq.pop();

        }

        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
