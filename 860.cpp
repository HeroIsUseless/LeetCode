#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5=0, b10=0, b20=0;
        for(auto bill : bills){
            if(bill == 5) b5++;
            if(bill == 10){
                b10++; 
                if(b5 == 0) return false;  // 出现错误
                else b5--; // 找零
            }
            if(bill == 20){
                if(b10 != 0){ // 找一个10块的
                    b10--;
                    if(b5 == 0) return false;
                    else b5--;
                }
                else{ // 否则就不找10块的
                    if(b5 < 3) return false; 
                    else b5 -= 3;
                }
            }
        }
        return true;
    }
};

int main(){
   Solution solution;

    return 0;
}