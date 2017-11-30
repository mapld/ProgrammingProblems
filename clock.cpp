/*Searches for the string w in the string s (of length k). Returns the 0-based index of the first match (k if no match is found). Algorithm runs in O(k) time. */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
void buildTable(VI& w, VI& t) {
  t = VI(w.size());
  int i = 2, j = 0; t[0] = -1;
  t[1] = 0;
  while(i < w.size()) {
    if(w[i-1] == w[j]) {
      t[i] = j+1;
      i++;
      j++;
    }
    else if(j > 0) j = t[j];
    else {
      t[i] = 0; i++;
    }
  }
}

int KMP(VI& s, VI& w) {
  int m = 0, i = 0;
  VI t;
  buildTable(w, t);
  while(m+i < s.size()) {
    if(w[i] == s[m+i]) {
      i++;
      if(i == w.size())
        return m;
    }
    else
    {
      m += i-t[i]; if(i > 0) i = t[i];
    }
  }
  return s.size();
}

// int getDiff(int big, inint diff = big - small;
//   if(diff > 180000){
//     diff = diff - 180000
//   }
// }

int main(){
  int hands;
  cin >> hands;
  VI clock1(hands);
  VI clock2(hands);
  for(int i = 0; i < hands; i++){
    int num;
    cin >> num;
    clock1[i] = num;
  }
  for(int i = 0; i < hands; i++){
    int num;
    cin >> num;
    clock2[i] = num;
  }


  sort(clock1.begin(), clock1.end());
  sort(clock2.begin(), clock2.end());
  // cout << clock1[0] << " " << clock1[2] << "\n";

  VI diff1(hands);
  VI diff2(hands);
  for(int i = 1; i < hands; i++){
    diff1[i] = clock1[i] - clock1[i-1];
    diff2[i] = clock2[i] - clock2[i-1];
  }
  diff1[0] = 360000 - clock1[hands-1] + clock1[0];
  diff2[0] = 360000 - clock2[hands-1] + clock2[0];

  // double diff2
  VI dc2 = diff2;
  diff2.insert(diff2.end(), dc2.begin(), dc2.end());

  // cout << diff1[0] << " " << diff1[1] << "\n";
  // cout << diff2[0] << " " << diff2[1] << diff2[2] << diff2[3] << "\n";
  // cout << diff2.size();

  //  cout << KMP(diff2, diff1) << "\n";
  int result = KMP(diff2, diff1);
  if(result < hands*2){
    cout << "possible\n";
  }
  else{
    cout << "impossible\n";
  }
}
