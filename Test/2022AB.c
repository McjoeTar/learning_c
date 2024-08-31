#include <stdio.h>

long zerofy(long num){
    long new=num,mul=10;
    while(num/10!=0){
        new=10*(new-new%mul)+new%mul;
        mul*=100;
        num/=10;
    }
    return new;
}

long rec_zerofy(long num){
    if(num/10==0){
        return num;
    }
    return num%10 + rec_zerofy(num/10)*100;
}

int is_prime(unsigned int num){
    if(num<=2) return 1;
    for(int i=2; i<=num/2;i++){
        if(num%i==0) return 0;
    }
    return 1;
}
int is_square_prime(unsigned int num){
    if(num==1) return 1;
    int i=2;
    for(;i*i<num;i++);
    if(i*i==num) return is_prime(i);
    return 0;
}

void all_square_primes(unsigned int num){
    for(int i=1;i<num/2;i++){
        if(num%i==0 && is_square_prime(i) && is_square_prime(num/i)) printf("%d, %d\n",i,num/i);
    }
}

int my_strlen(char s[]){
    int len=0;
    while(*s!='\0'){
        len++;
        s++;
    }
    return len;
}
void reverse(char s[]){ //"hey\0 0123"
    char tmp;
    int len = my_strlen(s); // 3
    for(int i = len-1; i>0; i--){ //i=2
        printf("s[i]=%c\n",s[i]);
        printf("s[len-1-i]=%c\n",s[len-i-1]);
        printf("i=%d\n",i);
        tmp = s[i]; // "y"
        s[i] = s[len-i-1]; // len-i-1 = 3-2-1 = 0 "h"
        s[len-1-i] = tmp; // "y"
    } // "yeh\0"
}
int main() {
    
    long num = 123456789;
    printf("zerofy(%ld) = %ld\n",num,zerofy(num));
    printf("rec_zerofy(%ld) = %ld\n",num,rec_zerofy(num));
    
    unsigned int n = 49;
    printf("is_square_prime(%d) = %d\n",n,is_square_prime(n));
    n = 25;
    printf("is_square_prime(%d) = %d\n",n,is_square_prime(n));
    n = 1;
    printf("is_square_prime(%d) = %d\n",n,is_square_prime(n));
    n = 2;
    printf("is_square_prime(%d) = %d\n",n,is_square_prime(n));
    n = 16;
    printf("is_square_prime(%d) = %d\n",n,is_square_prime(n));
    all_square_primes(36);

    char s[] = "Hey";
    reverse(s);
    printf("%s",s);
    return 0;
}