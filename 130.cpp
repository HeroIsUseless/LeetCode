#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    int x, y;
    void dfs(vector<vector<char>>& board, int i, int j){
        board[i][j] = '#';
        if(i-1>=0 && board[i-1][j]=='O') dfs(board, i-1, j);
        if(j-1>=0 && board[i][j-1]=='O') dfs(board, i, j-1);
        if(i+1<x-1&& board[i+1][j]=='O') dfs(board, i+1, j);
        if(j+1<y-1&& board[i][j+1]=='O') dfs(board, i, j+1);
    }
public:
    void solve(vector<vector<char>>& board) {
        x = board.size(); if(x==0) return;
        y = board[0].size(); if(y==0) return;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(board[i][j]=='O' && (i==0 || j==0 || i==x-1 || j==y-1))
                    dfs(board, i, j);
            }
        }
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
int main(){
    vector<vector<char>> board=
    {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}};
   Solution solution;
    solution.solve(board);
    return 0;
}
