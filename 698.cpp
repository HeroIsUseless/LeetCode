#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1){//数组本身就是它的一个子集
          return true;  
        }
        if(k>nums.size()){  //不可能构成k个子集
            return false;
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k){
            return false;
        }
        int n=nums.size(),target=sum/k,curSum=0;
        vector<int> used(n,0);
        return ifSubsets(nums,0,0,target,curSum,k,used);
    }
    bool ifSubsets(vector<int>& nums, int start,int n,int target,int curSum,int k,vector<int>& used)
    {// start表示搜索的起点，n为当前已经搜索过的数字数目，curSum为当前的累加和，target，k,used和定义一致
        if(curSum>target){return false;}
        if(k==0&&n==nums.size()){return true;}
        if(curSum==target){  //已经存在一个集合
            return ifSubsets(nums,0,n,target,0,k-1,used);  //继续从第一个数字开始搜索,start变为0,当前和变为0
        }
        for(int i=start;i<nums.size();i++)
        {//curSum<target
            if(used[i]==0)//还没有使用过
            {
                used[i]=1;  //标识
                if(ifSubsets(nums,i+1,n+1,target,curSum+nums[i],k,used)){ //还是给第k个子集找值,所以k不变;要把i处的值加上，并从他的下一个位置搜索
                    return true;
                }
                used[i]=0;  //说明上述子集中没有用到i,所以恢复状态等待下次使用
            }
        }
        return false;
    }
};

class Solution {
    bool backtracking(vector<int> &nums, int k, int target, int cur, int start, bool* used) {
        // 返回条件
        if (k == 0) return true; // 这个k就是划分的多少个集合
        if (cur == target) { // target就是一个子集合多大
            // 如果本集合成功，构建下一个集合，下面的就不管了
            return backtracking(nums, k-1, target, 0, 0, used);
        }
        for (int i = start; i < nums.size(); i++) { // 从start开始到末尾
            if (!used[i] && (int)(cur+(int)nums[i]) <= (int)(target)) {// 如果没有使用并且小于等于
                used[i] = true; // 就使用它
                if (backtracking(nums, k, target, cur+nums[i], i+1, used)) return true;
                used[i] = false; // 回归原位置
            }
        }
        return false;
    }
    
public: 
    bool canPartitionKSubsets(vector<int> nums, int k) {
        // 注意nums[i] > 0
        int sum = 0, maxNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (maxNum < nums[i]) maxNum = nums[i];
        }
        if (sum % k != 0 || maxNum > sum/k) return false; // 常规避险
        bool* used = new bool[nums.size()]; // 一个使用标记变量
        return backtracking(nums, k, sum/k, 0, 0, used);
    }
};

int main(){
    vector<int> nums = {4,3,2,3,5,2,1};
    Solution solution;
    cout<<solution.canPartitionKSubsets(nums, 4);
    return 0;
}