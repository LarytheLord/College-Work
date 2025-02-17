#include<stdio.h>
#include<conio.h>
void main()
{
	float a;
	clrscr();
	printf("enter your number=");
	scanf("%f",&a);
	if(a/2==0)
	{
		printf("the given number is even %f",a);
	}
	else
	{
		printf("the given number is odd %f",a);
	}
	getch();
}