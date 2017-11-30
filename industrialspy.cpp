#include <bitset>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef long long ll ;
typedef vector<int> vi ;
#define pb push_back
#define sz(x) (int)((x).size())

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; i++) {
           if (bs[i]) {
                   for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
                   primes.pb(i);
           }
    }
}

bool isPrime(ll N) {
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < sz(primes); i++)
           if (N % primes[i] == 0)
                   return false;
    return true;
}

string s;
string deleted;
set<string> deletedSet;
set<int> primeSet;

void search(){
  // cout << "s: " << s << "\n";
  if(s == ""){
    return;
  }

  sort(s.begin(), s.end());
  do{
    string::size_type size_t;
    long long num = stoll(s,&size_t);
    if(isPrime(num)){
      //cout << num << "\n";
      primeSet.insert(num);
    }
  } while(next_permutation(s.begin(), s.end()));

  int n = s.size();
  string sCopy = s;
  for(int sIndex=0; sIndex<n; sIndex++){
    deleted = deleted + s[sIndex];
    string dCopy = deleted;
    sort(dCopy.begin(), dCopy.end());
    if(deletedSet.find(dCopy) != deletedSet.end()){
      // backtrack
      deleted.pop_back();
      continue;
    }
    // cout << "d:" << deleted << "\n";
    deletedSet.insert(dCopy);
    s.erase(sIndex,1);

    search();
    //s = deleted.back() + s;
    s = sCopy;
    deleted.pop_back();
  }
}

int main() {
    sieve(10000000); // Load sieve...
    int n;
    //scanf_s("%d", &n);
    //printf("%d is %sprime.", n, (isPrime(n)) ? "" : "not ");

    cin >> n;
    for(int i = 0;i < n; i++){
      cin >> s;

      sort(s.begin(), s.end());
      deletedSet.clear();
      primeSet.clear();
      deleted = "";

      search();
      cout << primeSet.size() << "\n";
    }

}
