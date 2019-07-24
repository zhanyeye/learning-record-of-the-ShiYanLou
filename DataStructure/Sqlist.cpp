#include <iostream>

using namespace std;
const int MAXSIZE = 100;
typedef int ElemType;

//存储结构
struct SqList {
    ElemType* data; //存储空间基地址
    int length;     //当前长度
    int max_size;   //当前分配表长大小
        
};

//初始话一个空线性表
bool InitList(SqList &L) {
    L.data = (ElemType*) malloc(sizeof(ElemType) * MAXSIZE);
    if (L.data == NULL) {
        return false;
    }
    L.length = 0;
    L.max_size = MAXSIZE;
    return true;
}

//销毁线性表
bool DestoryList(SqList &L) {
    free(L.data);
    L.length = 0;
    L.max_size = 0;
    return true;
}

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) { //判断i的范围是否有效
        return false;
    }
    if (L.length >= L.max_size) { //判断存储空间是否以满
        return false;
    }
    for (int j = L.length; j >= i; j--) { //将第i个元素及其之后元素后移
        L.data[j] = L.data[j-1]; //将数组 j-1 向后移

    }
    L.data[i-1] = e; //在位置i出放入e,注意数组从0开始
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length) { //判断范围是否有效
        return false;
    }
    e = L.data[i-1];   //保存将要被删除的元素
    for (int j = i; j < L.length; j++) { // 将第 i个位置之后的元素前移
        L.data[j-1] = L.data[j]; 
    }
    L.length--;
    return true;
}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

