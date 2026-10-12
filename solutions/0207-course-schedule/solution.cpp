#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);

        deque<int> toTake;

        for(auto& req: prerequisites){
            adj[req[1]].push_back(req[0]);
            indeg[req[0]] ++;
        }

        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) toTake.push_back(i);
        }
        
        while(!toTake.empty()){
            int now = toTake.front();

            for(int node: adj[now]){
                indeg[node]--;
                if(indeg[node] == 0) toTake.push_back(node);
            }
            indeg[now]=-1;
            toTake.pop_front();

            
            
        }

        for(int deg:indeg) if (deg != -1) return false;
        return true;



        
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
