#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, pair<int,int>>>pq;
        pair<long long, pair<int, int>> temp;
        vector<vector<int>> ans;
        for(vector<int> point : points){
            if((int)pq.size() < k){
                temp = {point[0]*point[0] + point[1]*point[1], {point[0], point[1]}};
                pq.push(temp);
            }
            else if (point[0]*point[0] + point[1]*point[1] < pq.top().first){
                temp = {point[0]*point[0] + point[1]*point[1], {point[0], point[1]}};
                pq.push(temp);
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;

    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
