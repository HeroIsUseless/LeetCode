#include "iostream"
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int preMax = 0;
        int nowMax = 0;
        for(int i=0; i<n; i++){
            int t = nowMax;
            nowMax = (preMax+nums[i])>nowMax?(preMax+nums[i]):nowMax;
            preMax = nowMax;
        }
        return nowMax;
    }
};

int main(){

    return 0;
}