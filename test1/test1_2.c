// 用户输入M,N值，从1至N开始顺序
// 循环数数，每数到M输出该数值，
// 直至全部输出
#include <stdio.h>

// 节点
typedef struct node
{
    int data;
    node* next;
}node;

// 创建循环链表
void createList(node*& head, node*& tail, int n)
{
    if(n<1)
    {
        head = NULL;
        return ;
    }
    head = new node();
    head->data = 1;
    head->next = NULL;
   
    node* p = head;
    for(int i=2; i<n+1; i++)
    {
        p->next = new node();
        p = p->next;
        p->data = i;
        p->next = NULL;
    }
   
    tail = p;
    p->next = head;
}

// 打印循环链表
void Print(node*& head)
{
    node* p = head;
   
    while(p && p->next!=head)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    if(p)
    {
        printf("%d\n", p->data);
    }
}

// 用户输入M,N值，从1至N开始顺序
// 循环数数，每数到M输出该数值，
// 直至全部输出
void CountPrint(node*& head, node*& tail, int m)
{
    node* cur = head;
    node* pre = tail;
   
    int cnt = m-1;
    while(cur && cur!=cur->next)
    {
        if(cnt)
        {
            cnt--;
            pre = cur;
            cur = cur->next;
        }
        else
        {
            pre->next = cur->next;
            printf("%d ", cur->data);
            delete cur;
            cur = pre->next;
            cnt = m-1;
        }   
    }
   
    if(cur)
    {
        printf("%d ", cur->data);
        delete cur;
        head = tail = NULL;
    }
    printf("\n");
}

int main()
{
    node* head;
    node* tail;
    int m;
    int n;
    scanf("%d", &n);
    scanf("%d", &m);
    createList(head, tail, n);
    Print(head);
    CountPrint(head, tail, m);
    //system("pause");
    return 0;
}
