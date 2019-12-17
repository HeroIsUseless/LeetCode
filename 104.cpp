#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution;
int main(){
   Solution solution;

    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 1; 
        root->val = 1;    
        vector<TreeNode*> v;  
        v.push_back(root);
        while (v.size() != 0){
            TreeNode *p=v.back(); v.pop_back();
            if(p->left){
                p->left->val = p->val+1;
                if(depth < p->left->val){depth = p->left->val;}
                v.push_back(p->left);
            }
            if(p->right){
                p->right->val = p->val+1;
                if(depth < p->right->val){depth = p->right->val;}
                v.push_back(p->right);
            }
        }
        return depth;
    }
};