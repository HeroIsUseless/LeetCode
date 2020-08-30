#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        int minPrice = prices[0];
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i)
        {
            dp[i] = (dp[i - 1] > prices[i] - minPrice) ? dp[i - 1] : prices[i] - minPrice;
            if (minPrice > prices[i])
                minPrice = prices[i];
        }
        return dp[n - 1];
    }
};