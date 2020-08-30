#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> tmp;

    void func(vector<int> &candidates, int index, int tar)
    {
        for (int i = index; i < candidates.size(); i++)
        {
            if (tar - candidates[i] > 0)
            { // 继续递归
                tmp.push_back(candidates[i]);
                func(candidates, i, tar - candidates[i]);
                tmp.pop_back();
            }
            else if (tar - candidates[i] == 0)
            { // 就是它了
                tmp.push_back(candidates[i]);
                result.push_back(tmp);
                tmp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        func(candidates, 0, target);
        return result;
    }
};

int main(){

    return 0;
}