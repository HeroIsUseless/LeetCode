#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int row) {
        if(row == 1) return s;
        if(row == 2){
            string str;
            for(int i=0; i<s.length(); i++){
                if(i%2 == 0){
                    str += s[i];
                }
            }
            for(int i=0; i<s.length(); i++){
                if(i%2 == 1){
                    str += s[i];
                }
            }
            return str;
        }
        int len = s.length();
        int col = (len/row+1)*(len/row+1); // 乘以2倍来容纳足够量
        int n = row*col;
        int *arr = new int[n]; // 定义这个二维数组
        for(int i=0; i<n; i++) arr[i] = 0;
        int x=0, y=0; // 行和列
        bool is_stand = true; // 是否向下插入
        // 插入二维数组中
        for(auto ch : s){
            if(is_stand){ // 如果继续向下
                arr[y*col+x] = ch;
                y++;
                if(y == row){ // 说明到头了
                    is_stand = false;
                    y-=2;
                    x++; // 进行下一列
                }
            }
            else{ // 否则进行斜向插入
                arr[y*col+x] = ch;
                y--;
                x++;
                if(y == 0){ // 说明到顶了
                    is_stand = true;
                }
            }
        }
        // 进行收缩
        string str;
        for(int i=0; i<n; i++){
            if(arr[i] != 0) str+=arr[i];
        }
        return str;
    }

};

int main(){
    string s = "PAYPALISHIRING";
    Solution solution;
    string str = solution.convert(s, 5);
    cout<<s<<endl;
    cout << str;
    return 0;
}