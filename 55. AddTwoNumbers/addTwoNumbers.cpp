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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        int carry=0, l1Val, l2Val;
        ListNode *head = new ListNode();
        ListNode *holder = head;
        while (l1 != NULL || l2 != NULL || carry > 0){
            int sum=0;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode *justBorn = new ListNode(sum%10);
            holder->next = justBorn;
            holder = justBorn; //we could also do holder = holder->next, which is more intuitive
        }

        return head->next;
    }
};
void printNodes(ListNode *n){
    while(n != NULL){
        cout<<n->val<<" ";
        n = n->next;
    }
}

int main(){
    // ListNode *list1h = new ListNode(102);
    ListNode *list1g = new ListNode(9);
    ListNode *list1f = new ListNode(9, list1g);
    ListNode *list1e = new ListNode(9, list1f);
    ListNode *list1d = new ListNode(9, list1e);
    ListNode *list1c = new ListNode(9, list1d);
    ListNode *list1b = new ListNode(9, list1c);
    ListNode *list1a = new ListNode(9, list1b);
    
    ListNode *list2d = new ListNode(9);
    ListNode *list2c = new ListNode(9, list2d);
    ListNode *list2b = new ListNode(9, list2c);
    ListNode *list2a = new ListNode(9, list2b);
    
    Solution sol;
    ListNode *finalHead = sol.addTwoNumbers(list1a, list2a);
    printNodes(finalHead); 
    
    return 0;
}