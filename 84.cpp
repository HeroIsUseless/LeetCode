#include <vector>

using namespace std;
// 用栈获取左边的
// 用栈获取右边的
// 结构体是{height, index}
struct Node
{
    int height;
    int index;
    Node(int cIndex, int cHeight) : height(cHeight), index(cIndex) {}
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 获取左边的
        vector<Node> lstack;
        vector<int> lefts;
        lstack.push_back(Node(-1, 0));
        for(int i=0; i<heights.size(); i++){
            while(lstack.back().height >= heights[i]){
                if(lstack.size() == 1) break;
                lstack.pop_back();
            } 
            lefts.push_back(lstack.back().index + 1);
            Node *node = new Node(heights[i], i); // 以1开头
            lstack.push_back(*node);
        }
        // 获取右边的
        vector<Node> rstack;
        vector<int> rights;
        rstack.push_back(Node(heights.size(), 0));
        for(int i=heights.size()-1; i>=0; i--){
            while(rstack.back().height > heights[i]){
                if (rstack.size() == 1) break;
                rstack.pop_back();
            } 
            rights.push_back(rstack.back().index - 1);
            Node *node = new Node(heights[i], i);
            rstack.push_back(*node);
        }
        // 计算
        int res=0;
        for(int i=0; i<heights.size(); i++){
            int s = heights[i]*(rights[i] - lefts[i] + 1);
            if(res < s) res = s;
        }
        return res;
    }
};