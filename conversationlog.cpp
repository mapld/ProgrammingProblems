#include <stdio.h>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <queue>

int main(){
  using namespace std;

  int numMessages;
  cin >> numMessages;


  set<string> users;
  map<string, int> counts;
  map<string,bool> used;

 for(int i = 0; i < numMessages; i++){
    string line;
    getline(cin,line);
    istringstream iss(line);

    string name;
    iss >> name;
    users.insert(name);
    string word;
    while(iss >> word){
      if(counts.find(word) == counts.end()){
        counts[word] = 1;
      }
      if(used.find(name+word) == used.end()){
        used[name+word] = true;
      }
    }
  }

 for (set<string>::iterator it=users.begin(); it != users.end(); ++it){
   string user = *it;
   if(user == ""){
     continue;
   }
   for (map<string,int>::iterator itt=counts.begin(); itt!= counts.end(); ++itt){
     string word = itt->first;
     if(used.find(user+word) == used.end()){
       counts.erase(itt);
     }
   }
 }

 std::priority_queue<int> q;
 for (map<string,int>::iterator itt=counts.begin(); itt != counts.end(); ++itt){
   q.push(itt->second);
 }
 while(q.size() > 0){
   int size = q.top();
   q.pop();
   for (map<string,int>::iterator itt=counts.begin(); itt != counts.end(); ++itt){
     if(itt->second == size){
       cout << itt->first << "\n";
       counts.erase(itt);
     }
   }
 }
}
