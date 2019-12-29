#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                for(int j=n-1; j>0; j--){
                    if(nums[j]>nums[i-1] && j>i-1){
                        int t = nums[j];
                        nums[j]=nums[i-1];
                        nums[i-1]=t;
                        for(int k=i; k<(n+i)/2; k++){
                            int t = nums[k];
                            nums[k]=nums[n-1+i-k];
                            nums[n-1+i-k]=t;
                        }
                        return;
                    }
                }
            }
            
        }
    }
};
int main(){
   Solution solution;

    return 0;
}
