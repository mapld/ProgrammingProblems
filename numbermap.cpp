#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
//#define trv(c, it) \ // all sample codes involving TRvii use this macro
//  for (vector<vector<int> >::iterator it = (c).begin(); it != (c).end(); it++)

vector<vector<int> > numMap;
vector<vector<int> > visited;
deque<int> q;
int xSize;
int ySize;

int bfs(int x, int y){
  int depth = 0;
  q.push_back(x);
  q.push_back(y);
  q.push_back(depth);

  while(q.size() > 0){
      x = q.front();
      q.pop_front();
      y = q.front();
      q.pop_front();
      depth = q.front();
      q.pop_front();

      if(visited[x][y] > 0){
        continue;
      }
      visited[x][y] = 1;

      if(x == xSize-1 && y == ySize-1){
        return depth;
      }

      int curMoveLen = numMap[x][y];
      if(x - curMoveLen >=0 && visited[x - curMoveLen][y] == 0){
        q.push_back(x - curMoveLen);
        q.push_back(y);
        q.push_back(depth+1);
      }
      if(x + curMoveLen < xSize){
        q.push_back(x + curMoveLen);
        q.push_back(y);
        q.push_back(depth+1);
      }
      if(y - curMoveLen >= 0){
        q.push_back(x);
        q.push_back(y - curMoveLen);
        q.push_back(depth+1);
      }
      if(y + curMoveLen < ySize){
        q.push_back(x);
        q.push_back(y + curMoveLen);
        q.push_back(depth+1);
      }
  }
  return -1;
}

int main(){
  cin >> ySize;
  cin >> xSize;

  // cout << "xsize: " << xSize << "\n";
  // cout << "ysize: " << ySize << "\n";
  numMap = vector<vector<int> >(xSize, vector<int>(ySize));
  visited = vector<vector<int> >(xSize, vector<int>(ySize, 0));

  for(int i = 0; i < ySize; i++){
    string s;
    cin >> s;
    for(int j = 0; j < xSize; j++){
      char digit = s[j];
      int num = (int)(digit - '0');
      //      cout << "test i = " << i  << ", j = " << j << "\n";
      numMap[j][i] = num;
    }
  }

  int res = bfs(0,0);
  cout << res << "\n";

}
