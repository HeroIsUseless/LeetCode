int* twoSum(int* nums, int numsSize, int target) {
    int element_max = INT_MIN, element_min = INT_MAX;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < element_min)
            element_min = nums[i];
        if (nums[i] > element_max)
            element_max = nums[i];
    }//找到最大值和最小值
    //它的思路是，额，如果对于其中的一个数，target被它减后的值不再区间中，自然不行
    //它是用了一个hashtable类似的性质，存进去，并没有顺序可言，且只遍历一遍
    //而且，嗯，就是这样，我也不认为这个哈希表有什么用。。。
    //如果说，数的总量，和极差之间，谁大谁小是不一定的
    #define BITMAP_LENGTH 26137//啥意思，而且哇塞，是在里面定义的，学习了
    int bitmap[BITMAP_LENGTH] = {0};//嗯，没错，看得懂
    int *result = (int *)malloc(2 * sizeof(int));//嗯，题目要求的
    for (int i = 0; i < numsSize; ++i) {//一个大for循环
        if (target - nums[i] < element_min || target - nums[i] > element_max) 
            continue;
        if (bitmap[(nums[i] - element_min) % BITMAP_LENGTH] != 0) {
            //bitmap不是哈希，但是很像哈希
            //减去极小值，然后取模，因为开的足够大，假设没有重复这是
            result[0] = bitmap[(nums[i] - element_min) % BITMAP_LENGTH] - 1;
            result[1] = i;
            break;//返回结果
        }
        bitmap[(target - nums[i] - element_min) % BITMAP_LENGTH] = i + 1;
    }
    return result;
}