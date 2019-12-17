#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node{
    int var;
    int layer;
    Node(int v):var(v), layer(9999){}
};
class Solution {
    int x, y;
    // 如何初始化这个队列
    void init(vector<Node> &que, int var, int pos){
        if(pos == x*y+1) que.push_back(Node(var));
        else{
            init(que, convert(var, pos, 1), pos+1);
            init(que, convert(var, pos, 0), pos+1);
        }
    }
    int convert(int var, int pos, int b){
        if(b == 1){

        }
        if(b == 0){

        }
        return var;
    }
    void dfs(vector<vector<int>> mat, int ci, int cj){
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){

            }
        }
    }
public:
// 从第一个开始，每一个都是无限循环的，但是它必定会大于。。。
    int minFlips(vector<vector<int>>& mat) {
        x = mat.size(); if(x == 0) return;
        y = mat[0].size(); if(y==0)return;
        vector<Node> que;
        init(que, 0, 1);
        dfs(que, 0, 0);
    }
};
int main(){
   Solution solution;
    solution.minFlips();
    return 0;
}

