#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> fleet;
        
        for(int i = 0; i < (int) position.size(); i++){
            fleet.push_back({position[i], speed[i]});
        }
        stable_sort(fleet.begin(), fleet.end());
        int n = (int)fleet.size();
        int ans = n;
        vector<float>etas;
        for(auto& x: fleet){
            etas.push_back(((float)target - (float)x.first)/((float)x.second));
        }

        int i = n-2;
        while(i >= 0){
            int k=0;
            while(i-k>=0 && etas[i-k] <= etas[i+1]){
                ans--;
                k++;
            }

            i-=(k+1);
        }

        
        return ans;
        
        
        
    }
};


int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
