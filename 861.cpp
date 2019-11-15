#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    int function(vector<int> A){
        int n = A.size();
        int res = 0;
        int num2 = 1;
        for(int i=0; i<n; i++){
            res += A[n-i-1]*num2;
            num2 *= 2;
        }
        return res;
    }
public:
    int matrixScore(vector<vector<int>>& A) {
        int x = A.size(); // 多少行
        int y = A[0].size(); // 多少列
        // 先进行行翻转
        for(int i=0; i<x; i++){ // 对于每一行
            if(A[i][0] == 0){ // 如果第一行是0的话
                for(int j=0; j<y; j++){ // 进行翻转成开头是1的
                    if(A[i][j] == 0) A[i][j] = 1;
                    else A[i][j] = 0;
                }
            }
        }
        // 从第二列开始，再进行其他列翻转
        for(int j=1; j<y; j++){ 
            int n1 = 0; // 先统计1的个数，决定是否要翻转
            for(int i=0; i<x; i++){
                if(A[i][j] == 1) n1++;
            }
            if(n1 < y/2){ // 如果少于一半就进行翻转
                for(int i=0; i<x; i++){
                    if(A[i][j] == 1) A[i][j] = 0;
                    else A[i][j] = 1;
                }
            }
        }
        // 进行转码相加
        int res = 0;
        for(int i=0; i<x; i++){
            int t = function(A[i]); // 转码函数
            res += t;
        }
        return res;
    }
};

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size(); // 行
        int col = A[0].size(); // 列
        //行移动
        for(int i=0; i<row; i++) {
            if(A[i][0] == 0) {//如果第一个数是0，则进行翻转
                for(int j=0; j<col; j++){
                    A[i][j] ^= 1;
                }
            }
        }
        
        int sum = row * pow(2, col-1);//第一列全为1，sum初始值、
        for(int i=1; i<col; i++) {// 对于每一列
            int count = 0;
            for(int j=0; j<row; j++) {
                if(A[j][i] == 1)//统计1的个数
                    count++;
            }
            if(count <= row/2) {//列反转条件,不用进行翻转操作，直接计算
                count = row - count;
            }
            sum += count * pow(2, col - i -1);
        }
        return sum;
    }
};

int main(){
   Solution solution;

    return 0;
}