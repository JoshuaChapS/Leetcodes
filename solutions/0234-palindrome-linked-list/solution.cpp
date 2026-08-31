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
    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* second = reverseList(middleNode(head));
        while(second!=nullptr){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
        
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
    ListNode* reverse(ListNode* current, ListNode* last){
        if(current == nullptr) return last;
        ListNode* next = current->next;
        current->next = last;
        return reverse(next, current);
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
