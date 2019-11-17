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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;       
        v1.push_back(p);
        v2.push_back(q);
        while (v1.size() != 0){
            TreeNode *p1=v1.back(), *p2=v2.back();
            v1.pop_back(), v2.pop_back();
            if(p1!=NULL && p2!=NULL){
                if(p1->val != p2->val){return false;}
                v1.push_back(p1->left);
                v1.push_back(p1->right);
                v2.push_back(p2->left);
                v2.push_back(p2->right);
            }
            if(p1==NULL&&p2!=NULL || p1!=NULL && p2==NULL) return false;
        }
        return true;
    }
};
int main(){
   Solution solution;

    return 0;
}