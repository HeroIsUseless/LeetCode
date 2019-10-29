#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int quick_sort(vector<vector<int>>& points, int begin, int end){
        int i=begin, j=end-1;
        vector<int> flag = points[i]; // 为距离值
        while(1){
            while(points[j][2] > flag[2]){
                j--;
                if(i == j) goto end;
            }
            points[i] = points[j]; // 这里就是j找到了
            i++;
            if(i == j) goto end;
            while(points[i][2] <= flag[2]){
                i++;
                if(i == j) goto end;
            }
            points[j] = points[i]; // 这里就是i找到了
            j--;
            if(i == j) goto end;
        }
        end:
        points[i] = flag;  // 最后赋值
        return i;
    }

    void select(vector<vector<int>>& points, int begin, int end, int k){
        int i = quick_sort(points, begin, end);
        if(i+1 == k){return;} // 如果排完后，这个数等于，那么就结束
        if(i+1 > k){select(points, begin, i+1, k);} // 如果排完后，这个数比较大的话，从0到这个数，随便取一个，进行k的快排
        if(i+1 < k){select(points, i+1, end, k);} // 如果排完后，这个数比较小的话，从这个数到末尾，随便取一个，进行m-k的快排
    }

// 用快速排序，找出前k个数就行
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 预处理
        int n = points.size();
        for(int i=0; i<n; i++)
            points[i].push_back(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
        // 进行排序
        select(points, 0, n, k);
        vector<vector<int>> res;
        for(int i=0; i<k; i++){
            vector<int> vt;
            vt.push_back(points[i][0]); vt.push_back(points[i][1]);
            res.push_back(vt);
        }
        return res;
    }

};

int main(){
    vector<vector<int>> points = {{-2,10},{-4,-8},{10,7},{-4,-7}};
    Solution solution;
    solution.kClosest(points, 3); // 数组和前n个
    return 0;
}