/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if(!head || !(head->next)){
        return head;
      }
      ListNode* cur = head;
      head = cur->next;
      ListNode* old = NULL;
      while(cur){
        if(cur->next){
          ListNode* next = cur->next;
          ListNode* nnext = next->next;
          if(old){
            old->next = next;
          }
          next->next = cur;
          cur->next = nnext;
        }
        old = cur;
        cur = cur->next;
      }
      return head;
    }
};
