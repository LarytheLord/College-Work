#include <stdio.h>
#include <conio.h>
void main()
{
	char a;
	clrscr();
	printf("Enter your character=");
	scanf("%c",&a);
	if(a>='a' && a<='z')
	{
		printf("The character is lowercase");
	}
	else
	{
		printf("The character is upper case");
	}
	getch();
}