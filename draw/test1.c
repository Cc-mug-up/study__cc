#include <stdio.h>
#include <malloc.h>

int main()
{
    printf("ʹ��cat /proc/%d/maps�鿴�ڴ����\n", getpid());

    // ����1�ֽڵ��ڴ�
    void *addr = malloc(1);
    printf("��1�ֽڵ��ڴ���ʼ��ַ��%x\n", addr);
    printf("ʹ��cat /proc/%d/maps�鿴�ڴ����\n", getpid());

    // �����������������������ַ�ʱ������ִ��
    getchar();

    // �ͷ��ڴ�
    free(addr);
    printf("�ͷ���1�ֽڵ��ڴ棬��heap�Ѳ������ͷ�\n");

    getchar();
    return 0;
}