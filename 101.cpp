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
class Solution;
int main(){
   Solution solution;

    return 0;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        vector<TreeNode*> v1, v2;       
        v1.push_back(root->left);
        v2.push_back(root->right);
        while (v1.size() != 0){
            TreeNode *p1=v1.back(), *p2=v2.back();
            v1.pop_back(), v2.pop_back();
            if(p1!=NULL && p2!=NULL){
                if(p1->val != p2->val){return false;}
                v1.push_back(p1->right);
                v1.push_back(p1->left);
                v2.push_back(p2->left);
                v2.push_back(p2->right);
            }
            if(p1==NULL&&p2!=NULL || p1!=NULL && p2==NULL) return false;
        }
        return true;
        
    }
};