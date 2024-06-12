#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int n = 0,i;
	printf("Input: n = ");
    scanf("%d", &n);
    printf("Output: ");
    for(i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            printf("%d ",i);
        }
    }
    printf("%d",n);
	return 0;
}