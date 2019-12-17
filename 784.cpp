#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    char reverse(char ch){
        if(ch>='a' && ch<='z') return ch-'a'+'A';
        if(ch>='A' && ch<='Z') return ch-'A'+'a';
        return ch;
    }
public:
    vector<int> dumpSort(vector<int> v){
        for(int i=v.size()-1; i>0; --i){
            int t = i;
            while(t/2 != 0){
                if(v[t/2] > v[t]) swap(v[t/2], v[t]);
                t /= 2;
            }
        }
        return v;
    }



    vector<string> letterCasePermutation(string s) {
        vector<string> v;
        if(s.length() == 0) return v;
        char ch = s[0];
        string ts;
        ts += ch;
        v.push_back(ts);
        if(isalpha(ch)){
            string ts;
            ts += reverse(ch);
            v.push_back(ts);
        } 
        for(int i=0; i<s.length(); i++){
            int n = v.size();
            if(n == 0){

            }
            else{
                for(int j=0; j<n; j++){
                    if(isalpha(s[i]))
                        v.push_back(v[j]+reverse(s[i]));
                    v[j] += s[i];
                }
            }
        }
        return v;
    }
};
int main(){
    string s = "a1b2";
    vector<int> v = {1,6,2,8,4,9,3};
    Solution solution;
    v = solution.dumpSort(v);
    return 0;
}
