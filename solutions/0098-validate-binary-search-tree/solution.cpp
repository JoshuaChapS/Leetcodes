#include <bits/stdc++.h>
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
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
    bool check(TreeNode* node, long min,long max){
        bool ans1 = true;  
        bool ans2 = true; 
        if(node->left!=nullptr){
            if(node->left->val < node->val && min < node->left->val && node->left->val < max){
                ans1 = check(node->left, min, node->val);
            }
            else ans1 = false;
        }
        
        if (node->right!=nullptr){
            if(node->right->val > node->val && min < node->right->val && node->right->val < max){
                ans2 = check(node->right, node->val, max);
            }
            else ans2= false;
        }
        

        return ans1 && ans2;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
