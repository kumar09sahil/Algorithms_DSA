/* C program to implement the “Maximum Subarray Problem” using pointer.
1. Find the maximum subarray using naive approach
2. Find the maximum subarray using divide-and-conquer approach
3. Exit from the program
*/
#include <stdio.h>
#include <limits.h>

int *maxsubarraynaive(int *a, int n, int *maxSum, int *maxStart, int *maxEnd)
{
    *maxSum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int Sum = 0;
        for (int j = i; j <= n; j++)
        {
            Sum += a[j];
            if (Sum > *maxSum)
            {
                *maxSum = Sum;
                *maxStart = i;
                *maxEnd = j;
            }
        }
    }
    return a + *maxStart;
}

void maxcrossingsum(int *a, int low, int mid, int high, int *crosslow, int *crosshigh, int *crosssum)
{
    int leftSum = INT_MIN;
    int sum = 0;
    *crosslow = mid;

    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            *crosslow = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    *crosshigh = mid + 1;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if (sum > rightSum) 
        { 
            rightSum = sum;
            *crosshigh = i;
        }
    }

    *crosssum = leftSum + rightSum;
}

int maxsubarraysumdivcon(int *a, int low, int high, int *maxStart, int *maxEnd)
{
    if (low == high)
    {
        *maxStart = low;
        *maxEnd = high;
        return a[low];
    }
}


int main()
{
    int n, k, x, i, a[20], maxsum;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    do
    {
        printf("1. Find the maximum subarray using naive approach\n");
        printf("2. Find the maximum subarray using divide-and-conquer approach\n");
        printf("3. Exit from the program\n");
        printf("Enter your option: ");
        scanf("%d", &x);
        int maxStart, maxEnd;
        switch (x)
        {

        case 1:

            maxsubarraynaive(a, n, &maxsum, &maxStart, &maxEnd);
            printf("The maximum sum is: %d\n", maxsum);
            printf("The maximum subarray is: ");
            for (k = maxStart; k <= maxEnd; k++)
            {
                printf("A[%d] = %d ", k, a[k]);
            }
            printf("\n");
            break;
        case 2:
            maxsum = maxsubarraysumdivcon(a, 1, n, &maxStart, &maxEnd);
            printf("The maximum sum is: %d\n", maxsum);
            printf("The maximum subarray is: ");
            for (k = maxStart; k <= maxEnd; k++)
            {
                printf("A[%d] = %d ", k, a[k]);
            }
            printf("\n");
            break;
        }
    } while (x <= 2);

    return 0;
}

