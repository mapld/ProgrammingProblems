#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int adjustIndex(int idx, int size){
    if(idx< 0){
      idx = size+idx;
    }
    if(idx >= size){
      idx -= size;
    }
    return idx;
  }

    int search(vector<int>& nums, int target) {
      int pivot = nums.size()/2;
      int left = -1 * pivot;
      int right = nums.size()-1+pivot;
      while(left <= right){
        int adjustedIndex = adjustIndex(pivot, nums.size());
        int val = nums[adjustedIndex];
        if(target == val){
          return adjustedIndex;
        }
        if(target < val){
          right = pivot-1;
          while(nums[adjustIndex(left, nums.size())] >= val){
            left++;
          }
        }
        else{
          left = pivot+1;
          while(nums[adjustIndex(right, nums.size())] <= val){
            right--;
          }
        }
        pivot = left + ((right-left)/2);
      }
      return -1;
    }
};
