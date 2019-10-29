#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size(); if(x == 0) return false;
        int y = matrix[0].size(); if(y == 0) return false;
        int i=0, j=0;
        bool flag=false; // 最后的检测变量
        while(i<x && j<y){ // 只有同时成立才行，如何检测到最后的。。。
            if(matrix[i][j] >= target){ // 目标找到了
                for(int k=0; k<=i; k++){ // 列遍历
                    if(matrix[k][j] == target) return true;
                }
                for(int k=0; k<=j; k++){ // 行遍历
                    if(matrix[i][k] == target) return true;
                }
            }
            if(i < x-1) i++; 
            if(j < y-1) j++; // 循环真是个问题
            if((i==x-1) && (j==y-1)){if(flag){break;}else{flag = true;}}
        }
        return false;
    }

};

// {1,   4,  7, 11, 15},
// {2,   5,  8, 12, 19},
// {3,   6,  9, 16, 22},
// {10, 13, 14, 17, 24},
// {18, 21, 23, 26, 30}

int main(){
    vector<vector<int>> matrix = 
    {
        {-1,3}
    };
    Solution solution;
    cout << solution.searchMatrix(matrix, 3);
    return 0;
}