#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(); 
        if(n == 0) return {-1, -1};
        if(n == 1){
            if(nums[0] == target) return {0,0};
            else return {-1, -1};
        }
        int l=0, r=n-1, m;
        while(l <= r){
            m = (l+r)/2;
            if(nums[m] > target) r = m-1;
            if(nums[m] < target) l = m+1;
            if(nums[m] ==target) break;
        }
        if(nums[m] != target) return {-1, -1};
        int i1=m, i2=m;
        while(i1>=0 && nums[i1]==nums[m]) i1--; i1++;
        while(i2<n  && nums[i2]==nums[m]) i2++; i2--;
        return {i1, i2};
    }
};
int main(){
   Solution solution;
   vector<int> v = {1,4};
    solution.searchRange(v, 4);
    return 0;
}
