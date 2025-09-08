#include<stdio.h>
#include<conio.h>

void main() {
    int a[10];
    int i, j, find, f = 0;

    clrscr();

    printf("Enter 10 elements for the array:\n");
    for(i = 1; i <= 10; i++) {
	printf("Element %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nEnter the element you want to search/find: ");
    scanf("%d", &find);

    for(j = 0; j < 10; j++) {
        if(a[j] == find) {
            printf("The %d was present at position %d of the array.", find, j + 1);
            f = 1;
            break;
        }
    }

    if(f == 0) {
        printf("\nThe element you wanted to find is not in the array.");
    }

    getch();
}