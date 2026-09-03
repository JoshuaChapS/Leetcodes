#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size(); 
        if (m == 0) return false;

        int up = 0;
        int down = n-1;
        int row;
        while (up<=down){
            row = up +(down-up)/2;
            if(matrix[row][0] == target) return true;
            if(matrix[row][0] > target) down = row - 1;
            else up = row + 1;
        }
        
        if (matrix[row][0]>target) row--;
        if(row == -1) return false;
        int mid;
        int left  = 0;
        int right = m-1;
        
        while(left<=right){
            mid = left + (right - left)/2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] > target) right = mid - 1;
            else left = mid+1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
