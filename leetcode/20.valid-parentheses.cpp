#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      deque<char> openStack;

      for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == '}'){
          if(openStack.size() == 0){
            return false;
          }
          char back = openStack.back();
          openStack.pop_back();
          if(back != '{'){
            return false;
          }
        }
        else if(c == ')'){
          if(openStack.size() == 0){
            return false;
          }
          char back = openStack.back();
          openStack.pop_back();
          if(back != '('){
            return false;
          }
        }
        else if(c == ']'){
          if(openStack.size() == 0){
            return false;
          }
          char back = openStack.back();
          openStack.pop_back();
          if(back != '['){
            return false;
          }
        }
        else{
          openStack.push_back(c);
        }
      }
      if(openStack.size() == 0){
        return true;
      }
      return false;
    }
};
