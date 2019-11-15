#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    bool all_9(vector<int>& digits, int n){
        for(int i=0; i<n ;i++)
            if(digits[i] != 9) return false;
        return true;
    }
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(all_9){
            for(int i=0; i<n; i++) digits[i] = 0;
            digits[0] = 1;
            digits.push_back(0);
        }
        else{
            int c = true;
            int i=n-1;
            while (c){
                digits[i]++;
                if(digits[i] == 10) digits[i--] = 0;
                else c = false;
            }
        }
        return digits;
    }
};
int main(){
   Solution solution;
   vector<int> v = {1,2,3};
    solution.plusOne(v);
    return 0;
}