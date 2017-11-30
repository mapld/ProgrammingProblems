#include <stdio.h>
#include <iostream>
#include <queue>
#include <cmath>


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

  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int uf[150];
    int xCoords[150];
    int yCoords[150];

    int numStores;
    cin >> numStores;

    int homeX;
    int homeY;
    cin >> homeX;
    cin >> homeY;

    uf[1] = 1;
    xCoords[1] = homeX;
    yCoords[1] = homeY;

    int counter;
    for(counter = 2; counter < numStores + 3; counter++){
      cin >> xCoords[counter];
      cin >> yCoords[counter];
      uf[counter] = counter;
      for(int j = 1; j < counter; j++){
        if(abs(xCoords[j] - xCoords[counter]) + abs(yCoords[j] - yCoords[counter]) <= 1000){
          createUnion(uf, counter, j);
        }
      }
    }

    int end = counter - 1;

    if(find(uf, 1) == find(uf, end)){
      cout << "happy\n";
    }
    else{
      cout << "sad\n";
    }

  }
  return 0;
}
