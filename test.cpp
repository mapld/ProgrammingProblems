#include <stdio.h>
#include <iostream>
#include <queue>


int find(int* uf, int child){
  if(uf[child] == child){
    return child;
  }
  return find(uf, uf[child]);
}

void createUnion(int* uf, int c1, int c2){
  uf[find(uf, c1)] = find(uf, c2);
}

int main(){
  using namespace std;
  priority_queue<int> q;
  q.push(1);
  q.push(22);
  q.push(3);
  while(q.size() > 0){
    //cout << q.top() << "\n";
    q.pop();
  }

  int uf[5000];
  uf[5] = 5;
  uf[50] = 5;
  uf[22] = 50;
  uf[33] = 50;
  uf[70] = 70;
  uf[88] = 70;

  cout << find(uf, 33) << "\n";
  createUnion(uf, 33, 88);
  cout << find(uf, 33) << "\n";

  return 0;
}
