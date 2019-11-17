#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution {
    void function(string &s){
        for(int i=0; i<s.length(); ++i){
            s[i] -= '0';
        }
    }
public:
    string addBinary(string a, string b) {
        // 进行处理成数字
        function(a);
        function(b);
        // 处理得到长的和短的
        string x, y;
        if(a.length() > b.length()){ x = a; y = b; }
        else{ x = b; y = a; }
        // 进行组合
        for(int i=x.length()-1, j=y.length()-1; j>=0; j--, i--){
            x[i] += y[j];
        }
        // 进行增进，循环个一万遍准成
        for(int i=0; i<10; i++){ 
            bool c = false;
            for(int j=x.length(); j>=0; j--){
                x[j] += c;
                if(x[j] > 1){
                    c = true;
                    x[j]-=2;
                }
                else{ 
                    c = false;
                }
            }
            // 循环一遍完毕，如果还是有进位的话，那么得在前面加一位
            if(c){
                x = (char)1+x;
                c = false;
            }
        }
        for(int i=0; i<x.length(); i++){x[i] += '0';}
        return x;
    }
};

int main(){
   Solution solution;
    string a = "11";
    string b = "1";
    string c = solution.addBinary(a, b);
    return 0;
}