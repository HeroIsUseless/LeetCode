#include <iostream>
#include <string>

using namespace std;

class Solution {
    bool is_gramRight(string p){
        
    }
    bool is_pEmpty(string p, int j){
        for(int i=j; i<p.length(); i++)
            if(p[i] != '*')
                return false;
        return true;
    }
public:
    bool isMatch(string s, string p) {
        if(s == "") return false;
        if(p == "") return false;
        if(is_gramRight(p)) return false;
        int sn = s.length(), pn = p.length();
        int i = 0, j = 0;

        while(j < pn){
            char ch = p[j];
            if(ch == '.'){
                i++; j++; // 如果是点，简单前进
                if(i == sn && is_pEmpty(p, j)) return true; // 如果到头了就成功
                continue;
            }
            if(ch == '*'){
                if(j == 0) return false; // '*' 开头，语法错误
                char t_c;
                if(p[j-1] == '.'){
                    t_c = s[i];
                }
                else{
                    t_c = p[j-1];
                }
                while(t_c == s[i]){
                    i++;
                    if(i == sn) return true;
                }
                j++; // 如果不相等了，p进行下一个字母 
                if(j == pn) return false;
                continue;
            }
            // 其他情况
            if(ch == s[i]){ // 对的上
                i++; j++; // 前进1
                if(i == sn) return true; // 进行检查
            }
            else{ // 对不上
                if(j+1 == pn) return false; // 如果是最后自然不行
                if(p[j+1] != '*') return false; // 没有*也不行
                else{ // 证明有*而且是下一个，p切换到下一个
                    if(j+2 == pn) return false; // 实际上仍然没有
                    else{
                        j = j+2; // 进行下一次对比
                    }
                }
            }
        }
        
        return false; // 证明i没有到头而j到头了
    }
};

int main(){
    string s="ab";
    string p=".*c";
    Solution solution;
    solution.isMatch(s, p);
    return 0;
}