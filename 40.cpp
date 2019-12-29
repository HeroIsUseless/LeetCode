#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
    int sum(vector<int> &v){
        int res=0; for(int var : v) res += var;
        return res;
    }
    vector<vector<int> > res;
    void insert(vector<int> v){
        sort(v.begin(), v.end());
        bool flag = true;
        for(auto var : res)
            if(var == v) flag = false;
        if(flag) res.push_back(v);
    }
    void dfs(vector<int> &v, vector<int>& candidates, int l, int target){
        if(sum(v) >= target){ if(sum(v)==target) insert(v); return; }
        for(int i=l; i<candidates.size(); i++){
            v.push_back(candidates[i]);
            dfs(v, candidates, i+1, target);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        dfs(v, candidates, 0, target);
        return res;
    }
};
int main(){
   Solution solution;
    vector<int> v = {1,2,3,4,5,6,7};
    solution.combinationSum2(v,10);
    return 0;
}
