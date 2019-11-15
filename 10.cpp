#include <iostream>
#include <string>
using namespace std;

class Solution {
        int i, j;
        int sn, pn;
public:
    // 判断是不是到头了
    bool isRightEnd(){
        if((i==sn) && (j==pn)) return true;
        else return false;
    }
    // 匹配程序
    bool isMatch(string s, string p) {
        // 预处理
        if(s == "") return false;
        if(p == "") return false;
        i=0; j=0;
        sn = s.length(); pn = p.length();
        // 进行比对循环
        while((i<sn) && (j<pn)){
            char ch = p[j];
            if(ch == '.'){
                i++; j++; // 如果是点，简单前进
                if(isRightEnd()) return true;
                continue;
            }
            if(ch == '*'){
                if(j == 0) return false; // '*' 开头，语法错误
                char t_c; // 替换字符
                if(p[j-1] == '.') // 如果前面是点的话直接相等是可以的
                    t_c = s[i];
                else // 如果不是点就是前一个字符了
                    t_c = p[j-1];
                j++; // 前进一位，摆脱'*'
                while((t_c==s[i]) && (i<sn)){ // 进行匹配
                    i++;
                }
                while((t_c==p[j]) && (j<pn)){ // 这个是需要的
                    j++;
                }
                if(isRightEnd()) return true;
                continue;  // 如果不相等了，进行下一次循环
            }
            // 其他情况
            if(ch == s[i]){
                i++; j++;
                if(isRightEnd()) return true;
            }
            else{ // 要看第二位是不是*
                if(j<pn-1 && p[j+1]=='*'){
                    j+=2; // 越过本地字符和*
                    continue;
                }
                else
                    return false; // 其实也不一定为false
            }
        }
        return false; // 证明i没有到头而j到头了
    }
};


int main(){
    string s = "aaa";
    string p = "ab*a*c*a";
    Solution solution;
    cout << solution.isMatch(s, p);
    return 0;
}