#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,c,i,n;
	clrscr();
	printf("enter number ");
	scanf("%d",&n);
	printf("enter first number:");
	scanf("%d",&a);
	printf("\nenter second number:");
	scanf("%d",&b);
	for(i=0;i<n;i++)
	{
	       c=a+b;
	       a=b;
	       b=c;
	       printf("\n%d",b);
	}

	getch();
}
