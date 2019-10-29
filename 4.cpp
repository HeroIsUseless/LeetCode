#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> nums;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        while((i<nums1.size()) || (j<nums2.size())){
            if(i == nums1.size()){ // 如果nums1到头了，直接填nums2
                nums.push_back(nums2[j++]);
                continue;
            } 
            if(j == nums2.size()){ // 如果nums2到头了，直接填nums1
                nums.push_back(nums1[i++]);
                continue;
            } 
            if(nums1[i] > nums2[j]){ // 正常的填充
                nums.push_back(nums2[j++]);
            } 
            else if(nums1[i] < nums2[j]){
                nums.push_back(nums1[i++]);
            }
            else{ // 说明相等的
                nums.push_back(nums1[i++]);
                nums.push_back(nums2[j++]);
            }
        }
        // 下面寻找中位数
        int count = nums.size();
        if(count%2 == 0){ // 是偶数个
            return ((double)nums[count/2]+(double)nums[count/2-1])/2;
        }
        else{ // 是奇数个
            return (double)nums[count/2];
        }
        return 0;
    }
};

int main(){
    vector<int> nums1 = {1,1,1,1,1,1,1,1,1,1,4,4};
    vector<int> nums2 = {1,3,4,4,4,4,4,4,4,4,4};
    Solution solution;
    cout<<solution.findMedianSortedArrays(nums1,nums2);
    // for(int i=0; i<solution.nums.size(); i++){
    //     cout<<solution.nums[i]<<endl;
    // }
    return 0;
}