#include "iostream"
using namespace std;

class Solution {
    int max;
public:
    // 用哈希的方法，具体是
    // 先一个一个的填，如果没有，就填进去，如果有了，就终止，分成三段？
    int lengthOfLongestSubstring(string s) {
        max = 0;
        recursion(s, 0, s.length()); // 是左闭右开类型的
        return max;
    }
    // 找寻最长字符串，有重复的进行拆分的递归函数
    void recursion(string s, int begin, int end){
        int n=0; // 无重复串的长度
        int ch[256]; // 一个字符数量存储结构
        for(int i=0; i<256; i++) ch[i] = -1;
        for(int i=begin; i<end; i++){ // 都是从头开始算
            if(ch[s[i]] == -1){ // 说明不存在
                ch[s[i]] = i; // 设定其位置
                n++;
                if(max < n) max = n;
            }
            else{ // 说明存在，那么就需要拆分了
                recursion(s, begin, i);
                recursion(s, ch[s[i]]+1, end);
                return;
            }
        }
    }
};

int main(){
    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s);
    return 0;
}