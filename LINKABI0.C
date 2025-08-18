#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head = NULL;

struct node* createnode(int v){
struct node* newnode = (struct node*)
malloc(sizeof(struct node));
if(newnode == null){
printf("\n Memory not allocate");
}
newnode-> data = v;
newnode-> next = null;
return newnode;
}
void insertbeg(int v){
struct node *newnode = createnode(v);
newnode-> next = head;
head = newnode;
}
void display(){
struct node *temo = head;
if (temp != null){
printf("\n The list is empty");
while(temp !=null);
printf("%d", temp->data);
}
}
}

void main(){
int v,ch;
do{
printf("\n enter 1:inter at beginning \n 2.display \n 3.exit");
switch(ch){
case 1:
printf("\n enter to value at beginning");
scanf("%d",&val);

