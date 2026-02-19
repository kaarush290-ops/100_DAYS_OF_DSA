#include <stdio.h>

int main()
{
    char s[] = {'h','e','l','l','o'};
    int n = 5;

    int i = 0;
    int j = n - 1;

    while(i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }

    for(int k = 0; k < n; k++)
    {
        printf("%c ", s[k]);
    }

    return 0;
}
