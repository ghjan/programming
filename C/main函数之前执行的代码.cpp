#include <stdio.h>
#include <stdlib.h>
void init(void) __attribute__((constructor));

void init(void){

    printf("before enter main!\n");

}

void exit_func(void){

    printf("after leave main!\n");

}

int main(void){

    int *m = (int *)malloc(sizeof(int));

    atexit(exit_func);

    printf("hello world!\n");

}
/*
ȫ�ֱ������죬�����ȫ�������Ĺ��캯������  ��  ��� __attribute__((constructor))���Եĸ���������
���Ƕ�Ӧ���ڽ���mainǰ���е��á�
*/ 
