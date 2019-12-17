#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution;
int main(){
   Solution solution;

    return 0;
}
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(target == nums[mid]) return mid;
            if(target < nums[mid]){
                right = mid-1;
            }
            if(target > nums[mid]){
                left = mid+1;
            }
        }
        return left;
    }
};