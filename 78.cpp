#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> mnums;
    vector<vector<int>> res;
    vector<int> tmp;
    void recur(int i)
    {
        if(i == mnums.size()) return;

        res.push_back(tmp);
        recur(i+1);

        tmp.push_back(mnums[i]);
        recur(i+1);
        tmp.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        mnums = nums;
        recur(0);
        return res;
    }
};