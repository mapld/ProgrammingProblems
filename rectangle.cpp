#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;


int main(){
  int nRects;
  cin >> nRects;
  while (nRects != 0)
  {
    vector<vector<bool> > gridPoints = vector<vector<bool> >(500, vector<bool>(500,false));
    for(int i = 0; i < nRects; i++){
      int x1, x2, y1, y2;
      cin >> x1;
      cin >> y1;
      cin >> x2;
      cin >> y2;

      for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++){
          gridPoints[i][j] = true;
        }
      }
    }
    int count = 0;
    for(int i = 0; i < 500; i++){
      for(int j = 0; j < 500; j++){
        if(gridPoints[i][j]){
          count++;
        }
      }
    }
    cout << count << "\n";
    cin >> nRects;
  }
}
