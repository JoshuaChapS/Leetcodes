#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        return run(slow, fast);        
    }
    bool run(ListNode* slow, ListNode* fast){
        if (fast == nullptr) return false;
        if (fast->next == nullptr) return false;
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return true;
        return run(slow, fast);
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
