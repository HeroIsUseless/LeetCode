#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4) return res;
        sort(nums.begin(), nums.end());
        for(int k=0; k<n-3; k++){
            if(k>0 && nums[k]==nums[k-1]) continue;
            int min = nums[k]+nums[k+1]+nums[k+2]+nums[k+3];
            if(min>target) continue;
            int max = nums[k]+nums[n-1]+nums[n-2]+nums[n-3];
            if(max<target) continue;
            for(int i=k+1; i<n-2; i++){
                if(i>k+1 && nums[i] == nums[i-1]) continue;
                int j = i+1;
                int h = n-1;
                int min = nums[k]+nums[i]+nums[j]+nums[j+1];
                if(min>target) continue;
                int max=nums[k]+nums[i]+nums[h]+nums[h-1];
                if(max<target) continue;
                while(j<h){
                    int t = nums[k]+nums[i]+nums[j]+nums[h];
                    if(t == target){
                        res.push_back(vector<int>({nums[k],nums[i],nums[j],nums[h]}));
                        j++;
                        while(j<h&&nums[j]==nums[j-1]) j++;
                        h--;
                        while(j<h&&i<h&&nums[h]==nums[h+1]) h--; 
                    }else if(t > target){
                        h--;
                    }else {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};
