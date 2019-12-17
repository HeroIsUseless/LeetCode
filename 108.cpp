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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(0, nums.size(), nums);
    }

    TreeNode* makeTree(int begin, int end, vector<int>& nums) {
        if(end-begin == 0) return NULL; // 如果是0个，就返回空
        int mid = (begin+end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(end-begin == 1) return root;
        if(end-begin == 2){
            root->left = makeTree(begin, mid, nums);
            return root;
        }
        if(end-begin >= 3){
            root->left = makeTree(begin, mid, nums);
            root->right= makeTree(mid, end, nums);
            return root;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return helper(nums,0,nums.size()-1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right)
            return nullptr;
        int mid = (left+ right) /2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left,mid -1);
        root->right = helper(nums,mid+1, right);
        return root;
    }
};

// 对于二分法来说，全部是数据比较好做一点