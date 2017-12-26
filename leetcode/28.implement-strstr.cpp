#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
      // build longest prefix w/ is also suffix array
      vector<int> lps = vector<int>(haystack.size(), 0);
      int i = 1;
      int len = 0;
      while(i < needle.size()){
        if(needle[i] == needle[len]){
          len++;
          lps[i] = len;
          // cout << " lps: " << lps[i];
          i++;
        }
        else{
          if(len > 0){
            len = lps[len-1];
          }
          else{
            lps[i] = 0;
            // cout << " lps: " << lps[i];
            i++;
          }
        }
      }

      // kmp
      int hS = 0;
      int nP = 0;
      int hP = hS;
      while(hS+needle.size() <= haystack.size()){
        // cout << " hS: " << hS << " hP: " << hP << " nP: " << nP << "   ";
        while(nP < needle.size() && needle[nP] == haystack[hP]){
          nP++;
          hP++;
        }
        if(nP >= needle.size()){
          return hS;
        }
        // aaaaabb
        // aab
        // 010
        // nP = 2, hS=1, hP=3
        // aaab
        // 0120
        // nP = 3, hS=1, hP=4
        // asdf
        // 0000
        // nP = 0, hS=1, hP=1
        // abaccaba
        hS++;
        nP = lps[nP-1];
        hP = hS + nP;
      }
      return -1;
    }
};
