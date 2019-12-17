#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    int x;
    int y;
    bool dp(string& s, int k, vector<vector<char>>& board, int i, int j, vector<int> path){
        if(k >= s.length()) return true; // 如果到头了，返回true
        if(i<0 || j<0 || i>=x || j>=y) return false; // 条件不成立了不行
        if(s[k] != board[i][j]) return false; // 如果不相等，返回false
        bool res = false;
        bool t;
        t = false;
        for(int var : path){ // 朝上走
            if((i-1)*y+(j) == var) t = true;
        }
        if(!t){
            vector t_path = path;
            t_path.push_back((i-1)*y+(j));
            res |= dp(s, k+1, board, i-1, j, t_path);
        } 
        t = false;
        for(int var : path){ // 朝下走
            if((i+1)*y+(j) == var) t = true;
        }
        if(!t){
            vector t_path = path;
            t_path.push_back((i+1)*y+(j));
            res |= dp(s, k+1, board, i+1, j, t_path);
        } 
        t = false;
        for(int var : path){ // 朝左走
            if((i)*y+(j-1) == var) t = true;
        }
        if(!t){
            vector t_path = path;
            t_path.push_back((i)*y+(j-1));
            res |= dp(s, k+1, board, i, j-1, t_path);
        } 
        t = false;
        for(int var : path){ // 朝右走
            if((i)*y+(j+1) == var) t = true;
        }
        if(!t){
            vector t_path = path;
            t_path.push_back((i)*y+(j+1));
            res |= dp(s, k+1, board, i, j+1, t_path);
        }         
        return res;
    }
    bool exist(string& s, vector<vector<char>>& board){
        bool res = false;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                vector<int> path; path.push_back(i*y+j);
                res |= dp(s, 0, board, i, j, path);
            }
        }
        return res;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        x = board.size(); y = board[0].size();
        vector<string> res;
        for(string s : words)
            if(exist(s, board)) res.push_back(s);
        return res;
    }
};
//  没办法重复使用的话，只能说，存住它的路径才行
int main(){
   Solution solution;
    vector<vector<char>> board=
{
  {'o','a','a','n'},
  {'e','t','a','e'},
  {'i','h','k','r'},
  {'i','f','l','v'}
};
vector<string> words=
{"oath","pea","eat","rain"};
solution.findWords(board, words);
    return 0;
}
