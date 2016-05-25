/**************************************
* 用户输入M,N值，从1至N开始顺序循环数数，
*每数到M输出该数值，直至全部输出 
***************************************/

#include <iostream>
using namespace std;

//节点
typedef struct node
{
	int data;
	struct node* next;
}node;

//创建循环链表
void createList(node* &head, node* &tail, int n)
{
    if(n<1)
    {
        head = NULL;
        return ;
    }
    head = new node(); //C中的malloc函数分配的内存空间即在堆上,C++中对应的是new操作符。
    head->data = 1;
    head->next = NULL;
    
    node* p = head;
    for(int i=2; i<n+1; i++)
    {
        p->next = new node();//C中的malloc函数分配的内存空间即在堆上,C++中对应的是new操作符。
        p = p->next;
        p->data = i;
        p->next = NULL;
    }
    
    tail = p;
    p->next = head;//尾节点指向头结点
}

// 打印循环链表
void Print(node* &head)
{
    node* p = head;
    
    while(p && p->next!=head)
    {
        //printf("%d ", p->data);
        cout<<p->data<<" ";
        p=p->next;
    }
    if(p)
    {
        //printf("%d/n", p->data);
        cout<<p->data<<endl;
    }
}

// 用户输入M,N值，从1至N开始顺序
// 循环数数，每数到M输出该数值，
// 直至全部输出
void CountPrint(node* &head, node* &tail, int m)
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
            //printf("%d ", cur->data);
            cout<<cur->data<<" ";
            delete cur;
            cur = pre->next;
            cnt = m-1;
        }    
    }
    
    if(cur)
    {
        //printf("%d ", cur->data);
        cout<<cur->data<<" ";
        delete cur;
        head = tail = NULL;
    }
    //printf("/n");
    cout<<endl;
}

int main()
{
    node* head;
    node* tail;
    int m;
    int n;
    //printf("please input m and n:\n");
    //scanf("m = %d", &m);
    //scanf("n = %d", &n);
    cout<<"please input m and n:"<<endl;
    cout<<"m = ";
    cin>>m;
    cout<<"n = ";
    cin>>n;
    createList(head, tail, n);
    Print(head);
    CountPrint(head, tail, m);
    return 0;
}