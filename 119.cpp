#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1; i<=numRows; i++){
            vector<int> tv;
            for(int j=0; j<i; j++){
                if(j==0 || j==i-1){
                    tv.push_back(1);
                }
                else{
                    tv.push_back(res[i-2][j-1]+res[i-2][j]);
                }
            }
            res.push_back(tv);
        }
        return res[res.size()-1];
    }
};
int main(){
   Solution solution;

    return 0;
}
