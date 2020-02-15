#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int> > m;
        for(int i=0; i<nums.size(); i++){ // 从头到尾插入进去
            if(m.find(nums[i]) != m.end()){ // 证明之前就有这个数字
                for(int j=0; j<m[nums[i]].size(); j++){ // 就开始比较是否
                    if(abs(m[nums[i]][j])-i<=k){
                        return true;
                    } 
                }
                // 如果都大于k，那么就添加进去，进行下一个
                m[nums[i]].push_back(i);
            }
            else{ // 证明不存在
                vector<int> v;
                v.push_back(i);
                m[nums[i]] = v;
            }
        }
        return false;
    }
};
int main(){
   Solution solution;
    vector<int> v = {1,2,3,1,2,3};
    solution.containsNearbyDuplicate(v, 2);
    return 0;
}
