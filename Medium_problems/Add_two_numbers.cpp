/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#define NULL (void*)0

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
    int carry = 0;
    ListNode resList(0);
    ListNode *currLast = &resList;
      
    while(l1 != NULL || l2 != NULL || carry != 0) {
        int result = 0;
        if (l1) {
            result += l1->val;
            l1 = l1->next;           
        }
        if (l2) {
            result += l2->val;
            l2 = l2->next;
        }
        result += carry;
        carry = result / 10;
        result %= 10;
        currLast->next = new ListNode(result);
        currLast = currLast->next;
      }

      return resList.next;
   }  
};
