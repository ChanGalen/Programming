/***************************************************
*一个学生的信息是：姓名，学号，性别，年龄等信息，
*用一个链表，把这些学生信息连在一起， 
*给出一个age, 在些链表中删除学生年龄等于age的学生信息。
*****************************************************/

#include "stdio.h"
//#include "conio.h"

struct stu
{
	char name[20];
	char sex;
	int  no;
	int  age;
	struct stu *next;
}*linklist;

//创建链表
struct stu *creatlist(int n)
{
    int i;
    struct stu *h, *p, *s;//h为头结点，p为前一结点，s为当前结点
    h = (struct stu *)malloc(sizeof(struct stu));
    h->next = NULL;
    p = h;
    for (i = 0; i < n; ++i)
    {
    	s = (struct stu *)malloc(sizeof(struct stu));
    	p->next = s;
    	printf("Please input the information of the student: name sex no age \n");
    	scanf("%s  %c  %d  %d", s->name, &s->sex, &s->no, &s->age);
    	s->next = NULL;
    	p = s;
    }
    printf("Create Successful! \n");
    return(h);
}

//删除学生年龄等于age的学生信息
void deletelist(struct stu *s, int a)
{
    struct stu *p;
    while(s->age != a)
    {
       p = s;
       s = s->next;
    }
    if(s == NULL)
    {
    	printf("The record is not exist! \n");
    }
    else
    {
    	p->next = s->next;  //删除年龄等于a的学生信息，p->next为当前节点
    	printf("Delete Successful! \n");
    }
}

//显示学生信息
void display(struct stu *s)
{
     s = s->next;
     while(s != NULL) //单链表
     {
        printf("%s  %c  %d  %d \n", s->name, s->sex, s->no, s->age);
        s = s->next;
     }
}

int main(int argc, char const *argv[])
{
	struct stu *s;
	int n, age;
	printf("Please input the length of seqlist:\n");
	scanf("%d",&n);
	s = creatlist(n);
	display(s);
	printf("Please input the age:\n");
	scanf("%d",&age);
	deletelist(s,age);
	display(s);
	return 0;
}