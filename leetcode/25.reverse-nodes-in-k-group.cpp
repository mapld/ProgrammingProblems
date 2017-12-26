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
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(!head){
        return head;
      }
      ListNode* cur = head;
      ListNode* old = NULL;
      int len = 0;;
      while(cur){
        cur = cur->next;
        len += 1;
      }
      if(len < k){
        return head;
      }

      int count = 0;
      cur = head;

      while(len-count >= k){
        ListNode* localHead = cur;
        ListNode* next = cur->next;
        // cout << "test " << cur->val;
        count += k;
        for(int i = 0; i < k-1; i++){
          ListNode* tmp = next->next;
          next->next = cur;
          cur = next;
          next = tmp;
        }
        localHead->next = next;
        if(old){
          old->next = cur;
        }
        else{
          head = cur;
        }
        old = localHead;
        cur = old->next;
      }
      // cout << "blah";
      return head;
    }
};
