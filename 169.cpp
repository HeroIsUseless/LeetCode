class Solution {
    int n;
    int node_n;
    TreeNode *head;
public:
    vector<vector<int>> res;
    // 压入输出的过程
    void add_res(){
        vector<int> t_res; // 临时结果变量
        vector<TreeNode*> queue; // 操作队列
        queue.push_back(head); // 首先填入队列
        while(queue.size() != 0){
            TreeNode* tp = queue.front(); // 拿出一个节点
            queue.erase(0); // 删除这个节点，vector没有相关的功能
            TreeNode *t1 = new TreeNode(1);
            if(tp->left == NULL) queue.push_back(t); // 如果左节点为空的话也要添加一个空节点
            else if(tp->val == 0)  queue.push_back(tp->left); // 不然就添加这个节点，而且必须不是空节点
            TreeNode *t2 = new TreeNode(1); 
            if(tp->right==NULL) queue.push_back(t2); // 如果右节点为空的话也要添加一个空节点
            else if(tp->val == 0) queue.push_back(tp->right); // 不然就添加这个节点，而且必须不是空节点
            if(tp->val == 0) t_res.push_back(0); 
            else t_res.push_back(null);
        }
        res.push_back(t_res); // 最终完全添加
    }
    // 一个递归函数
    void function(TreeNode *node){
        if(node_n == N) { // 一个预防结束的过程，极端情况(只有一个节点)才会发生
            add_res();
            return;
        }
        node->left = new TreeNode(0); // 插入左右节点
        node->left = new TreeNode(0);
        node_n += 2; // 节点数加2
        if(node_n == n){ // 如果满了直接输出并返回
            add_res(); 
            return;
        }
        // 如果没有满，就向下递归
        function(node->left);
        function(node->right);
        delete node->left; // 恢复原状
        delete node->right;
        node->left = NULL;
        node->right=NULL;   
    }

    vector<TreeNode*> allPossibleFBT(int N) {
        if((N%2) == 0) return res;
        n = N; // 全局变量用
        node_n = 1; // 头节点不会消失的，首先设置
        head = new TreeNode(0);
        function(head); // 进行递归
        return res; // 返回
    }

};