#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(sum > 0) sum += nums[i];
            else sum = nums[i];
            if(sum > max) max = sum;
        }
        return max;
    }
};

int main(){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout<<solution.maxSubArray(v);
    return 0;
}