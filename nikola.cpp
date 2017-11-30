#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<int> entryCosts;
vector<vector<int> > minCosts;
int stoneCount;
int minTotalCost = 1000000000;
deque<int> q;

void dfs(int spos, int sstep){
  q.push_back(spos);
  q.push_back(sstep);

  while(q.size() > 0){
    int pos = q.front();
    q.pop_front();
    int step = q.front();
    q.pop_front();

    int forward = pos + step + 1;
    int backward = pos - step;
    // cout << "test1\n";

    if(forward == stoneCount - 1){
      // cout << "test2\n";
      int cost = minCosts[pos][step] + entryCosts[forward];
      if(cost < minTotalCost){
        minTotalCost = cost;
      }
    }
    if(forward < stoneCount - 1){
      // cout << "test3\n";
      int cost = minCosts[pos][step] + entryCosts[forward];
      if(cost < minTotalCost && cost < minCosts[forward][step+1]){
        minCosts[forward][step+1] = cost;
        q.push_back(forward);
        q.push_back(step + 1);
      }
    }
    if(backward >= 0){
      // cout << "size of vecs = " << minCosts.size() << " , " << entryCosts.size() << "\n";
      // cout << "test4 pos=" << pos << " step=" << step << "\n";
      int cost = minCosts[pos][step] + entryCosts[backward];
      // cout << "test5\n";
      if(cost < minTotalCost && cost < minCosts[backward][step]){
        minCosts[backward][step] = cost;
        q.push_back(backward);
        q.push_back(step);
      }
    }
  }
}

int main(){
  cin >> stoneCount;

  for(int i = 0; i < stoneCount; i++){
    int eCost;
    cin >> eCost;
    entryCosts.push_back(eCost);
  }
  int mCost = 1000;
  minCosts = vector<vector<int> >(stoneCount, vector<int>(1005, 1000000000));

  int curStep = 1;
  int curPos = 1;
  minCosts[1][1] = entryCosts[1];

  dfs(curPos, curStep);
  cout << minTotalCost << "\n";
}
