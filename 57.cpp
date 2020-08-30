#include <iostream>
#include <vector>
using namespace std;

//两侧向中间逼近法，
//设ia和ib，表示需要删除的位置，
//如果a在区间里，a设为区间开头，ia设为此i否则ia设为i + 1，
//然后b类似，
//最后删除ia到ib的所有区间，然后插入该区间即可。

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 求出a的位置，如果在0之前，那index就是-1
        int a = newInterval[0];
        int ia = 0;
        for (int i = 0; i < intervals.size(); i++){
            if(a>=intervals[i][0] && a<=intervals[i][1]) { // 说明在区间内
                a = intervals[i][0]; 
                ia = i;
            }
            if(a > intervals[i][1]){
                ia = i+1;
            }
        }
        // 求出b的位置
        int b = newInterval[1];
        int ib = intervals.size()-1;
        for (int i = intervals.size(); i >= 0; i--)
        {
            if (b >= intervals[i][0] && b <= intervals[i][1])
            {
                b = intervals[i][1];
                ib = i;
            }
            if (b > intervals[i][1])
            {
                ib = i;
            }
        }
        int flag = true;
        vector<vector<int>> res;
         for (int i = 0; i <= intervals.size(); i++)
        {
            if(!(i>=ia && i<=ib)) res.push_back(intervals[i]);
            else
                if(flag){
                    res.push_back({a, b});
                    flag = false;
                }
        }
        return res;
    }
};