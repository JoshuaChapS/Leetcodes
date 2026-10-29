#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    explicit TreeNode(int v) : val(v) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(root->val > key) root-> left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else{
            if(root->right == nullptr) return root->left;
            if(root->left == nullptr) return root->right;

            TreeNode* temp = root->right;
            while(temp->left != nullptr) temp = temp->left;

            root->val = temp->val;
            temp->val = key;

            root->right = deleteNode(root->right, key);
        }

        return root;
    }

    
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
