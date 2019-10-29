#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x == -2147483648) return 0;
        bool is_nega = false;
        if(x < 0){
            x *= -1;
            is_nega = true;
        } 
        int result = 0;
        int arr[20] = {0}; int n = 0;
        while(x != 0){
            int t = x%10;
            arr[n++] = t;
            x = x/10;
        }
        for(int i=0; i<n; i++){
            if(result > 214748364) return 0;
            result *= 10;
            result += arr[i];
        }
        if(is_nega) result *= -1;
        return result;
    }
};
int main(){
    Solution solution;
    cout << solution.reverse(-12345);
    return 0;
}