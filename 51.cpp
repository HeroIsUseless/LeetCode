class Solution {
    vector<vector<string>> vvs; // 作为最后结果
public:
    void change(vector<vector<bool>> &vvb, int x, int y){
        int n = vvb.size();
        for(int i=0; i<n; i++){
            vvb[x][i] = false; // 横向修改
            vvb[i][y] = false; // 纵向修改
            if(x-i>=0 && y-i>=0) vvb[x-i][y-i] = false; // 左上方修正
            if(x+i< n && y+i< n) vvb[x+i][y+i] = false; // 右下角修正
            if(x-i>=0 && y+i< n) vvb[x-i][y+i] = false;
            if(x+i< n && y-i>=0) vvb[x+i][y-i] = false; 
        }
    }
    void function(int n, vector<string> vs, vector<vector<bool>> vvb){
        int x = vs.size(); // 已经有多少行了
        if(x < n){
            for(int y=0; y<n; y++){
                if(x != 0) if(vvb[x][y] == false) continue; // 不符合约束条件，不能执行
                string s; // 最后一行的字符串和初始化
                for(int i=0; i<n; i++) if(i == y) s+='Q'; else s+='.';
                vector<string> t_vs = vs; 
                t_vs.push_back(s);
                vector<vector<bool>> t_vvb = vvb;
                change(t_vvb, x, y); // 重新修改vvb
                function(n, t_vs, t_vvb); // 递归向下执行
            }
        }
        else vvs.push_back(vs);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vs;
        vector<vector<bool>> vvb; // 作为一个判断数组用
        for(int i=0; i<n; i++){
            vector<bool> vb; 
            for(int j=0; j<n; j++) vb.push_back(true);
            vvb.push_back(vb);
        } // vvb初始化
        function(n, vs, vvb);
        return vvs;
    }
};
