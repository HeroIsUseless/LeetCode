#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 预处理，在间隔处补0
        vector<char> s_v = {0};
        for(int i=0; i<s.length(); i++){
            s_v.push_back(s[i]);
            s_v.push_back(0);
        } 
        int len = s_v.size(); // 预处理后的字符串长度
        int pali_len[len]; // 每个字符的回文长度，但只是半径，且不包括中心
        for(int i=0; i<len; i++) pali_len[i] = 0;
        // 进行比较
        int mid_center = 0; // 极右边界的回文串中心
        int right_border = 0; // 极右边界
        int max_center = 0; // 最长回文子串的中心
        int max_length = 0; // 最长回文子串的长度，同样是半径，且不包括中心
        for(int right_center=0; right_center<len; right_center++){ // 对于每个右边回文串的中心
            int need_expand = true;
            if(right_border > right_center){ // 在范围内
                int left_center = mid_center - (right_center-mid_center); // 不会出现小于0的情况
                pali_len[right_center] = pali_len[left_center];
                if(pali_len[right_center]+right_center >= right_border){ // 一个修正
                    pali_len[right_center] = right_border-right_center;
                }
                else{
                    need_expand = false;
                }
            }
            if(need_expand){
                while (right_center-pali_len[right_center]-1>=0 && right_center+1+pali_len[right_center]<len){
                    if(s_v[right_center-pali_len[right_center]-1] == s_v[right_center+1+pali_len[right_center]]){
                        pali_len[right_center]++;
                    }
                    else{
                        break;
                    }
                }
                right_border = right_center+pali_len[right_center];
                mid_center = right_center;
                if(pali_len[right_center] > max_length){
                    max_center = right_center;
                    max_length = pali_len[right_center];
                }
                
            }
        }
        string r_s;
        for(int i=max_center-max_length; i<=max_center+max_length; i++){
            if(s_v[i] != 0)
                r_s += (char)s_v[i];
        }
        return r_s;
    }

};
// 0123210
// 0c0c0c0
// 0123456
int main(){
    string s = "ccc";
    Solution solution;
    cout<<solution.longestPalindrome(s);
    return 0;
}

