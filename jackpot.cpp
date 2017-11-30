#include <iostream>
#include <vector>

// computes gcd(a,b)
long long gcd(long long a, long long b) {
  while (b){
      long long t = a%b; a = b; b = t;
    }
  return a;
}

// computes lcm(a,b)
long long lcm(long long a, long long b){
  return a / gcd(a, b)*b;
}

using namespace std;
int main(){
  long long cases;
  cin >> cases;
  for(long long i= 0; i < cases; i++){
    long long nwheels;
    cin >> nwheels;
    long long curNum;
    cin >> curNum;
    int keepGoing = 1;
    for(long long j=1; j < nwheels; j++){
      long long newNum;
      cin >> newNum;
      if(keepGoing == 0){
        continue;
      }
      curNum = lcm(newNum, curNum);
      if(curNum > 1000000000 || curNum < 0){
        keepGoing = 0;
      }
    }
    if(curNum > 1000000000 || curNum < 0){
      cout << "More than a billion.\n";
    }
    else{
      cout << curNum << "\n";
    }
  }
}
