#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���ֶ�̬�ڴ����Ĵ���

// 1.��NULLָ��Ľ�����
int main()
{
    int* p = (int*)malloc(40);
    *p = 20;  //�������ʧ��p����NULL����NULL���ܽ����ã���������Ҫ�ж�p�Ƿ�Ϊ��
    return 0;
}

// 2.�Զ�̬���ٿռ��Խ�����
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
        p[i] = i;                 // Խ�����
    }
    free(p);
    p = NULL;
    return 0;
}

// 3.�ԷǶ�̬���ٿռ��free�ͷ�
int main()
{
    int a = 20;
    int* p = &a;
    //����
    free(p);
    p = NULL;       // p��ָ��Ŀռ䲻�Ƕ�̬���ٳ�����
    return 0;
}

// 4.ʹ��free�ͷŶ�̬�����ڴ��һ����
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
    }                 // ����p��ָ���λ�������û��ָ������ռ����ʼλ�ã��޷�ͨ��p���ͷſռ�
    free(p);
    p = NULL;
    return 0;
}

// 5.��ͬһ��ռ�Ķ���ͷ�
int main()
{
    int* p = (int*)malloc(40);
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    }
    //����
    free(p);
    p = NULL;
    //����
    free(p);

    return 0;
}

// 6.��̬�����ڴ������ͷ�(�ڴ�й©)
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
    }                             // ������������ͽ����� , p��û�б��ͷ�
    free(p);
    p = NULL;
}
int main()
{
    test();
    return 0;
}