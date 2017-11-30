#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int num1;
  int num2;
  int num3;
  string order;
  cin >> num1;
  cin >> num2;
  cin >> num3;
  cin >> order;

  vector<int> nums;
  nums.push_back(num1);
  nums.push_back(num2);
  nums.push_back(num3);

  std::sort(nums.begin(), nums.end());

  for(int i = 0; i < 3; i++){
    if(order[i] == 'A'){
      cout << nums[0];
    }
    if(order[i] == 'B'){
      cout << nums[1];
    }
    if(order[i] == 'C'){
      cout << nums[2];
    }
    if(i < 2){
      cout << " ";
    }
  }
  cout << "\n";
}
