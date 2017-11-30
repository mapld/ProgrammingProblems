#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;

map<string,set<string> > adjMap;
map<string,bool> visited;

string start;
string last;

string dfs(string cur){
  if(visited.find(cur) != visited.end()){
    return "";
  }
  visited[cur] = true;

  if(cur == last){
    return cur;
  }

  set<string> adjSet = adjMap[cur];
  for (set<string>::iterator it=adjSet.begin(); it != adjSet.end(); ++it){
    string res = dfs(*it);
    if(res != ""){
      return cur + " " + res;
    }
  }

  return "";
}

int main(){
  int numEntries;
  cin >> numEntries;

  string line;
  getline(cin,line);
  for(int i =0;i < numEntries; i++){
    // cout << "i: " << i << "\n";
    getline(cin,line);
    // cout << "line: " << line << "\n";
    istringstream iss(line);

    string stat;
    iss >> stat;
    if(adjMap.find(stat) == adjMap.end()){
      adjMap[stat] = set<string>();
    }
    string adj;
    while(iss >> adj){
      adjMap[stat].insert(adj);
      if(adjMap.find(adj) == adjMap.end()){
        adjMap[adj] = set<string>();
      }
      adjMap[adj].insert(stat);
    }
  }

  getline(cin,line);
  istringstream iss(line);

  iss >> start;
  iss >> last;

  // cout << "start: " << start << "\n";
  // cout << "end: " << last << "\n";

  string result = dfs(start);
  if(result == ""){
    result = "no route found";
  }
  cout << result << "\n";

}

