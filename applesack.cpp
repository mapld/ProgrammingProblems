#include <iostream>


int main(){
  using namespace std;

  int N;
  int K;
  cin >> N;
  cin >> K;

  int curi = 0;
  int newi = 0;
  int curAtOld = N;
  int curAtNew = 0;


  while(true){
    // cout << "curi: " << curi << "curAtOld: " << curAtOld << "\n";
    int curk = 0;
    int steps = 0;
    if(curAtOld <= K){
      cout << curi + curAtOld + 1 << "\n";
      return 0;
    }
    while(curAtOld >= K){
      curk = K;
      curAtOld -= curk;

      steps = 1; //curk / 2;
      newi = curi + steps;

      curAtNew += curk - steps;
      // cout << "curAtNew: " << curAtNew << "\n";
    }
    curk = curAtOld;
    // cout << "steps: " << steps << "\n";
    if(steps == 0){
      steps = 1 ;//curk/2;
      newi = curi + steps;
    }
    if(curk - steps > 0){
      curAtNew += curk - steps;
    }

    curi = newi;
    curAtOld = curAtNew;
    curAtNew = 0;
  }


}
