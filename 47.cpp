#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
    vector<vector<int> > res;
    bool *flag;
    int n;
    
    void dfs(vector<int> &nums, vector<int> &t, bool *flag){
        if(count(flag, flag+n, false)==0) { // 没有false值了，到头了
            if(count(res.begin(), res.end(), t)==0)// 并不重复
                res.push_back(t);
            return; 
        }
        for(int i=0; i<n; i++){
            if(flag[i] == true) continue;
            flag[i] = true;
            t.push_back(nums[i]);
            dfs(nums, t, flag);
            flag[i] = false;
            t.pop_back();
        }
    }
public:
// 不仅要判断有没有重复数，而且还要在res里判断是否重合
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        flag = new bool[n](); // 是否使用的地图，true代表被使用
        vector<int> t;
        dfs(nums, t, flag); 
        return res;
    }
};

int main(){
   Solution solution;

    return 0;
}
