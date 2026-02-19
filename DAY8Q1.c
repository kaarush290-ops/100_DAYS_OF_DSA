#include <stdio.h>

int power(int a, int b)
{
    if(b == 0)
        return 1;   // Base case

    return a * power(a, b - 1);  // Simple recursion
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int result = power(a, b);

    printf("%d", result);

    return 0;
}
