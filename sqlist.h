//
// Created by Alexander on 2019/4/25.
//

#ifndef LINERLIST_SQLIST_H
#define LINERLIST_SQLIST_H

#include <cstdlib>
#include <cstdio>

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *&L, ElemType a[], int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        L->data[i] = a[i];
    }
    L->length = n;
}

void InitList(SqList *&L) {
    L = (SqList *) malloc(sizeof(SqList));
    L->length = 0;
}

void DestroyList(SqList *&L) {
    free(L);
    L = nullptr;
}

bool ListEmpty(SqList *L) {
    return L->length;
}

int ListLength(SqList *L) {
    return L->length;
}

void DispList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

bool GetElem(SqList *L, int i, ElemType &e) {
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i - 1];
    return true;
}

int LocateElem(SqList *L, ElemType e) {
    int i = 0;
    for (i = 0; i < L->length; i++) {
        if (L->data[i] == e)
            break;
    }
    if (i >= L->length)
        return 0;
    else return i + 1;
}

bool ListInsert(SqList *&L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    i--;
    for (int t = L->length; t > i; t--) {
        L->data[t] = L->data[t - 1];
    }
    L->data[i] = e;
    L->length += 1;
    return true;
}

bool ListDelete(SqList *&L, int i, ElemType &e) {
    if (i < 1 || i > L->length)
        return false;
    i--;
    e = L->data[i];
    for (int j = i; j < L->length - 1; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}

#endif //LINERLIST_SQLIST_H
