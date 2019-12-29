#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
class Solution {
    string getRoNum(int num){
        if(num<10){
            vector<string> v = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
            return v[num];
        }
        else if(num>=10 && num<100){
            num /= 10;
            vector<string> v = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
            return v[num];
        }
        else if(num>=100&& num<1000){
            num /= 100;
            vector<string> v = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
            return v[num];
        }
        else if(num>=1000){
            num /= 1000;
            vector<string> v = {"","M","MM","MMM"};
            return v[num];
        }
        return "";
    }
public:
    string intToRoman(int num) {
        int level=0;
        string s;
        while(num != 0){
            int t = num%10;
            t *= (int)pow(10, level);
            s = getRoNum(t) + s;
            num /= 10;
            level++;
        }
        return s;
    }
};
int main(){
   Solution solution;

    return 0;
}
