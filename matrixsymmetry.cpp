#include <iostream>
#include <sstream>
#include <string>

void doThing(std::string line){
  using namespace std;

  int matrix[1000][1000];

  istringstream iss(line);
  int num;
  char delim;
  iss >> num;
  matrix[0][0] = num;
  int size = 1;
  int xCount = 0;
  int yCount = 0;
  while(iss >> delim){
    if(delim == ','){
      xCount++;
    }
    if(delim == ';'){
      size = xCount + 1;
      xCount = 0;
      yCount++;
    }
    iss >> num;
    matrix[xCount][yCount] = num;
  }

  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(matrix[i][j] != matrix[j][i]){
        cout << "Not symmetric\n";
        return;
      }
    }
  }
  cout << "Symmetric\n";
  return;
}

int main(){
  using namespace std;

  string line;
  while(getline(cin,line)){
    doThing(line);
  }
}
