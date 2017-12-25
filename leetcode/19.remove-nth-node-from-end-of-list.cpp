#include <iostream>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    int trimNth(ListNode* head, int n){
      int result;
      if(head->next == NULL){
        result = n;
      }
      else{
        result = trimNth(head->next, n);
      }

      if(result == -1){
        head->next = head->next->next;
      }

      return result - 1;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int result = trimNth(head,n-1);
      if(result == -1){
         return head->next;
      }
      return head;
    }
};
