#include <vector>
#include <string>
using namespace  std;
// dp[i][j] = dp[i-1][j] || dp[i][j-1]
// 代表s1前i个，s2前j个能不能匹配上s3的i+j个
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.length(), n2=s2.length(), n3=s3.length();
        if(n3 != (n1+n2)) return false; // 长度不同绝对不是
        bool *arr = new bool[(n1+1)*(n2+1)]();
        arr[0*n2+0]=true;
        if(s1[0] == s3[0]) arr[0*n2+1]=true;
        if(s2[0] == s3[0]) arr[1*n2+0]=true;
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                bool b1 = i-1<0?false:arr[i-1][j];
                bool b2 = j-1<0?false:arr[i][j-1];
                arr[i][j] = b1 || b2; // 感觉不对劲啊，还有本身的
            }
        }
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();
        auto f = vector < vector <int> > (n + 1, vector <int> (m + 1, false));
        if (n + m != t) return false;
        f[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return f[n][m];
    }
};
