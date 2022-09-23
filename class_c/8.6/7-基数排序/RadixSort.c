#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
void RadixSort(int *a,int length)
{
    int i,max = a[0],base = 1;
    //先找最大值，赋值给max
    for(i = 0 ; i < length;i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    int *t = (int *)malloc(sizeof(int) *length);
    //循环结束的条件：最大数的位数就是循环的次数
    while (max/base > 0)
    {
        int bucket[10] = {0};//bucket[1] = 2; 第一次循环为例：表示个位数为1的数有两个
        //以个数为例：统计每个数个位出现的次数
        for(i = 0;i < length;i++)
        {
            bucket[a[i]/base % 10]++;//a[i]/base % 10:例如1234/1%10 = 4:取个位的数字
        }
        //将个位出现的次数进行累加，方法：b[1] = b[0] + b[1] b[1] = b[1] + [2]....
        for(i = 1; i < 10;i++)
        {
            bucket[i] += bucket[i - 1];
        }
        //循环将a[i]的值，按照个位排序放入到数组t中
        for(i = length-1; i>= 0; i--)
        {
            t[bucket[a[i]/base % 10] - 1] = a[i];
            bucket[a[i]/base % 10]--;//个位数相同，相同的个位数防止到其前面一位
        }
        //循环将数组t中的元素赋值给数组a
        for(i = 0 ; i < length;i++)
        {
            a[i] = t[i];
        }
        //开始进行十位/百位/千位。。比较
        base = base *10;
    }
}
int main(int argc, char const *argv[])
{
    int i;
    //int array[10] = {9,8,2,4,1,3,5,7,0,6};
    int array[10000] = {0};
    srand(time(NULL));
    for(i = 0; i < 10000;i++)
    {
        array[i] = rand() % 1000;
    }
    int length = sizeof(array)/sizeof(array[0]);
    RadixSort(array,length);
    for(i = 0 ; i < length;i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
    return 0;
}