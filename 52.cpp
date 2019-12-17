#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node
{
    bool center, down, left, right;
    Node():center(true),down(true),left(true),right(true){};
    void set_false(){center = down = left = right = false;}
};

class Solution {
    int res;
    void function(int n, int line, vector<Node> v){
        if(line >= n){ res++; return; } 
        for(int i=0; i<n; i++){ // 对于下一层的每个元素
            vector<Node> t_v(n, Node());
            for(int j=0; j<n; j++){ // 承接上一层的传递值
                if(v[j].left == false) if(j-1>=0) t_v[j-1].center=t_v[j-1].left = false;
                if(v[j].down == false) t_v[j].center=t_v[j].down = false;
                if(v[j].right== false) if(j+1 <n) t_v[j+1].center=t_v[j+1].right= false;
            }
            if(t_v[i].center == false) continue;
            else{
                t_v[i].set_false(); // 本身先设置成false
                function(n, line+1, t_v);
            }
        }
    }
public:
    // 每一行的是否可用都可以用上一行加三个参数来确定
    // 
    int totalNQueens(int n) {
        function(n, 0, vector<Node>(n, Node()));
        return res;
    }
};
int main(){
   Solution solution;
    solution.totalNQueens(4);
    return 0;
}
