#include<stdio.h>
#include<conio.h>
void main(){
char c;
clrscr();
printf("Enter your special character");
if(scanf("%c",&c))
{ printf("character is string");
 if(c>='a' & c<='z'){
 printf("character is lower case");
 }
 else if(c>='A' & c<='Z')
{ printf("character is upper case");
}
 else if(c>=0)
 { printf("characte is +ve number");
 }
}
getch();
}
