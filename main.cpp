#include <iostream>
#include "sqlist.h"
#include "cstdio"
#include "stdio.h"
int main() {;
    int a[3] = {1, 2, 3};
    SqList *L;
    InitList(L);
    CreateList(L,a,sizeof(a)/ sizeof(ElemType));
    ListInsert(L,3,999);
    DispList(L);
    return 0;

}