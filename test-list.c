#include <stdio.h>
#include "list.h"

void test()
{
    printf("testing lists2...\n");
    char **str_list = list("hello", "booo", "wat", "yee");
    int *int_list = list(1, 2, 3, 4, 5, 6, 7);
    assert(stbds_arrlen(str_list) == 4);
    assert(stbds_arrlen(int_list) == 7);
}

int main() {
    test();
    printf("success!\n");
    return 0;
}