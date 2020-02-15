#include <iostream>
#include <string>
using namespace std;

class Solution {
    void process(string &s){
        int n = s.length();
        char *ar = new char[n];
        int ar_n = 0;
        // 将字母替换成数字
        for(int i=0; i<n; i++){
            // 检查是否存在，如果存在，就不用赋予新的值了
            bool is_exist = false;
            int j;
            for(j=0; j<ar_n; j++){
                if(s[i] == ar[j]){ // 证明存在
                    is_exist = true;
                    break;
                }
            }
            if(is_exist){
                s[i] = j+'0';
            }
            else{ // 如果不存在的话
                ar[ar_n] = s[i];
                s[i] = ar_n+'0';
                ar_n++;
            }
        }
    }
public:
    bool isIsomorphic(string s, string t) {
        process(s);
        process(t);
        if(s == t) return true;
        else return false;
    }
};

int main(){
    string s = "qwerqwer";
    string t = "qwerqwewrfadsvqrqefasdr";
    Solution solution;
    solution.isIsomorphic(s,t);
    return 0;
}