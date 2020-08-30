int firstMissingPositive(int *nums, int n)
{
    int i;
    int res = 1; 
    for (i = 0; i < n; i++){
        if(nums[i]>0 && nums[i]<=res)
            res = nums[i] + 1;
    }
    return res;
}