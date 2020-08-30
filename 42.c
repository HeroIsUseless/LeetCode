#include <stdlib.h>
#include "MyLib.c"

int trap(int *height, int n)
{
    if (n == 0 || n == 1 || n == 2)
        return 0;
    int i;
    // 找到最高的柱子
    int height_max = max(height, n);
    int height_index = max_index(height, n);
    // 容器
    int *content = (int *)malloc(sizeof(int) * n);
    // 削左边的
    int left = height[0];
    for (i = 0; i < height_index; i++)
    {
        if (height[i] >= left)
            left = height[i];
        content[i] = left - height[i];
    }
    // 削右边的
    int right = height[n - 1];
    for (i = n - 1; i > height_index; i--)
    {
        if (height[i] >= right)
            right = height[i];
        content[i] = right - height[i];
    }
    content[height_index] = 0;
    int res = 0;
    for (i = 0; i < n; i++)
        res += content[i];
    return res;
}