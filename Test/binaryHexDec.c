#include <stdio.h>
#define BITS 32


void num2Bits(int num, char binary[]){

    int mol,i=BITS-1;
    binary[BITS]='\0';  
    for(;i>=0;i--){
        mol=num%2;
        num/=2;
        printf("i=%d, mol=%d, num=%d\n",i,mol,num);
        binary[i]= (mol==1)?'1':'0';
    }
}

int main() {
    int nums[26]={0};
    char p[BITS+1];
    int num = 9;
    num2Bits(num,p);
    printf("%s\n",p);

    return 0;
}