#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool buying = false;
        int res = 0;
        for(int i=0; i<n-1; i++){
            if(prices[i] < prices[i+1]){ // 如果明天比今天价格高
                if(buying){ // 如果现在是满仓
                    res += prices[i+1] - prices[i]; // 明天也是满仓，中间获利记下来
                }
                else{ // 如果现在是空仓，就买入股票，顺便把中间获利记下来
                    buying = true;
                    res += prices[i+1] - prices[i];
                }
            }   
            else{ // 如果明天比今天价格低，今天就清仓
                if(buying){
                    buying = false;
                }
            }
        }
        return res;
    }
};
int main(){
   Solution solution;

    return 0;
}