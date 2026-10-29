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
    int kthSmallest(TreeNode* root, int k) {
        int now = 1;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(nodes.top()->left != nullptr){
            nodes.push(nodes.top()->left);
        }

        while(!nodes.empty() && now<k){
            TreeNode* node =nodes.top();
            nodes.pop();
            now++;

            if(node->right !=nullptr){
                nodes.push(node->right);
                while(nodes.top()->left != nullptr){
                    nodes.push(nodes.top()->left);
                }
            }   
        }

        return nodes.top()->val;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
