#include <stdio.h>
#include <math.h>


/////////////////////////////////// Question 1
double dist_sqrd(double a,double b){
    return a*a+b*b;
}
void cord_sort(double a[],double b[],int len){
    double tmpA,tmpB;
    for(int i=len-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(dist_sqrd(a[j],b[j])>dist_sqrd(a[j+1],b[j+1])){
                tmpA=a[j];
                tmpB=b[j];
                a[j]=a[j+1];
                b[j]=b[j+1];
                a[j+1]=tmpA;
                b[j+1]=tmpB;
            }
        }
    }
}
void print_data(double a[],double b[],int len){
    int totDist=0;
    double Len = (double)len;
    cord_sort(a,b,len);
    for(int i=0;i<len;i++){
        totDist+=sqrt(dist_sqrd(a[i],b[i]));
    }
    printf("median: %f\n",(len%2==0)?sqrt(dist_sqrd(a[(len+1)/2],b[(len+1)/2])):sqrt(dist_sqrd((a[len/2]+a[(len+1)/2])/2,(b[len/2]+b[(len+1)/2])/2)));
    printf("average: %f\n",totDist/Len);
}

/////////////////////////////////// Question 2
int three_sum(int a[],int len,int num){
    if(len==0) return 0;
    if(len==1) return a[0] == num;
    if(len==2) return a[0]+a[1] == num;
    for(int i=0;i<len-2;i++){
        for(int j=i+1;j<len-1;j++){
            for(int k=j+1;k<len;k++){
                if(a[i]+a[j]+a[k] == num) return 1;
            }
        }
    }
    return 0;
}


int rec_sum(int a[],int len,int num){
    if(!len) return 0;
    if(a[0]==num) return 1;
    if(a[0]>num) return rec_sum(a+1,len-1,num);
    return rec_sum(a+1,len-1,num-a[0]) || rec_sum(a+1,len-1,num);
}
int main() {
    /////////////////////////////////// Question 1
    printf("question 1\n");
    double a[] = {1.0, 2.0, 3.0, 5.0, 4.0};
    double b[] = {1.0, 2.0, 3.0, 5.0, 4.0};
    int len = 5;

    cord_sort(a, b, len);

    printf("Sorted coordinates:\n");
    for (int i = 0; i < len; i++) {
        printf("(%lf, %lf)\n", a[i], b[i]);
    }
    print_data(a,b,len);

    /////////////////////////////////// Question 2
    printf("question 2\n");

    int arr[] = {1, 2, 3, 4, 5};
    int n = 9;
    printf("three_sum(arr, 5, 9) = %d\n", three_sum(arr, 5, n));
    n=10;
    printf("three_sum(arr, 5, 10) = %d\n", three_sum(arr, 5, n));
    int newarr[] = {1};
    n=1;
    printf("three_sum(newarr, 5, 1) = %d\n", three_sum(newarr, 1, n));

    int arr2[] = {1, 2, 3, 4, 5};
    printf("rec_sum(arr2, 5, 9) = %d\n", rec_sum(arr2, 5, 9));
    printf("rec_sum(arr2, 5, 10) = %d\n", rec_sum(arr2, 5, 10));
    printf("rec_sum(arr2, 5, 1) = %d\n", rec_sum(arr2, 5, 1));
    printf("rec_sum(arr2, 5, 15) = %d\n", rec_sum(arr2, 5, 16));
    return 0;
}