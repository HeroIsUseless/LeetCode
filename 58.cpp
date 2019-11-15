#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    bool isEmpty(string &s){
        for(auto ch : s) if(ch != ' ') return false;
        return true;
    }
public:
    int lengthOfLastWord(string s) {
        if(isEmpty(s)) return 0;
        // 现在确认非空，一定有单词
        int i = s.length()-1;
        int n = 0;
        while(s[i]==' ') i--; // 找到第一个位置
        while(s[i]!=' ' && i>=0){
            n++; i--;
        }
        return n;
    }
};
int main(){
   Solution solution;

    return 0;
}