#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int nNodes;
vector<vector<int> > edgeList;
deque<int> nodes;
vector<int> vis;
vector<int> top;
int c = 0;

void dfs(int cur){
  vis[cur] = c;
  top[cur] = c;
  c++;
  nodes.push_back(cur);
  // cout << "cur: " << cur << "\n";
  // nodes.pop_back();

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
    cout << "scc with head " << cur << "\n";
    int bl;
    do{
      bl = nodes.back();
      nodes.pop_back();
      vis[bl] = -2;
      top[bl] = top[cur];
      cout << "contains " << bl << "\n";
    } while (bl != cur);
  }
}

int main(){
cin >> nNodes;
edgeList = vector<vector<int> >(nNodes);

// cout << "test " << nNodes << "\n";

int nConn;
cin >> nConn;

// cout << "test2 " << nConn << "\n";
  for(int i = 0; i < nConn; i++){
    int from;
    int to;
      cin >> from;
      cin >> to;
      // cout << "from: " << from << "\n";;
      // cout << "to: " << to << "\n";;
      edgeList[from].push_back(to);
  }

  vis = vector<int>(nNodes, -1);
  top = vector<int>(nNodes, -1);

  // while thing
  int nextNum = 0;
  while(nextNum >= 0){
    dfs(nextNum);
    nextNum = -1;
    for(int i = 0; i < nNodes; i++){
      if(vis[i] >= 0){
        vis[i] = -2;
      }
      else if(vis[i] == -1){
        nextNum = i;
      }
    }
  }
  // for(int i = 0; i < nNodes; i++){
  //   cout << top[i] << "\n";
  // }
}
