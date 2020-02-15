#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    vector<vector<int> > res;
    bool *flag;
    int n;
    void dfs(vector<int>& nums, vector<int> &t, bool *flag){
        if(t.size() == n) {
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
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        flag = new bool[n]();
        vector<int> t;
        dfs(nums, t, flag);
        return res;
    }
};
int main(){
   Solution solution;

    return 0;
}
