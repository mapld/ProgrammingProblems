#include <vector>
#include <iostream>
#include <climits>

using namespace std;


 // struct ListNode {
 //     int val;
 //     ListNode *next;
 //     ListNode(int x) : val(x), next(NULL) {}
 // };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      vector<ListNode*> others;
      int smallest = INT_MAX;
      int smallestI = 0;
      for(int i = 0; i < lists.size(); i++){
        ListNode* ln = lists[i];
        if(ln){
          others.push_back(ln);
          if(ln->val < smallest){
            smallest = ln->val;
            smallestI = others.size()-1;
          }
        }
      }
      if(others.size() == 0){
        return NULL;
      }
      if(others.size() == 1){
        return others[0];
      }
      ListNode* cur = others[smallestI];
      others.erase(others.begin()+smallestI);
      ListNode* head = cur;
      while(others.size() > 0){
        int smallest = INT_MAX;
        int smallestI = -1;
        for(int i = 0; i < others.size(); i++){
          ListNode* ln = others[i];
          if(ln->val < smallest){
            smallest = ln->val;
            smallestI = i;
          }
        }
        if(!(cur->next)){
          cur->next = others[smallestI];
          others.erase(others.begin()+smallestI);
          cur = cur->next;
        }
        else if(smallest < cur->next->val){
          ListNode* tmp = cur->next;
          cur->next = others[smallestI];
          others.erase(others.begin()+smallestI);
          cur = cur->next;
          if(tmp){
            others.push_back(tmp);
          }
        }
        else{
          cur = cur->next;
        }
      }
      return head;
    }
};
