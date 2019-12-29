#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max=0;
        while(i<j){
            int t = (j-i)*min(height[i], height[j]);
            if(t > max) max = t;
            if(height[i] >= height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return max;
    }
};
int main(){
   Solution solution;

    return 0;
}
