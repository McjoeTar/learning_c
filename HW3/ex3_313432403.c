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
	int temp_counter, counter=1;
    int i, j, temp_sum, sum = arr[0] - '0';
    for (i = 0; arr[i] != '\0'; i+=2){
        temp_sum = 0;
        temp_counter = 0;
        for (j=0; arr[j] != '\0'; j+=2){
            temp_sum += arr[j] - '0';
            temp_counter++;
            if (temp_sum > sum){
                sum = temp_sum;
                counter = temp_counter;
            }
        }
    }
    return counter;
}

int q_2(char arr[], int k)
{
	// HERE: define the function accordingly
}

int q_3(char arr[])
{
	// HERE: define the function accordingly
}


int q_4(char arr[])
{
	// HERE: define the function accordingly
}