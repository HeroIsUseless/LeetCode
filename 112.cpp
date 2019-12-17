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
    // 保证不会运行空节点
    bool function(TreeNode *root, int sum, int res){
        if(root == NULL) return false;
        bool result = false;
        result |= function(root->left, sum, root->val+res);
        result |= function(root->right,sum, root->val+res);
        if(root->left==NULL && root->right == NULL){//到叶子节点了
            if(root->val+res == sum) result = true;
        }
        return result;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return function(root, sum, 0);
    }
};
int main(){
   Solution solution;

    return 0;
}
