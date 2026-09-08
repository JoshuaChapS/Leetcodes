#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pair<int, int> temp;
        vector<int> ans;
        for(const int& num: nums){
            freq[num]++;
        }
        for(const auto& val: freq){
            if((int)pq.size()<k){
                temp = {val.second, val.first};
                pq.push(temp);
            }
            else if (val.second > pq.top().first){
                temp = {val.second, val.first};
                pq.push(temp);
                pq.pop();
            }
            
            
            
        }
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    for (int x : sol.topKFrequent(nums, 2)) cout << x << " ";
    cout << endl;
}
