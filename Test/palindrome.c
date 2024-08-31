#include <stdio.h>


int countSwitchesToPalindrome(long num) {
    long rev=0,tmp=num;
    int count=0,len=0;
    while(num>0){
        rev = rev*10+num%10;
        num/=10;
        len++;
    }
    num=tmp;
    for(int i=0;i<len/2;i++){
        if(num%10!=rev%10){
            count++;
        }
        num/=10;
        rev/=10;
    }
    return count;
}

int main() {
    long num;
    printf("Enter a number: ");
    scanf("%ld", &num);

    int switches = countSwitchesToPalindrome(num);
    printf("Number of switches needed: %d\n", switches);

    return 0;
}