#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
int findDuplicate(int* nums, int numsSize) {
    int flag=0;
    for(int t=1; t<numsSize;t++){
        for(int i=0;i<numsSize;i++){
            if(nums[i]+t==numsSize)
                flag++;
            if(flag>=2)
                return nums[i];
        }
        flag=0;
    }
    return 1;
}

int main() {
    int n;

    printf("请输入数组大小：");
    scanf("%d", &n);

    // 动态分配内存
    int* nums = (int*)malloc(n * sizeof(int));

    printf("请输入 %d 个整数 (数字范围在1到%d之间，且只有一个重复数字):\n", n, n-1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // 显示输入的数组
    printf("输入的数组为: [");
    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // 查找重复数字
    int result = findDuplicate(nums, n);
    printf("重复的数字是: %d\n", result);

    // 释放内存
    free(nums);

    return 0;
}