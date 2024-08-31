#include <stdio.h>
#include <stdlib.h>


typedef struct num {
    int num1;
} Num; 

int createNum(Num* num,int number){

    num[number].num1 = number;
    return 0;
}
int main() {

    Num* nums = malloc(sizeof(Num) * 5);
    for (int i = 0; i < 5; i++)
    {
        createNum(nums,i);
    }

    printf("nums[0].num1 = %d\n",nums[0].num1);
    printf("nums[1].num1 = %d\n",nums[1].num1);
    printf("nums[2].num1 = %d\n",nums[2].num1);
    printf("nums[3].num1 = %d\n",nums[3].num1);
    printf("nums[4].num1 = %d\n",nums[4].num1);
    printf("(*nums).num1 = %d\n",(*nums).num1);
}