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
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        if(root->left!=NULL && root->right!=NULL){
            int a = minDepth(root->left);
            int b = minDepth(root->right);
            return (a<b?a:b)+1;
        }
        if(root->left!=NULL && root->right==NULL)
            return minDepth(root->left)+1;
        if(root->left==NULL && root->right!=NULL)
            return minDepth(root->right)+1;
        return 0;
    }
};
int main(){
   Solution solution;

    return 0;
}
