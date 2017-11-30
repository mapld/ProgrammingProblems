#include <iostream>
#include <map>
#include <set>


int main(){
  using namespace std;

  map<string,int> messageMap;
  set<string> messages;

  for(int i = 0; i < 5;i++){
    string line;
    getline(cin,line);

    messages.insert(line);
    if(messageMap.find(line) == messageMap.end()){
      messageMap[line] = 1;
    }
    else{
      messageMap[line] = messageMap[line] + 1;
    }
  }

  int maxNum = 0;
  string maxMes = "";
  for (std::set<string>::iterator it=messages.begin(); it!=messages.end(); ++it){
    string curMes = *it;
    int curNum = messageMap[curMes];
    if(curNum > maxNum){
      maxNum = curNum;
      maxMes = curMes;
    }
  }
  cout << maxMes << "\n";
  cout << maxNum << "\n";
}
