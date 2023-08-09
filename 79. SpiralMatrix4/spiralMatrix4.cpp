#include<iostream>
#include <vector>
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0, right = n;
        int top = 0, bottom = m;
        vector<vector<int>> res(m, vector<int>(n));
        while(top < bottom && left < right){
            for(int i = left; i < right; i++){
                if(head != NULL){
                    res[top][i] = head->val;
                    head = head->next;
                }else res[top][i] = -1;
            }
            top++;

            for(int i = top; i < bottom; i++){
                if(head != NULL){
                    res[i][right-1] = head->val;
                    head = head->next;
                }else res[i][right-1] = -1;
            }
            right--;

            if(!(top < bottom && left < right)) break;

            for(int i = right-1; i >= left; i--){
                if(head != NULL){
                    res[bottom-1][i] = head->val;
                    head = head->next;
                }else res[bottom-1][i] = -1;
            }
            bottom--;

            for(int i = bottom-1; i>=top; i--){
                if(head != NULL){
                    res[i][left] = head->val;
                    head = head->next;
                }else res[i][left] = -1;
            }
            left++;
        }
        return res;
    }
};

int main(){
    ListNode *list1m = new ListNode(0);
    ListNode *list1l = new ListNode(5, list1m);
    ListNode *list1k = new ListNode(5, list1l);
    ListNode *list1j = new ListNode(2, list1k);
    ListNode *list1i = new ListNode(4, list1j);
    ListNode *list1h = new ListNode(9, list1i);
    ListNode *list1g = new ListNode(7, list1h);
    ListNode *list1f = new ListNode(1, list1g);
    ListNode *list1e = new ListNode(8, list1f);
    ListNode *list1d = new ListNode(6, list1e);
    ListNode *list1c = new ListNode(2, list1d);
    ListNode *list1b = new ListNode(0, list1c);
    ListNode *list1a = new ListNode(3, list1b);
    

    vector<vector<int>> matrix;
    Solution sol;
    matrix = sol.spiralMatrix(3,5, list1a);

    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
/*
  2326. Spiral Matrix IV
Medium

You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented
in spiral order (clockwise), starting from the top-left of the matrix. If there are
remaining empty spaces, fill them with -1.

Return the generated matrix.

Example 1:

Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000
*/