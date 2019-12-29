#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            bool flag1[9] = {false};
            bool flag2[9] = {false};
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(flag1[board[i][j]-'1'] == false) flag1[board[i][j]-'1'] = true;
                    else return false;
                }
                if(board[j][i] != '.'){
                    if(flag2[board[j][i]-'1'] == false) flag2[board[j][i]-'1'] = true;
                    else return false;
                }
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                bool flag[9] = {false};
                for(int p=0; p<3; p++){
                    for(int q=0; q<3; q++){
                        if(board[i*3+p][j*3+q] == '.') continue;
                        if(flag[board[i*3+p][j*3+q]-'1'] == false) flag[board[i*3+p][j*3+q]-'1'] = true;
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};
int main(){
   Solution solution;

    return 0;
}
