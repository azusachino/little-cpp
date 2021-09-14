#include <malloc.h>
#include <string.h>

int a = 0; // global initialized area
char *p1; // global uninitialized area

main() {
    int b; // stack
    char s[] = "abc"; // stack
    char *p2; // stack
    char *p3 = "123456"; // '123456\0' constant, p3 stack
    static int c = 0; // global (static) initialized area

    // 分配得来得10和20字节的区域就在堆区。
    p1 = (char*) malloc(10);
    p2 = (char*) malloc(20);

    //  123456\0放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方。
    strcpy(p1, "123456");
}