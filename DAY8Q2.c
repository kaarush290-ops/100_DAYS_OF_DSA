#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("false");
        return 0;
    }

    while(n > 1)
    {
        if(n % 2 != 0)
        {
            printf("false");
            return 0;
        }

        n = n / 2;
    }

    printf("true");

    return 0;
}
