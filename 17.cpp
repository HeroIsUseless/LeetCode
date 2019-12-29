#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    vector<string> res;
    void dfs(vector<string> &process, string &many, int i){
        if(i == process.size()){
            res.push_back(many);
            return;
        }
        for(int j=0; j<process[i].size(); j++){
            many = many+process[i][j];
            dfs(process, many, i+1);
            many.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v(9);
        v[1] = "abc";  v[2] = "def";  v[3]  = "ghi";
        v[4]  = "jkl"; v[5]  = "mno"; v[6]  = "pqrs";
        v[7]  = "tuv"; v[8]  = "wxyz";
        vector<string> process;
        for(int i=0; i<digits.length(); i++){
            int a = digits[i]-'0';
            process.push_back(v[i-1]);
        }
        string manyou;
        dfs(process, manyou, 0); // 后面的这个数是代表第几层了，什么是第几层呢？就是第几个process
        return res;
    }
};

// 开头写思路
// 中间写输出
// 结尾写自己编写的实验数据
int main(){
   Solution solution;

    return 0;
}
