#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRight(vector<int>& nums, int target, int min){
      int left = min;
      int right = nums.size()-1;
      int mid = left + (right-left)/2;
      while(left < right){
        // cout << " mid: " << mid << " left: " << left << " right: " << right;
        int val = nums[mid];
        if(val > target){
          right = mid-1;
        }
        else{
          left = mid+1;
        }
        mid = left + (right-left)/2;
      }
      if(nums[left] != target){
        left--;
      }
      return left;
    }

    int findLeft(vector<int>& nums, int target, int max){
      int right = max;
      int left = 0;
      int mid = left + (right-left)/2;
      while(left < right){
        int val = nums[mid];
        if(val < target){
          left = mid + 1;
        }
        else{
          right = mid;
        }
        mid = left + (right-left)/2;
      }
      if(nums[right] != target){
        right++;
      }
      return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      int left = 0;
      int right = nums.size()-1;
      int mid = right/2;

      while(left <= right){
        // cout << " mid: " << mid;
        int val = nums[mid];
        if(val < target){
          // cout << " left ";
          left = mid+1;
        }
        else if(val > target){
          // cout << " right ";
          right = mid-1;
        }
        else{
          // hit value
          // cout << " hit ";

          // find left edge
          int left = findLeft(nums, target, mid);
          // cout << "left: " << left;

          // find right edge
          int right = findRight(nums,target,mid);
          // cout << "right: " << right;

          vector<int> results;
          results.push_back(left);
          results.push_back(right);
          return results;
        }
        mid = left + (right-left)/2;
      }
      vector<int> results;
      results.push_back(-1);
      results.push_back(-1);
      return results;
    }
};
