#include <iostream>

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(!l1) return l2;
      if(!l2) return l1;

      ListNode* head;
      ListNode* cur;
      ListNode* other;
      if(l1->val > l2->val){
        cur = l2;
        other = l1;
      }
      else{
        cur = l1;
        other = l2;
      }
      head = cur;
      while(cur && other){
        if((cur->next) != NULL && cur->next->val > other->val){
          ListNode* tmp = cur->next;
          cur->next = other;
          cur = other;
          other = tmp;
        }
        else{
          if(!(cur->next)){
            cur->next = other;
            break;
          }
          cur = cur->next;
        }
      }
      return head;
    }
};
