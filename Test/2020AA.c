#include <stdio.h>
#include <stdlib.h>




int palindrome_arr(int num){
    int* arr;
    int len=0,tmp=num;
    while(tmp!=0){
        len++;
        tmp/=10;
    }
    arr = (int*)malloc(len*sizeof(int));
    tmp=num;
    for(int i=0;i<len;i++){
        arr[i]=tmp%10;
        tmp/=10;
    }
    for(int i=0;i<len/2;i++){
        if(arr[i]!=arr[len-i-1]){
            free(arr);
            return 0;
        }
    }
    return 1;
}
int palindrome(int num){
    int rev=0,tmp=num,len=0;
    while(num>0){
        rev = rev*10+num%10;
        num/=10;
        len++;
    }
    num=tmp;
    for(int i=0;i<len/2;i++){
        if(num%10!=rev%10){
            return 0;
        }
        num/=10;
        rev/=10;
    }
    return 1;
}

void rec_rev(long num,long* rev,int* len){
    if(num==0) return ;
    *rev=*rev*10+num%10;
    *len=*len+1;
    rec_rev(num/10,rev,len);
}
int countMinChanges(long num,long rev,int len){
    if(len==0) return 0;
    if(num%10==rev%10){
        return countMinChanges(num/10,rev/10,len-1);
    }
    return 1+countMinChanges(num/10,rev/10,len-1);
}
int rec_palindrome(long num){
    long rev=0;
    int len=0;
    rec_rev(num,&rev,&len);
    return countMinChanges(num,rev,len/2);
}


int unique(char s[]){
    int asc[256]={0};
    int count =0;
    while(*s!='\0'){
        if(asc[*s]==0){
            asc[*s]=1;
            count++;
        }
        s++;
    }
    return count;
}
int getLen(char* s[]){
    int len=0;
    for(;s[len];len++);
    return len;
}
void unique_sort(char* s[]){
    char* tmp;
    int len=getLen(s);
    for(int i=len-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(unique(s[j])>unique(s[j+1])){
                tmp=s[j];
                s[j]=s[j+1];
                s[j+1]=tmp;
            }
        }
    }
}


int almost(int a[],int n,int num){
    int mid,l=0,h=n-1;
    if(a[n-1]<num){
        return -1;
    }
    if(a[0]>num){
        return 0;
    }
    while(l<=h){
        mid = l+(h-l)/2;
        if(a[mid]>=num && a[mid-1]<num){
            return mid;
        }
        if(a[mid]>num){
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return -1;
}
int iter(int a[],int l,int h,int num){
    int mid =l+(h-l)/2;
    if(a[mid]>=num && a[mid-1]<num){
        return mid;
    }
    if(a[mid]>num){
        return iter(a,l,mid-1,num);
    }
    return iter(a,mid+1,h,num);
}
int rec_almost(int a[],int n,int num){
    if(a[n-1]<num) return -1;
    if(a[0]>num) return 0;
    return iter(a,0,n-1,num);
}
int main() {
    
    int num=131;
    printf("Is %d a palindrome? %d\n",num,palindrome_arr(num));
    num=132;
    printf("Is %d a palindrome? %d\n",num,palindrome_arr(num));
    num=12321;
    printf("Is %d a palindrome? %d\n",num,palindrome_arr(num));

    num=131;
    printf("Is %d a palindrome? %d\n",num,palindrome(num));
    num=132;
    printf("Is %d a palindrome? %d\n",num,palindrome(num));
    num=12321;
    printf("Is %d a palindrome? %d\n",num,palindrome(num));

    long num2 = 123,rev=0;
    int len=0;
    rec_rev(num2,&rev,&len);
    printf("Reverse of %ld is %ld\n",num2,rev);
    printf("Length of %ld is %d\n",num2,len);
    printf("Number of changes needed to make %ld a palindrome: %d\n",num2,rec_palindrome(num2));
    num2 = 12321;
    len=0;
    rev=0;
    rec_rev(num2,&rev,&len);
    printf("Reverse of %ld is %ld\n",num2,rev);
    printf("Length of %ld is %d\n",num2,len);
    printf("Number of changes needed to make %ld a palindrome: %d\n",num2,rec_palindrome(num2));
    
    char* s[] = {"hey","hello","world","hey","hello",NULL};
    printf("len=%d\n",getLen(s));
    printf("unique(\"hey\")=%d\n",unique("hey"));
    printf("unique(\"hello\")=%d\n",unique("hello"));
    unique_sort(s);


    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 0;
    printf("n = %d and almost = %d\n",n,almost(a,10,n));
    printf("n = %d and rec_almost = %d\n",n,rec_almost(a,10,n));
    n = 11;
    printf("n = %d and almost = %d\n",n,almost(a,10,n));
    printf("n = %d and rec_almost = %d\n",n,rec_almost(a,10,n));
    n = 5;
    printf("n = %d and almost = %d\n",n,almost(a,10,n));
    printf("n = %d and rec_almost = %d\n",n,rec_almost(a,10,n));
    n = 1;
    printf("n = %d and almost = %d\n",n,almost(a,10,n));
    printf("n = %d and rec_almost = %d\n",n,rec_almost(a,10,n));


    return 0;
}