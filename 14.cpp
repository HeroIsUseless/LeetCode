#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        int n = strs.size();
        if(n == 0) return s;
        for(int i=0; i<strs[0].size(); i++){
            char c = strs[0][i];
            int j;
            for(j=0; j<n; j++){ // 字符的横向比较
                if(strs[j][i] != c) break;
            }
            if(j != n) break;
            else s += c;
        }
        return s;
    }
};

int main(){
    vector<string> s;
    Solution solution;
    solution.longestCommonPrefix(s);
    return 0;
}