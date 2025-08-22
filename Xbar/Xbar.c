#include <stdio.h>
#include <math.h>

int main() {
    int X[5], Y[5], n, i;
    int sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;

    printf("Enter number of elements (max 5): ");
    scanf("%d", &n);

    printf("Enter elements of X:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &X[i]);
        sumX += X[i];
        sumX2 += X[i] * X[i];
    }

    printf("Enter elements of Y:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &Y[i]);
        sumY += Y[i];
        sumY2 += Y[i] * Y[i];
        sumXY += X[i] * Y[i];
    }

    double numerator = n * sumXY - sumX * sumY;
    double denominator = sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));

    if (denominator == 0)
        printf("Correlation undefined (division by zero).\n");
    else
        printf("rXY = %.4f\n", numerator / denominator);

    return 0;
}
