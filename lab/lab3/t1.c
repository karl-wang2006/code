#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void spiral_matrix(int n)
{
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = (int*)malloc(n * sizeof(int));
    }
    int num = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    while (num <= n * n)
    {
        for (int i = left; i <= right; i++)
        {
            arr[top][i] = num;
            num++;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            arr[i][right] = num;
            num++;
        }
        right--;

        if (left <= right)
        {
            for (int i = right; i >= left; i--)
            {
                arr[bottom][i] = num;
                num++;
            }
            bottom--;
        }

        if (top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
            {
                arr[i][left] = num;
                num++;
            }
            left++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int n;
    scanf("%d", &n);
    spiral_matrix(n);
    return 0;
}