#include <iostream>
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
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *holder = new ListNode();
        ListNode *past = NULL;
        while (head->next != NULL){
            holder = head->next;
            head->next = past;
            past = head;
            head = holder;
        }
        head->next = past;
        return head;
    }
};
void printNodes(ListNode *n){
    while(n != NULL){
        cout<<n->val<<" ";
        n = n->next;
    }
}

int main(){
    ListNode *list1h = new ListNode(102);
    ListNode *list1g = new ListNode(42, list1h);
    ListNode *list1f = new ListNode(22, list1g);
    ListNode *list1e = new ListNode(12, list1f);
    ListNode *list1d = new ListNode(10, list1e);
    ListNode *list1c = new ListNode(4, list1d);
    ListNode *list1b = new ListNode(2, list1c);
    ListNode *list1a = new ListNode(1, list1b);
    
    ListNode *list2c = new ListNode(4);
    ListNode *list2b = new ListNode(3, list2c);
    ListNode *list2a = new ListNode(1, list2b);
    
    
    Solution sol;
    ListNode *finalHead = sol.reverseList(list1a);

    printNodes(finalHead);    
    
    return 0;
}