#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  while(!cin.eof()){
    int numPairs;
    cin >> numPairs;
    vector<string> p1(numPairs);
    vector<string> p2(numPairs);

    for(int i = 0; i < numPairs; i++){
      cin >> p1[i];
      cin >> p2[i];
    }

    char final[10000];

    int cur = 0;
    int curP1 = 0;
    int curP2 = 0;
    int curI1 = 0;
    int curI2 = 0;

  }
}
