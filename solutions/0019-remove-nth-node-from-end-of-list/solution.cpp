#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = head;
        for (size_t i = 0; i < n; i++){
            right = right->next;
        }
        
        if(!right) return head->next;
        move(left, right->next);
        return head;
    }
    void move(ListNode* left, ListNode* right){
        if(!right){
            ListNode* trash = left->next;
            left->next=left->next->next;
            trash->next = nullptr;
            delete(trash);
            return;
        }
        
        move(left->next, right->next);
    }
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = head;
        for (int i = 0; i < n; i++){
            right = right->next;
        }
        
        if(!right) return head->next;
        right = right->next;
        while(right){
            left = left->next;
            right = right->next;
        }
        ListNode* trash = left->next;
        left->next = left->next->next;

        delete(trash);
        return head;
    }
    
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
