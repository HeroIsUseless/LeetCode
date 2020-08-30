#include <vector>
#include <set>
#include <algorithm>
#include "MyLib.cpp"
using namespace std;

class Solution
{
private:
    vector<int> mNums;
    vector<int> tmp;
    vector<vector<int> > res;
    bool contain()
    {
        for(auto var: res)
        {
            vector<int> v1(tmp);
            vector<int> v2(var);
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            if(v1 == v2){
                return true;
            }
        }
        return false;
    }
    void recur(int index){
        if(!contain())
        {
            res.push_back(tmp);
        }
        for(int i=index; i<mNums.size(); i++){
            tmp.push_back(mNums[i]);
            recur(i+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        mNums = nums;
        recur(0);
        return res;
    }
};

int main(){
    vector<int> v = {1,2,2};
    Solution solution;
    solution.subsetsWithDup(v);
    return 0;
}