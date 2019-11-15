#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int x, y;
    long *arr;
public:
    // 检测是不是不合规矩或者没有路径
    bool check(int ci, int cj, vector<vector<int>>& obstacleGrid){
        if(ci<0 || cj<0){ // 如果其中一个越界了，就不行 
            return false;
        }
        if(obstacleGrid[ci][cj] == 1){ // 如果有障碍物，也不行
            return false;
        }
        return true;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        x = obstacleGrid.size();
        y = obstacleGrid[0].size();
        // 容错处理
        if(x == 0) return 0;
        if(y == 0) return 0;
        // if(y == 1){
        //     if(obstacleGrid[0][0]==0) return 1;
        //     if(obstacleGrid[0][0]==1) return 0;

        // } 
        // 创建数组
        arr = new long[x*y]; 
        for(int i=0; i<x; i++){ // 进行清零
            for(int j=0; j<y; j++){
                arr[i*y + j] = 0;
            }
        }
        arr[0] = 1;
        // 开始动态规划填表，如果上面有路径，就加上路径，左边有路径，就加上路径，如果没有，就加0好了
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(check(i-1, j, obstacleGrid)){
                    arr[i*y + j] += arr[(i-1)*y + j];
                }
                if(check(i, j-1, obstacleGrid)){
                    arr[i*y + j] += arr[i*y + j-1];
                }
            }
        }
        // 如果最后一个元素是1，那么返回0了
        if(obstacleGrid[x-1][y-1] == 1) return 0;
        else return arr[(x-1)*y+y-1];
    }
};
int main(){
   Solution solution;

    return 0;
}

