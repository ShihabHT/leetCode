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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        ListNode *final = new ListNode();
        if(list1->val > list2->val){
            final = list2;
        }else{
            final = list1;
        }
        ListNode *holder = new ListNode();
        ListNode *previous = new ListNode();
        while (list2 != NULL){
            if(list1->val > list2->val){
                holder = list2->next;
                previous->next = list2;
                list2->next = list1;
                previous = list2;
                list2 = holder;
            } else{
                previous = list1;
                list1 = list1->next;
            }
            if(list1 == NULL){
                previous->next = list2;
                break;
            } 
        }
        return final;
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
    
    
    Solution *sol = new Solution();
    ListNode *finalHead = sol->mergeTwoLists(list1a, list2a);

    printNodes(finalHead);    
    
    return 0;
}