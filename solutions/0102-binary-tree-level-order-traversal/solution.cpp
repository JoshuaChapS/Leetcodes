#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> levels;
        levels.push(root);
        size_t n = levels.size();
        size_t i;
        vector<vector<int>> answer = {};
        vector<int> temp = {};
        TreeNode* current;
        while (n > 0){
            for(i = 0; i < n; i++){
                current = levels.front();
                temp.push_back(current->val);
                if (current->left!=nullptr) levels.push(current->left);
                if (current->right!=nullptr) levels.push(current->right);
                levels.pop();
            }
            n = levels.size();
            answer.push_back(temp);
            temp = {};
        }
        return answer;


    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
