#include <iostream>

using namespace std;

typedef int ElemType;

struct LNode {
    ElemType data; //数据域
    LNode* next;   //指针域
};

//头插法建立单链表
LNode* CreateList1(LNode* L) {
    LNode* s; //辅助指针
    L = (LNode*)malloc(sizeof(LNode)); //创建头节点
    L->next = NULL;  //初始化为空链表
    int n;
    cin >> n;
    while (n) { 
        s = (LNode*)malloc(sizeof(LNode));
        cin >> s->data;
        s->next = L->next;
        L->next = s;
        n--;
    }
    return L;
}

LNode* CreateList2(LNode* L) {
    L = (LNode*) malloc(sizeof(LNode)); //创建头节点
    L->next = NULL;   //初始为空链表
    LNode *s, *r = L; //s 为辅助指针; r 为表尾指针,记录表尾
    int n;
    cin >> n;
    while(n) {
        s = (LNode*)malloc(sizeof(LNode));
        cin >> s->data;
        r->next = s;
        r = r->next;
        n--;
    }
    return L;
}


LNode* GetElem(LNode* L, int i) {
    int cnt = 1; //计数初始为1
    if (i == 0) return L; //若i等于0, 则返回头节点
    if (i < 1) return NULL; //若i无效,返回NULL
    LNode *p = L->next;
    while (p && cnt < i) {
        p = p->next;
        cnt++;
    }
    return p;
}

LNode* LocateElem(LNode* L, ElemType e) {
    LNode* p = L->next;
    while (p != NULL && p->data != e) 
        p = p->next;
    return p;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

