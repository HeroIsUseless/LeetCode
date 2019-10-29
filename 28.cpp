#include <iostream>
#include <string>
using namespace std;

class Solution {
    int *next;
public:
    void getNext(string p){
        int n = p.size();
        next = new int[n];
        next[0] = -1;
        int i=0, j=-1;
        while(i < n-1){ 
            if((j==-1) || (p[i]==p[j])){
                i++; j++;
                next[i] = j;
            }
            else{
                j = next[j];
            }
        }
    }

    int strStr(string s, string p) {
        getNext(p);
        int s_n=s.size();
        int p_n=p.size();
        int i=0, j=0;
        while(i<s_n && j<p_n){
            if(j==-1 || s[i]==p[j]){
                i++; j++;
            }
            else{
                j = next[j];
            }
        }
        if(j == p_n)
            return i-j;
        else 
            return -1;
    }

};


int main(){
    string haystack;
    string needle;
    Solution solution;
    solution.strStr(haystack, needle);
    return 0;
}