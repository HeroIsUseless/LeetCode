#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while(numbers[i]+numbers[j] != target){
            if(numbers[i]+numbers[j] > target) j--;
            if(numbers[i]+numbers[j] < target) i++;
        }
        vector<int> v;
        v.push_back(i+1);
        v.push_back(j+1);
        return v;
    }
};
int main(){
   Solution solution;

    return 0;
}
