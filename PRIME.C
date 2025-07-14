#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b=1,c;
	int i;
	clrscr();
	printf("Enter your number:");
	scanf("%d",&a);
	c = a/2;
	for(i=2;i<=c;i++)
	{
	     b = a%i;
	     if(b==0)
		break;
	}
	if(b==0)
		printf("number is not prime");
	     else
		printf("number is prime");

	getch();
}