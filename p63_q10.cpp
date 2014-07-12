#include <stdio.h>
#include <stdlib.h>
#include <math.h>//add at 2014/7/12

typedef struct node* ptrtonode;
struct node
{
	int num;
	ptrtonode pre;
	ptrtonode next;
};

void creatjose(int n,int m,ptrtonode jose)
{
	int i;
	ptrtonode lasttmp,nowtmp;
	ptrtonode josee;
	if (n > 1)
		jose ->num = 1;
	else
		printf("you have enter an invalid value of N");
	
	josee = lasttmp = jose;

	for(i=2;i<=n;i++)
	{
		nowtmp = (ptrtonode)malloc(sizeof(struct node));
		nowtmp ->num = i;
		nowtmp->pre = lasttmp;
		nowtmp->next = NULL;
		lasttmp->next = nowtmp;
		lasttmp = nowtmp;
	}

	lasttmp->next = josee;
	josee->pre = lasttmp;
}

void deletejose(ptrtonode p)
{
	ptrtonode ppre = p->pre;
	ptrtonode pnext = p->next;

	printf("out of jose is :%6d\n",p->num);
	free(ppre->next);
	ppre->next = pnext;
	pnext->pre = ppre;
}

void main()
{
	ptrtonode jose;
	ptrtonode start,sartnext = NULL;
	int flag = 0;
	int nums;
	int N,M;
	int i,s = 0;
	time_t time_start = clock();

	jose = (ptrtonode)malloc(sizeof(struct node));
	jose->num = 0;
	jose->next = jose->pre =NULL;
	//printf("please enter the number N and M : ");
	//scanf("%d%d",&N,&M);
	N=10000;M=3;
	creatjose(N,M,jose);

	start = jose;
	for(nums = N;nums > 1;nums--)
	{
		while(flag != M)
		{
			flag++;
			start = start->next;
		}
		if (flag == M)
		{
			flag = 0;
			sartnext = start->next;
			deletejose(start);
			start = sartnext;
		}
	}

	if(nums == 1)
		printf("the last num is : %6d",start->num);
	putchar('\n');
	///精简的Josephus问题的算法，迅速求出最后胜利者

	for (i = 2; i <= N; i++)  
	{  
		s = (s + M+1) % i;  
	}  
	printf ("\nThe winner is %d\n", s+1); 

	time_t time_end = clock();
	double dur_time = (double)(time_end - time_start)/CLOCKS_PER_SEC *1000;
	printf("the time of program is :%f",dur_time);
}