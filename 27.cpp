#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0) return 0;
        int i=0;
        for(int j=0; j<n; ++j){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0) return 0;
        int i=0;
        for(int j=0; j<n; ++j){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};




int main(){
   Solution solution;
    vector<int> nums = {2};
    solution.removeElement(nums, 3);
    return 0;
}


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int)nums.size();
        if(n == 0) return 0;
        int i=0;
        for(int j=0; j<n; j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};