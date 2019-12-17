#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto var : nums)
            res ^= var;
        return res;
        
    }
};
int main(){
   Solution solution;

    return 0;
}
