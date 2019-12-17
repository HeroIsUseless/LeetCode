#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    // 如果是，则返回小写，否则返回0
    char isWord(char c){
        if((c>='a' && c<='z')||(c>='0'&&c<='9'))
            return c;
        if(c>='A' && c<='Z')
            return c - 'A' + 'a';
        return 0;
    }
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            // 去掉多于字符
            while(!isWord(s[i])){
                i++;
                if(i>=s.length()) break;
            } 
            while(!isWord(s[j])){
                j--;
                if(j<0) break;
            } 
            if(i>=j) return true;
            char a=isWord(s[i]), b=isWord(s[j]);
            if(a != b) return false;
            i++; j--;
        }
        return true;
    }
};
int main(){
   Solution solution;
    string s = "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''";
    solution.isPalindrome(s);
    return 0;
}
