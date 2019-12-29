#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int sum(vector<int> &v){
    int res=0;
    for(int i=0; i<v.size(); i++)
        res += v[i];
    return res;
}
class Solution {
    vector<vector<int>> res;
    map<int, bool> m;
    void dfs(vector<int> v, int a, int target){
        if(sum(v) >= target){
            if(sum(v) == target) res.push_back(v);
            return;
        }
        for(int i=a; i<=target; i++){
            if(m[i]){
                v.push_back(i);
                dfs(v, i, target);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int var : candidates) m[var] = true;
        vector<int> v;
        dfs(v, 1, target);
        return res;
    }
};
int main(){
   Solution solution;

    return 0;
}
