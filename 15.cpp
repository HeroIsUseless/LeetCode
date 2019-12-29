#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
    vector<vector<int>> res;
    void insert(vector<int> t){
        sort(t.begin(), t.end());
        int flag = true;
        for(auto var : res){
            if(var[0]==t[0] && var[1]==t[1] && var[2]==t[2]) flag = false;
        }
        if(flag) res.push_back(t);
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] > 0) break;
            int l = i+1, r = n-1;
            while(l < r){
                int t = nums[i]+nums[l]+nums[r];
                if(t == 0){
                    l++;
                    insert(vector<int>({nums[i],nums[l],nums[r]}));
                } 
                if(t > 0) r--;
                if(t < 0) l++;
            }
        }
        return res;
    }
};
int main(){
   Solution solution;

    return 0;
}


