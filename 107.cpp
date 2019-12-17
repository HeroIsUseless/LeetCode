#include <iostream>
#include <algorithm>  
#include <vector>
#include <queue>
#include <string>
using namespace std;
class Solution;
int main(){
   Solution solution;
    int a[] = {1,2,3,4,5,6,7};
    std::reverse(a, a+7);
    for(int i=0; i<7; i++){cout <<a[i];}
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        vector<TreeNode*> v;
        v.push_back(root);
        vector<int> t_res;
        while (v.size() != 0){
            vector<TreeNode*> t_v;
            for(auto var : v){
                t_res.push_back(var->val);
                if(var->left) t_v.push_back(var->left);
                if(var->right) t_v.push_back(var->right);
            }
            res.push_back(t_res);
            v = t_v;
        }
        return reverse(t_res.begin(), t_res.end());
    }
};