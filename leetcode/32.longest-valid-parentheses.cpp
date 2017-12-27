#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
      int start = -1;
      int lastClose = -1;
      int open = 0;
      int longest = 0;
      for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
          if(start < 0){
            start = i;
            lastClose = i;
          }
          open++;
        }
        else{
          if(open < 1){
            int count = lastClose-start;
            longest = max(longest,count);
            // cout << "  longest: " << longest;
            start = -1;
            lastClose = -1;
            continue;
          }
          if(open == 1){
            lastClose = i;
          }
          open--;
        }
      }
      longest = max(longest,lastClose-start);

      open = 0;
      start = -1;
      lastClose = -1;

      for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == ')'){
          if(start < 0){
            start = i;
            lastClose = i;
          }
          open++;
        }
        else{
          if(open < 1){
            int count = start-lastClose;
            longest = max(longest,count);
            start = -1;
            lastClose = -1;
            continue;
          }
          if(open == 1){
            lastClose = i;
          }
          open--;
        }
      }
      longest = max(longest,start-lastClose);
      if(longest > 0){
        longest++;
      }
      return longest;
    }
};
