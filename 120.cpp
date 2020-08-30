#include <vector>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<int> dp(m);
        dp[0] = triangle[0][0];
        
        for (int i = 1; i < n; ++i)
        { // 正在做的第几行
            m = triangle[i].size();
            dp[0] += triangle[i - 1][0];
            for (int j = 1; j < m - 1; ++j)
            { // 针对中间每一个元素
                dp[j] = max(triangle[i][j] + dp[j - 1], triangle[i][j] + dp[j]);
            }
            dp[m - 1] += triangle[i - 1][m - 2];
        }
        int max = dp[0];
        for (int i = 0; i < m; i++)
        {
            if (max < dp[i])
                max = dp[i];
        }
        return max;
    }
};