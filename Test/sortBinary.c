#include <stdio.h>

int iterate(int a[],int l,int h,int n,int num){
    int mid = l+(h-l)/2;
    if(a[n-1]<num){
        return -1;
    }
    if(a[0]>num){
        return 0;
    }
    if(a[mid]>=num && a[mid-1]<num){
        return mid;
    }
    if(a[mid]>num){
        h= mid-1;
        return iterate(a,l,h,n,num);
    }
    l=mid+1;
    return iterate(a,l,h,n,num);
}

int rec_almost(int a[],int n,int num){
    return iterate(a,0,n-1,n,num);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 0;
    printf("n = %d and rec_almost = %d\n",n,rec_almost(a,10,n));
    n = 11;
    printf("n = %d and rec_almost = %d\n",n,rec_almost(a,10,n));
    n = 5;
    printf("n = %d and rec_almost = %d\n",n,rec_almost(a,10,n));
    n = 1;
    printf("n = %d and rec_almost = %d\n",n,rec_almost(a,10,n));

    return 0;
}