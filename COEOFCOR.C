#include <stdio.h>
#include <math.h>

int main() {
    int x[5], y[5], n, i;
    int sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, sumy2 = 0;
    clrscr();
    printf("Enter number of elements (max 5): ");
    scanf("%d", &n);

    printf("Enter elements of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        sumx += x[i];
        sumx2 += x[i] * x[i];
    }

    printf("Enter elements of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &y[i]);
        sumy += y[i];
        sumy2 += y[i] * y[i];
        sumxy += x[i] * y[i];
    }

    double numerator = n * sumxy - sumx * sumy;
    double denominator = sqrt((n * sumx2 - sumx * sumx) * (n * sumy2 - sumy * sumy));

    if (denominator == 0)
        printf("Correlation undefined (division by zero).\n");
    else
        printf("rxy = %.4f\n", numerator / denominator);
    getch();
    return 0;
}
