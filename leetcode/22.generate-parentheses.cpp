#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      // i = 0, must be (
      // i = 1, either ( or )
      // (((( _ ))))
      // 4, 4
      // (()( _ ))()
      //      _ )())
      //      _ ()))
      // T[4,4]    = 3
      // T[N-1,_]  = 1
      // T[N-2, 2] = 1
      // T[N-2, 1] = makes no sense
      int N = n*2;

      vector<vector<vector<string > > > T = vector<vector<vector<string> > >(N, vector<vector<string> >(N, vector<string>()));
      T[n*2-1][1].push_back(")");
      for(int i = (N)-2; i >= 0; i--){
        // cout << " i: " << i;
        for(int j = min(N-i,i); j >= 0; j--){
          // cout << " j: " << j;
          if(j == N-i){
            vector<string> cur = T[i+1][j-1];
            T[i][j].push_back(")" + cur[0]);
          }
          else{
            //  T[i][j] = T[i+1][j+1] + T[i+1][j-1];
            if((N-i-j) % 2 != 0){
              continue;
            }
            vector<string> cur = T[i+1][j+1];
            for(int c = 0; c < cur.size(); c++){
              T[i][j].push_back("(" + cur[c]);
            }
            if(j > 0){
              cur = T[i+1][j-1];
              for(int c = 0; c < cur.size(); c++){
                T[i][j].push_back(")" + cur[c]);
              }
            }
          }
        }
      }
      return T[0][0];
    }
};
