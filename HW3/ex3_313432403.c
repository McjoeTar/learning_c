#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>

#define MAX_SIZE 30

int q_1(char arr[]);

int q_2(char arr[], int k);

int q_3(char arr[]);

int q_4(char arr[]);


int main()
{
	int q_num = 0, n = 0, res = 0, k = 0;
	char arr[MAX_SIZE];

	printf("Which question would you like to check?: ");
	scanf("%d", &q_num);
	printf("Please enter the input array: ");
	scanf("%s", arr);
	switch (q_num)
	{
	case 1:
		res = q_1(arr);
		printf("Result = %d", res);
		break;
	case 2:
		printf("Please enter k: ");
		scanf("%d", &k);
		res = q_2(arr, k);
		printf("Result = %d", res);
		break;
	case 3:
		res = q_3(arr);
		printf("Result = %d", res);
		break;
	case 4:
		res = q_4(arr);
		printf("Result = %d", res);
		break;
	default:
		printf("%d is an invalid input", q_num);
	}
	return 0;
}

int q_1(char arr[])
{
	int num_array[MAX_SIZE];
    int n = 0, current_num = 0, sign = 1;
    const char *p = arr;

    while(*p != '\0'){
        if(*p == '-'){
            sign = -1;
        }
        else if(*p >= '0' && *p <= '9'){
            current_num = current_num * 10 + (*p - '0');
        }
        else if(*p == ','){
            num_array[n++] = sign * current_num;
            current_num = 0;
            sign = 1;
        }
        p++;
    }

    num_array[n++] = sign * current_num;

    int max_sum = num_array[0], current_sum = num_array[0];
    int i;
    int max_count = 1, current_count = 1;
    for(i = 1; i < n; i++){
        if(num_array[i] > current_sum + num_array[i]){
            current_sum = num_array[i];
            current_count = 1;
        }
        else{
            current_sum += num_array[i];
            current_count++;
        }

        if(current_sum > max_sum){
            max_sum = current_sum;
            max_count = current_count;
        }
    }
    return max_count;
}

int q_2(char arr[], int k)
{
	// HERE: define the function accordingly
}

int q_3(char arr[])
{
	int num_array[MAX_SIZE];
    int len = 0;
    int n = 0, current_num = 0, sign = 1;
    const char *p = arr;
    
    while(*p != '\0'){
        if(*p == '-'){
            sign = -1;
        }
        else if(*p >= '0' && *p <= '9'){
            current_num = current_num * 10 + (*p - '0');
        }
        else if(*p == ','){
            num_array[n++] = sign * current_num;
            current_num = 0;
            sign = 1;
        }
        p++;
        len++;
    }

    num_array[n++] = sign * current_num;
    int nums[len];
    int i;
    for (i = 0; i < len; i++){
        nums[i] = 0;
    }

    for(i = 0; i < len; i++){
        if(nums[num_array[i]] == 1){
            return 1;
        }
        nums[num_array[i]] = 1;
    }
    return -1;
}


int q_4(char arr[])
{
    int num_array[MAX_SIZE];
    int n = 0, current_num = 0, sign = 1;
    const char *p = arr;

    while(*p != '\0'){
        if(*p == '-'){
            sign = -1;
        }
        else if(*p >= '0' && *p <= '9'){
            current_num = current_num * 10 + (*p - '0');
        }
        else if(*p == ','){
            num_array[n++] = sign * current_num;
            current_num = 0;
            sign = 1;
        }
        p++;
    }
    
    num_array[n++] = sign * current_num;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int total_water = 0;

    while (left<=right){
        if(num_array[left] < num_array[right]){
            if(num_array[left] >= left_max){
                left_max = num_array[left];
            }
            else{
                total_water += left_max - num_array[left];
            }
            left++;
        } else {
            if(num_array[right] >= right_max){
                right_max = num_array[right];
            }
            else{
                total_water += right_max - num_array[right];
            }
            right--;
        }
    }
    return total_water;
}