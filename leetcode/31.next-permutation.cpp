#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  void swp(vector<int>& nums, int x, int y){
    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
  }

  void nextPermutation(vector<int>& nums) {
    int i = nums.size()-1;

    // loop backwards and find place to make bigger by swapping
    while(i >= 1 && nums[i] <= nums[i-1]){
      i--;
    }

    if(i >= 1){
      // go forward, get smallest digit bigger than (i-1)
      int smallestI = i;
      int smallest = nums[i];
      for(int j = i; j < nums.size(); j++){
        if(nums[j] < smallest && nums[j] > nums[i-1]){
          smallest = nums[j];
          smallestI = j;
        }
      }

      swp(nums,i-1,smallestI);

      // go forward, get smallest number after
      if(i < nums.size()-1){
        sort(nums.begin()+i,nums.end());
      }
    }
    else{
      sort(nums.begin(), nums.end());
    }
  }
};
