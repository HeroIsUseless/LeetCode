#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    Solution solution;

    return 0;
}

class Solution
{
    int line;
    
    int pos(int i, int j) { return i * line + j; } // 方便的返回位置
    int max(int a, int b) { return a > b ? a : b; } // 最大值
public:
    int findMaxForm(vector<string> &strs, int n0, int n1)
    {
        if (strs.size() == 0 || (n0 == 0 && n1 == 0)) return 0;
        line = n1;
        int *dp = new int[(n0 + 1)* (n1 + 1)]();
        for (int i = 0; i < strs.size(); i++)
        {
            int numsOf0 = 0;
            int numsOf1 = 0;
            string str = strs[i];
            for (int j = 0; j < str.length(); j++)
            {
                if (str[j] == '0')
                {
                    numsOf0++;
                }
                else
                {
                    numsOf1++;
                }
            }
            for (int j = n0; j >= numsOf0; j--)
            {
                for (int k = n1; k >= numsOf1; k--)
                {
                    dp[pos(j, k)] = max(dp[pos(j, k)], 1 + dp[pos(j - numsOf0, k - numsOf1)]);
                }
            }
        }
        return dp[pos(n0, n1)];
    }
};

class Solution {
    int count(string &s, char num){
        int res=0;
        for(int i=0; i<s.length(); i++) if(s[i] == num) res++;
        return res;
    }
public:    
    int findMaxForm(vector<string>& strs, int m, int n) {
        long size = strs.size();
        int *dp = new int[(m+1)*(n+1)]();
        for (int i=0; i<size; i++) {
            int numsOf0 = count(strs[i], '0');
            int numsOf1 = count(strs[i], '1');
            for (int j = m; j>=numsOf0; j--) {
                for (int k = n; k>=numsOf1; k--) {
                    dp[j*(n+1)+k] = max(dp[j*(n+1)+k], dp[(j-numsOf0)*(n+1)+k-numsOf1]+1);
                }
            }
        }
        return dp[m*(n+1)+n];
    }
};
