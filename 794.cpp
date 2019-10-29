#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
// 判断是否O的数量大于X的数量，如果是返回true
    bool isBeginError(vector<string>& board){
        int X_n=0, O_n=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j] == 'X') X_n++;
                if(board[i][j] == 'O') O_n++;
            }
        }
        if(X_n-O_n>=0 &&(X_n-O_n<2)) return false;
        else return true;
    }

    bool isLink(char ch1, char ch2, char ch3){
        if(ch1 == ' ') return false;
        if(ch1 == ch2){
            if(ch2 == ch3){
                return true;
            }
        }
        return false;
    }
    // 判断是否出现两个人都赢，如果是返回true
    bool isWinError(vector<string>& board){
        int win[1000] = {0};
        if(isLink(board[0][0], board[0][1], board[0][2])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][0], board[2][0])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][1], board[2][2])) win[board[0][0]]++;
        if(isLink(board[0][1], board[1][1], board[2][1])) win[board[0][1]]++;
        if(isLink(board[0][2], board[1][1], board[2][0])) win[board[0][2]]++;
        if(isLink(board[1][0], board[1][1], board[1][2])) win[board[1][0]]++;
        if(isLink(board[2][0], board[2][1], board[2][2])) win[board[2][0]]++;
        if(win['X'] * win['O']){
            cout<<"Y"<<win['X'] << win['O']<<endl;
            return true;
        } 
        else{
            cout<<"N"<<win['X'] << win['O']<<endl;
            return false;
        } 
    }

    bool validTicTacToe(vector<string>& board) {
        if(isBeginError(board)) return false;
        if(isWinError(board)) return false;
        return true;
    }
};

int main(){
    vector<string> board = {"XXX","XOO","OO "};
    Solution solution;
    solution.validTicTacToe(board);
    return 0;
}

class Solution {
public:
    bool res;
    char XO[2];
    Solution(){
        res = false;
        XO[0] = 'X'; XO[1] = 'O';
    }

    bool validTicTacToe(vector<string>& board) {
        if(isEmpty(board)) return true;
        vector<string> manual = {"   ","   ","   "};
        generate(manual, board, 0);
        return res;
    }
    // 递归生成所有可能的棋谱
    // order从0开始，偶数时甲下，奇数时乙下
    void generate(vector<string>& manual, vector<string>& board, int order){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(manual[i][j] != ' ') continue; // 如果不为空就不要往里面填
                else{
                    manual[i][j] = XO[order%2]; // 为偶数下X，为奇数下O
                    if(isSame(board, manual)){res=true; return;} // 如果相同的话，立即设为res，之后的运算都没有意义了
                    if(isFull(manual)){manual[i][j] = ' '; continue;} // 如果满了，就没有下的必要了，但是还要恢复原状，供下面使用
                    if(isWin(manual)){manual[i][j] = ' '; continue;} // 既然赢了，就没有下的必要了，下面以它为基础的棋谱不会出现
                    generate(manual, board, order+1);
                    manual[i][j] = ' '; // 严格还原现场，保证在相等之前是正确的棋谱
                } 
            }
        }
    }
    // 判断是不是相同
    bool isSame(vector<string>& manual, vector<string>& board){
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(manual[i][j] != board[i][j]) return false;
        return true;
    }
    // 判断棋谱是不是满了
    bool isFull(vector<string>& manual){
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(manual[i][j] == ' ') return false;
        return true;
    }
    // 判断棋谱是不是空的
    bool isEmpty(vector<string>& manual){
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(manual[i][j] != ' ') return false;
        return true;
    }
    // 判断棋谱是不是赢了
    bool isWin(vector<string>& board){
        int win[1000] = {0};
        if(isLink(board[0][0], board[0][1], board[0][2])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][0], board[2][0])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][1], board[2][2])) win[board[0][0]]++;
        if(isLink(board[0][1], board[1][1], board[2][1])) win[board[0][1]]++;
        if(isLink(board[0][2], board[1][1], board[2][0])) win[board[0][2]]++;
        if(isLink(board[1][0], board[1][1], board[1][2])) win[board[1][0]]++;
        if(isLink(board[2][0], board[2][1], board[2][2])) win[board[2][0]]++;
        if(win['X'] + win['O']) return true;
        else return false;
    } 
    // 三个是不是连在一起了
    bool isLink(char ch1, char ch2, char ch3){
        if(ch1 == ' ') return false;
        if(ch1 == ch2)
            if(ch2 == ch3)
                return true;
        return false;
    }

};
