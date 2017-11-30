#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int rownum;
  int colnum;
  cin >> rownum;
  cin >> colnum;
  vector<int> rowSums;
  vector<int> colSums;
  for(int i = 0; i < rownum; i++){
    int s;
    cin >> s;
    rowSums.push_back(s);
  }
  for(int i = 0; i < colnum; i++){
    int s;
    cin >> s;
    colSums.push_back(s);
  }

  std::sort(colSums.rbegin(), colSums.rend());
  std::sort(rowSums.rbegin(), rowSums.rend());

  int colTotal = 0;
  int rowTotal = 0;
  for(int i = 0; i < colnum; i++){
    colTotal += colSums[i];
  }
  for(int i = 0; i < rownum; i++){
    rowTotal += rowSums[i];
  }
  if(colTotal != rowTotal){
    cout << "No\n";
    return 0;
  }
  int blah = 0;
  for(int k = 0; k < colnum; k++){
    int colT = 0;
    int rowT = 0;
    for(int i = 0; i < k; i++){
      colT += colSums[i];
    }
    for(int i = 0; i < rownum; i++){
      rowT += min(rowSums[i], k + 1);
    }
    if(colT > rowT){
      blah = 1;
    }
  }
  for(int k = 0; k < rownum; k++){
    int colT = 0;
    int rowT = 0;
    for(int i = 0; i < k; i++){
      colT += rowSums[i];
    }
    for(int i = 0; i < colnum; i++){
      rowT += min(rowSums[i], k + 1);
    }
    if(colT > rowT && blah){
      blah = 1;
    }
  }


  if(blah){

  }

  cout << "Yes\n";
}
