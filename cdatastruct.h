#define Maxsize 100
#define TRUE 1
#define FALSE 0
typedef struct SqList{
    ElemType data[Maxsize];
    int length;
}SqList;             //静态线性表
typedef struct SeqList{
    ElemType *data;
    int MaxSize,length;
}SeqList;           //动态分配线性表
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;   //链式线性表
typedef struct DulNode{
    ElemType data;
    struct DulNode *prior,*next;
}DulNode,*DLinklist;//双向链表节点

bool ListInsert(SqList &L,int i,ElemType e){                  //在顺序表L的第i个位置插入新元素e
    if(i<1||i>L->length+1){
        return FALSE;
    }
    if(L->length>=MaxSize){
        return FALSE;
    }
    for(int j=L.length;j>=i;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=e;
    L.length++;
    return TRUE;
}
bool ListDelete(SqList &L,int i,int &e){                     //删除顺序表的第i个元素
     if(i<1||i>L->length+1){
        return FALSE;
    }
    e=L->data[i-1];
    for (int j = i; <|j < L->length ; j++) {
        L->data[j-1]=L->data[j];
    }
    L->length--;
    return TRUE;
}
int ListLocate(SqList L,ElemType e){                        //查找e所在顺序表的位置
    int i;
    for(i = 0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return FALSE;
}
LNode *LinkedGetElem(LinkList L,int i){                           //取出第i个节点--链表
    int j=1;
    LNode *p=L->next;
    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
LNode *LinkedLocate(LinkList L,ElemType e){                     //安值查找链表节点所在位置,若没有则返回NULL
    LNode *p=L->next;
    while(p!=NULL&&P->data!=e)
        p=p->next;
    return p;
}
bool LinkedInsert(LinkList &L,int i,ElemType e){               //删除链表
    LNode *p=LinkedGetElem(L,i-1);
    if(p==NULL)
        return FALSE;
    LNode s;
    s.data=e;
    s.next=p->next;
    p->next=&s;
    return TRUE;
}
bool LinkedDelete(LinkList &L,int i){
    LNode *p=LinkedGetElem(L,i-1);
    if p=NUll
        return FALSE;
    LNode *s=p->next;
    p->next=s->next;
    free(s);
    return TRUE;
}

