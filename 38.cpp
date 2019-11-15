#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s = "1"; // 不会出现为0的
        for(int i=2; i<=n; i++){ // 从2到n的那个运算
            string t = ""; // 临时记录字符串
            int j1=0;     
            int j2=0; // 快慢指针
            while(j2 < s.length()){ // 如果抵达终点，终止此字符串处理
                while(s[j1]==s[j2] && j2<s.length()){ // 否则快慢指针读取同长度
                    j2++;
                }  
                if(j2-j1 == 0) continue; // 此时它一定是长度
                else{
                    t+=j2-j1+'0'; // 这个长度不应该这么算
                    t+=s[j1]; // 它是可以这么算的
                }
                j1 = j2; // 慢指针前进
            }
            cout <<i<<": "<< s<<endl; // 输出这个
            s = t; // 进行下次处理的准备
        }
        return s;
    }
};
int main(){
   Solution solution;
    solution.countAndSay(30);
    return 0;
}