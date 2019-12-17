#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // 返回它在第几层
    int level(TreeNode* root){
        if(root == NULL) return 0;
        int a = level(root->left);
        int b = level(root->right);
        return (a>b?a:b)+1;
    }
public:
    // 判断两棵子树是否小于1，如果不小于1，返回false，如果小于1，返回它们之中为false的
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int a = level(root->left);
        int b = level(root->right);
        if(abs(a-b) > 1) return false;
        else return isBalanced(root->left)&isBalanced(root->right);        
    }
};
int main(){
   Solution solution;

    return 0;
}
