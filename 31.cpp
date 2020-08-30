#include <stdio.h>
#include "MyLib.c"
void nextPermutation(int nums[], int n)
{
    if (n <= 1) return;
    int i = n - 2, j = n - 1, k = n - 1;
    // find: A[i]<A[j]
    while (i >= 0 && nums[i] >= nums[j])
    {
        i--;
        j--;
    }

    if (i >= 0) { // 不是最后一个排列
        // find: A[i]<A[k]
        while (nums[i] >= nums[k])
        {
            k--;
        }
        swap(&nums[i], &nums[k]);
    }
    invert(nums + j, n - j);
}
int main(){
    int arr[] = {1, 3, 2};
    nextPermutation(arr, 3);
    int i;
    for (i = 0; i < 3; i++)
        printf("%d ", arr[i]);
        return 0;
}


