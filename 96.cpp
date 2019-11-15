#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int *arr;
    int n;
public:
    // 在这个范围内有多少种树的变换形态
    int f(int begin, int end){
        if((end-begin) == 0) return 1; // 最终的情况了
        int res = 0;
        for(int i=begin; i<end; i++){ // 对于每个头节点的遍历
            int t1;
            if(arr[begin*n + i] != 0) 
                t1 = arr[begin*n + i];
            else{
                t1 = f(begin, i); 
                arr[begin*n + i] = t1;
            } 
            int t2;
            if(arr[(i+1)*n + end] != 0) 
                t2 = arr[(i+1)*n + end];
            else{
                t2 = f(i+1, end); 
                arr[(i+1)*n + end] = t2;
            }
            res += t1*t2; // 每棵树的多少取决于子树的乘积
        }
        return res;
    }

    int numTrees(int n) {
        int* G = new int[n + 1];
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }

};

int main(){
   Solution solution;
    cout << solution.numTrees(3);
    return 0;
}