#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0, i0=0;
        int n=nums.size();
        bool *arr = new bool[n];
        for(int i=0; i<n; i++) arr[i] = false; // 一个标记数组
        arr[0] = true; 
        // 两个指针的追赶法
        int end = 0;
        int index = 0;
        while(1){
            int t = nums[index] + index; // 在此位置上，最远能到多远
            if(t > end) end = t; // 如果它比最远的还远，更新最远
            if(end >= n-1) return true; // 如果最远的已经到达最后了，返回true
            if(index < end) // 如果没有到达最后，前进1，进行下一次循环
                index++;
            i++; // 一个一万的计数
            if(i > 10000) return false;
        }     
    }
};
int main(){
   Solution solution;
    vector<int> nums = {2,3,1,1,4};
    solution.canJump(nums);
    return 0;
}