#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//几种动态内存管理的错误

// 1.对NULL指针的解引用
int main()
{
    int* p = (int*)malloc(40);
    *p = 20;  //如果开辟失败p会变成NULL，而NULL不能解引用，所以这里要判断p是否为空
    return 0;
}

// 2.对动态开辟空间的越界访问
int main()
{
    int* p = (int*)malloc(40);
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    }
    for (int i; i <= 10; i++)
    {
        p[i] = i;                 // 越界访问
    }
    free(p);
    p = NULL;
    return 0;
}

// 3.对非动态开辟空间的free释放
int main()
{
    int a = 20;
    int* p = &a;
    //……
    free(p);
    p = NULL;       // p所指向的空间不是动态开辟出来的
    return 0;
}

// 4.使用free释放动态开辟内存的一部分
int main()
{
    int* p = (int*)malloc(40);
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    }
    for (int i; i < 10; i++)
    {
        *p = i;
        p++;
    }                 // 这里p所指向的位置在最后，没有指向这项空间的起始位置，无法通过p来释放空间
    free(p);
    p = NULL;
    return 0;
}

// 5.对同一块空间的多次释放
int main()
{
    int* p = (int*)malloc(40);
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    }
    //……
    free(p);
    p = NULL;
    //……
    free(p);

    return 0;
}

// 6.动态开辟内存忘记释放(内存泄漏)
void test()
{
    int* p = (int*)malloc(40);
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    }
    int i;
    scanf("%d", &i);
    if (i == 0)
    {
        return 0;
    }                             // 函数可能在这就结束了 , p就没有被释放
    free(p);
    p = NULL;
}
int main()
{
    test();
    return 0;
}