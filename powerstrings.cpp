#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
void buildTable(string& w, VI& t) {
  t = VI(w.length());
  int i = 2, j = 0; t[0] = -1;
  t[1] = 0;
  while(i < w.length()) {
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

/*Searches for the string w in the string s (of length k). Returns the 0-based index of the first match (k if no match is found). Algorithm runs in O(k) time. */
int KMP(string& s, string& w) {
  int m = 1, i = 0;
  VI t;
  buildTable(w, t);
  while(m+i < s.length()) {
    if(w[i] == s[m+i]) {
      i++;
      if(i == w.length())
        return m;
    }
    else
      {
        m += i-t[i]; if(i > 0) i = t[i];
      }
  }
  return s.length();
}

int main(){
  string in;
  cin >> in;
  while(in != "."){
    string second = in;
    in.insert(in.end(), second.begin(), second.end());

    cout << second.length() / KMP(in, second) << "\n";

    cin >> in;
  }
}
