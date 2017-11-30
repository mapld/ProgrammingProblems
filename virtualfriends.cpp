#include <stdio.h>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>

int find(int* uf, int child){
  if(uf[child] == child){
    return child;
  }
  return find(uf, uf[child]);
}

void createUnion(int* uf, int* sz, int c1, int c2){
  int p1 = find(uf, c1);
  int p2 = find(uf, c2);
  if(p1 == p2){
    return;
  }
  uf[p1] = p2;

  int size = sz[p1] + sz[p2];
  //  std::cout << "p1: " << p1 << " p2: " << p2 << "\n";
  //std::cout << "size: " << size << " p1sz: " << sz[p1] << " p2sz: " << sz[p2] << "\n";
  sz[p1] = size;
  sz[p2] = size;
  sz[c1] = size;
  sz[c2] = size;
}

int main(){
  using namespace std;

  int numCases;
  cin >> numCases;
  for(int i = 0; i < numCases; i++){
    map<string,int> nameMap;
    int friendCounter = 1;
    int uf[200005];
    int sz[200005];

    int numMatches;
    cin >> numMatches;
    for(int j = 0; j < numMatches; j++){
      string name1;
      string name2;

      cin >> name1;
      cin >> name2;

      if(nameMap.find(name1) == nameMap.end()){
        nameMap[name1] = friendCounter;
        sz[friendCounter] = 1;
        uf[friendCounter] = friendCounter;
        friendCounter++;
      }
      if(nameMap.find(name2) == nameMap.end()){
        nameMap[name2] = friendCounter;
        sz[friendCounter] = 1;
        uf[friendCounter] = friendCounter;
        friendCounter++;
      }

      int n1 = nameMap[name1];
      int n2 = nameMap[name2];
      createUnion(uf, sz, n1, n2);
      //cout << "found: " << find(uf, n1) << "\n";
      cout << sz[find(uf, n1)] << "\n";
    }

  }
  return 0;

}
