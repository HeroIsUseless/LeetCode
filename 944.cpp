#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution;
int main(){
   Solution solution;

    return 0;
}
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size()==0) return 0;
        int res = 0;
        for(int j=0; j<A[0].length(); j++){ // 对于每一列
            for(int i=0; i<A.size()-1; i++){ // 就这么一行行的比较
                if(A[i][j] > A[i+1][j]){
                    res++;
                    break;
                }
            }
        }
        return  res;
    }
};