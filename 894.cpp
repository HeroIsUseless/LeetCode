#include <iostream>
#include <vector>
using namespace std;  

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res; // 作为结果，里面都是头指针
        if((N%2) == 0) return res; // 如果是偶数是不成立的
        if(N == 1){ // 如果只有一个值，添加进去直接返回，不进行递归
            TreeNode* head = new TreeNode(0);
            res.push_back(head);
        }
        else{ // 如果有三个以上的值，直接递归
            for(int x=0; x<N; x++){
                int y = N-1-x;
                for(auto var_x : allPossibleFBT(x)){
                    for(auto var_y : allPossibleFBT(y)){
                        TreeNode* head = new TreeNode(0);
                        head->left = var_x;
                        head->right= var_y;
                        res.push_back(head);
                    }
                }
            }
        }
        return res;
    }

};

int main(){
    Solution solution;
    solution.allPossibleFBT(7);
    return 0;
}