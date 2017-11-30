#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int nNodes;
vector<vector<int> > heights;
vector<vector<int> > edgeList;
deque<int> nodes;
vector<int> vis;
vector<int> top;
vector<bool> ruledOut;
int c = 0;
int totalCount = 0;

void dfs(int cur){
  vis[cur] = c;
  top[cur] = c;
  c++;
  nodes.push_back(cur);
  // cout << "cur: " << cur << "\n";

  vector<int> connections = edgeList[cur];
  for(int i = 0; i < connections.size(); i++){
    int next = connections[i];
    // cout << "next: " << next << "\n";
    // cout << "vis[next]" << vis[next] << "\n";
    // cout << "top[next]" << top[next] << "\n";
    if(vis[next] == -1){
      dfs(next);
      top[cur] = min(top[cur], top[next]);
    }
    else if(vis[next] >= 0){
      top[cur] = min(top[cur], top[next]);
    }
    // cout << "vis[cur]" << vis[cur] << "\n";
    // cout << "top[cur]" << top[cur] << "\n";
  }

  if(vis[cur] == top[cur]){
    // head of scc
    // cout << "scc with head " << cur << "\n";
    int count = 0;
    bool ruleOut = false;
    int bl;
    do{
      bl = nodes.back();
      nodes.pop_back();
      if(ruledOut[bl]){
        ruleOut = true;
      }
      vis[bl] = -2;
      top[bl] = top[cur];
      count++;
      // cout << "contains " << bl << "\n";
    } while (bl != cur);
    if(!ruleOut){
      totalCount+= count;
    }
  }
}

int main(){
  int x;
  int y;

  cin >> x;
  cin >> y;

  x += 2;
  y += 2;

  nNodes = x * y;
  edgeList = vector<vector<int> >(nNodes);
  ruledOut = vector<bool>(nNodes, true);
  heights = vector<vector<int> >(x, vector<int>(y, 10000));
  vis = vector<int>(nNodes, -1);
  top = vector<int>(nNodes, -1);

  for(int i = 1; i < y-1; i++){
    for(int j = 1; j < x-1; j++){
      cin >> heights[j][i];
    }
  }
  for(int i = 1; i < x-1; i++){
    for(int j = 1; j < y-1; j++){
      // cout << "test\n";
      int ni = i-1;
      int nj = j;
      ruledOut[j*x+i] = false;
      if(heights[i][j] > heights[ni][nj]){
        // cout << "1ruling out x: " << i << "y: " << j << "\n";
        ruledOut[j*x+i] = true;
      }
      if(heights[i][j] >= heights[ni][nj]){
        edgeList[j*x+i].push_back(nj*x+ni);
      }
      ni = i + 1;
      nj = j;
      if(heights[i][j] > heights[ni][nj]){
        // cout << "2ruling out x: " << i << "y: " << j << "\n";
        ruledOut[j*x+i] = true;
      }
      if(heights[i][j] >= heights[ni][nj]){
        edgeList[j*x+i].push_back(nj*x+ni);
      }
      ni = i;
      nj = j+1;
      if(heights[i][j] > heights[ni][nj]){
        // cout << "3ruling out x: " << i << "y: " << j << "\n";
        ruledOut[j*x+i] = true;
      }
      if(heights[i][j] >= heights[ni][nj]){
        edgeList[j*x+i].push_back(nj*x+ni);
      }
      ni = i;
      nj = j-1;
      if(heights[i][j] > heights[ni][nj]){
        // cout << "4ruling out i: " << i << "j: " << j << "\n";
        // cout << "height compare f: " << heights[i][j] << "\n";
        // cout << "height compare s: " << heights[ni][nj] << "\n";
        ruledOut[j*x+i] = true;
      }
      if(heights[i][j] >= heights[ni][nj]){
        edgeList[j*x+i].push_back(nj*x+ni);
      }
    }

  }

  int nextNum = 0;
  while(nextNum >= 0){
    dfs(nextNum);
    nextNum = -1;
    for(int i = 0; i < nNodes; i++){
      if(vis[i] == -1){
        nextNum = i;
        break;
      }
    }
  }

  cout << totalCount << "\n";

}
