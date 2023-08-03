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
        string num1 ="", num2 ="";
        while(l1 != NULL){
            num1 += to_string(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            num2 += to_string(l2->val);
            l2 = l2->next;
        }
        int num1Len = num1.size()-1, num2Len = num2.size()-1, carry = 0, sum;
        string result = "";
        while(num1Len > -1 || num2Len > -1 || carry > 0){
            sum = carry;
            if(num1Len>-1){
                sum += num1[num1Len] - '0';
                num1Len--;
            } 
            if(num2Len>-1){
                sum += num2[num2Len] - '0';
                num2Len--;
            }
            carry = sum/10;
            result = to_string(sum%10) + result;
        }
        ListNode *head = new ListNode();
        ListNode *holder = head;
        int resLen = result.size();
        for(int i = 0; i < resLen; i++){
            ListNode *justBorn = new ListNode(result[i]-'0');
            holder->next = justBorn;
            holder = holder->next;
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
    // ListNode *list1g = new ListNode(9);
    // ListNode *list1f = new ListNode(9, list1g);
    // ListNode *list1e = new ListNode(9, list1f);
    ListNode *list1d = new ListNode(3);
    ListNode *list1c = new ListNode(4, list1d);
    ListNode *list1b = new ListNode(2, list1c);
    ListNode *list1a = new ListNode(7, list1b);
    
    // ListNode *list2d = new ListNode(9);
    ListNode *list2c = new ListNode(4);
    ListNode *list2b = new ListNode(6, list2c);
    ListNode *list2a = new ListNode(5, list2b);
    
    Solution sol;
    ListNode *finalHead = sol.addTwoNumbers(list1a, list2a);
    printNodes(finalHead); 
    
    return 0;
}
/*
  445. Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number
0 itself.

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
*/