#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int o = nums1.size()-1;
        for(--m, --n; m>=0 && n>=0; ){
            nums1[o--] = nums1[m]>nums2[n]?nums1[m--]:nums2[n--];
        }
        while(n >= 0) nums1[o--] = nums2[n--];
    }
};
int main(){
   Solution solution;

    return 0;
}