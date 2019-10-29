#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        char *stack = new char[n];
        int s_n = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                stack[s_n++] = '(';
            }
            if(s[i] == '['){
                stack[s_n++] = '[';
            }
            if(s[i] == '{'){
                stack[s_n++] = '{';
            }
            if(s[i] == ')'){
                if(s_n-1>=0 && stack[s_n-1]=='(') s_n--;
                else return false;
            }
            if(s[i] == ']'){
                if(s_n-1>=0 && stack[s_n-1]=='[') s_n--;
                else return false;
            }
            if(s[i] == '}'){
                if(s_n-1>=0 && stack[s_n-1]=='{') s_n--;
                else return false;
            }
        }
        if(s_n == 0) return true;
        else return false;
    }
};

int main(){
    string s = "([)]";
    Solution solution;
    cout << solution.isValid(s);
    return 0;
}