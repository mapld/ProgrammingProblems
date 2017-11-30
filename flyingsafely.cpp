#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<vector<int> >  adjMap;

int main(){
  int testcases;
  cin >> testcases;
  for(int i = 0; i < testcases; i++){
    int numC;
    int numP;
    cin >> numC;
    cin >> numP;

    //adjMap = vector<vector<int> >(numC);
    int toVisit = numC;

    for(int j=0; j < numP;j++){
      int from;
      int to;
      cin >> from;
      cin >> to;
      //adjMap[from].push_back(to);
      //adjMap[to].push_back(from);
    }

    cout << numC - 1 << "\n";

  }
}
