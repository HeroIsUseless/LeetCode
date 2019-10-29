#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int arr[200];
        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;
        int res = 0;
        int n = s.size();
        if(n == 0) return 0;
        for(int i=0; i<n; i++){
            if((i!=n-1) && (arr[s[i+1]]>arr[s[i]])){ // 如果后面的数比前面的数大
                res += arr[s[i]]*(-1);
            }
            else{
                res += arr[s[i]];
            }  
        }
        return res;
    }
};

int main(){
    string s = "III";
    Solution solution;
    cout << solution.romanToInt(s);
    return 0;
}