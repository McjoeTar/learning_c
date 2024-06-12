#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int n=0;
	printf("Enter a number to reverse: ");
    scanf("%d", &n);
    printf("Reverse of number is: ");
    while(n!=0)
    {
        printf("%d",n%10);
        n=n/10;
    }

	return 0;
}