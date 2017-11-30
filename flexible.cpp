#include <iostream>
#include <set>


int main(){
  using namespace std;

  int W;
  int numPart;
  cin >> W;
  cin >> numPart;


  int parts[100];

  parts[0] = 0;
  numPart++;

  for(int i = 1; i < numPart; i++){
    int width;
    cin >> width;
    parts[i] = width;
  }

  parts[numPart] = W;
  numPart++;

  set<int> widths;
  for(int i = 0; i < numPart; i++){
    for(int j = i+1; j < numPart; j++){
      widths.insert(parts[j] - parts[i]);
    }
  }

  //  sort(widths.begin(), widths.end());

  for(set<int>::iterator it=widths.begin(); it != widths.end(); ++it){
    int blah = *it;
    cout << blah << " ";
  }
  cout << "\n";

}
