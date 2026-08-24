#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        else{
            TreeNode* temp = invertTree(root->left);
            root->left =  invertTree(root->right);
            root->right = temp;
            return root;
        }
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
