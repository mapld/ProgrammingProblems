#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  int nClasses;
  cin >> nClasses;
  vector<int> allC;
  int sum = 0;
  for(int i = 0; i<nClasses; i++){
    int c;
    cin >> c;
    allC.push_back(c);
    sum += c;
  }
  sort(allC.rbegin(),allC.rend());
  int curTime = 0;
  int baseTime = 0;
  int baseI = 0;
  int curI = 0; // top
  int searchI = 0;
  map<int,int> used;
  while(curI < nClasses && searchI < nClasses){
    searchI = baseI;
    while(used.find(searchI) != used.end()){
      searchI++;
      if(searchI == baseI){
        baseI++;
      
    }
    if(searchI == curI){
      searchI++;
    }
    while(used.find(searchI) != used.end()){
      searchI++;
    }
    if(searchI == baseI){
      baseI++;
    }
    used[searchI] = 1;
    cout << "baseI: " << baseI << " searchI: " << searchI << "curI: " << curI << "\n";
    cout << "time: " << curTime << "\n";
    curTime += allC[searchI];
    baseTime += allC[searchI];
    if(baseTime >= allC[curI]){
      baseTime -= allC[curI];
      curI++;
    }
  }

  if(curTime < sum){
    curTime = sum;
  }

  cout << curTime << "\n";
}
