#include<stdio.h>
#include<conio.h>
#define max 4
int top,s[10],val;
int top = -1;
void puch();
void show();
void main()
{
	int i;
	clrscr();
	for(i=0;i<max;i++)
	{
	puch();
	}
	show();
	getch();
}

void puch()
{
		int i,val;
		if(top==max-1)
		{
			printf("stak overflowed");
		}
		else
		{
			top++;
			printf("\nenter the value ");
			scanf("%d ",&val);
			s[top]=val;
		}
	}


void show()
{
	int i;
	if(top==-1)
	{
		printf("stack empty");
	}
	else
	{
	for(i=0;i<max;i++)
	{
		printf("%d ",s[i]);

	}
}
}