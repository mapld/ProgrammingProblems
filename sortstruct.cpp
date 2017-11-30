#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct thing{
  int a;
  int b;
};

bool compareThing(thing first, thing second){
  return first.a < second.a;
}

int main(){
  thing t1 = {1,5};
  thing t2 = {4,10};
  thing t3 = {3,50};
  thing t4 = {2,100};
  vector<thing> things;
  things.push_back(t1);
  things.push_back(t2);
  things.push_back(t3);
  things.push_back(t4);

  sort(things.begin(),things.end(), compareThing);
  for(int i = 0; i< things.size(); i++){
    cout << things[i].b << "\n";
  }
}
