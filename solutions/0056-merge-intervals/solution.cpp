#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        int last = -1;
        while (i < (int) intervals.size()){
            if((int)temp.size() == 0){
                temp.push_back(intervals[i][0]);
                last = intervals[i][1];
            }
            else if((int)temp.size() == 1){
                if(last>= intervals[i][0]){
                    last = max(last,intervals[i][1]);
                }
                else{
                    temp.push_back(last);
                    ans.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    last = intervals[i][1];
                    temp.push_back(intervals[i][0]);
                }
            }
            i++;
        }
        if(last >=0){
            temp.push_back(last);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
