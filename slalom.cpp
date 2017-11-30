#include <iostream>
#include <map>
#include <vector>


int main(){
  using namespace std;

  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++){
    int gates;
    int startY;
    cin >> gates;
    cin >> startY;

    vector<int> gateBot;
    vector<int> gateTop;

    for(int j=0; j< gates; j++){
      int bot;
      int top;
      cin >> bot;
      cin >> top;
      gateBot.push_back(bot);
      gateTop.push_back(top);
    }

  map<int, int> mustGo;
  while(true){
    int curY = startY;
    int timesChange = 0;
    int changePos = 0;
    for(int j=0; j< gates;j++){
      int bot = gateBot[j];
      int top = gateTop[j];
      if(curY < bot){
        mustGo[j] = bot;
        curY = bot;
        timesChange++;
        changePos = j;
      }
      if(curY > top){
        mustGo[j] = top;
        curY = top;
        timesChange++;
        changePos = j;
      }
    }
    if(timesChange == 0){
      break;
    }
    timesChange = 0;
    for(int j=changePos;j >=0 ;j--){
      int bot = gateBot[j];
      int top = gateTop[j];
      if(curY < bot){
        mustGo[j] = bot;
        curY = bot;
        timesChange++;
      }
      if(curY > top){
        mustGo[j] = top;
        curY = top;
        timesChange++;
      }
    }

    if(timesChange == 0){
      break;
    }
  }

  float dist = 0.0f;
  int curY = startY;
  int curX = 0;
  for(int i = 0; i < gates; i++){
    if(mustGo.find(i) != mustGo.end()){
      int loc = mustGo[i];
      dist += (float)abs(curX-i)*(float)abs(curX-i) + (float)abs(curY-loc) + (float)abs(curY-loc);
    }
  }

  if(dist == 0.0f){
    dist = (float)gates;
  }

  cout << dist;
  }
}
