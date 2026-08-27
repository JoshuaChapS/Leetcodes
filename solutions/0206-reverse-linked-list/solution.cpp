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
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
    ListNode* reverse(ListNode* current, ListNode* last){
        if(current == nullptr) return last;
        ListNode* next = current->next;
        current->next = last;
        return reverse(next, current);
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
