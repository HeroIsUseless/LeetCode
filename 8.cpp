#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str == "-2147483648") return -2147483648; // 因为此负数无法用正数转换
        int i = 0; // 控制位
        while(str[i] == ' ') i++; // 跳过空格
        // 如果出现别的字符就停住
        if(((str[i]<48+0) || (str[i]>48+9)) && (str[i]!='-') && (str[i]!='+')) return 0;
        bool is_nega = false; // 是否为负数
        // 去掉符号
        if(str[i] == '-'){
            is_nega = true;
            i++; // 这样跳过负号了
            if(str[i] == '+') return 0; 
        }
        if(str[i] == '+'){
            i++; // 不用管
            if(str[i] == '-') return 0; 
        } 
        int res = 0;
        while(i<str.length()){
            if((str[i]<48+0) || (str[i]>48+9)){
               break; // 如果出现其他字符就停下（包括空格）
            }
            // 分成两部分判断
            if((res==214748364) && (str[i]-48>=8)){
                if(is_nega) return -2147483648;
                else return 2147483647;
            } 
            if((res>214748364)){
                if(is_nega) return -2147483648;
                else return 2147483647;
            } 
            res *= 10;
            res += str[i]-48;
            i++;
        }
        if(is_nega) res *= -1;
        return res;
    }
};

int main(){
    string s = "   -42";
    Solution solution;
    cout<<solution.myAtoi(s);
    return 0;
}