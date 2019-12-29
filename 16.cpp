#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int min = 100000;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int t = nums[i]+nums[j]+nums[k];
                    if(abs(t-target)<min) min = abs(t-target);
                }
            }
        }
        return min;
    }
};
int main(){
   Solution solution;

    return 0;
}
