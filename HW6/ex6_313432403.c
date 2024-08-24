#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


#define ENTERING_QUESTION "Please choose a question by entering 1-5 (enter 0 to exit):" 
#define DYNAMIC_ALLOCATION_FAILED "dynamic allocation failed"

//Q1//
#define MAX_SIZE_INPUT 31
#define QUESTION1_INPUT_MESSAGE "Please enter binary number input:"
#define QUESTION1_OUTPUT_MESSAGE_DECIMAL "to decimal is:"
#define QUESTION1_OUTPUT_MESSAGE_HEXADECIMAL "to hexadecimal is:"
#define QUESTION1_ERROR_MESSAGE "invalid input, please try again."

//Q2//
#define QUESTION2_INPUT1_MESSAGE "Please enter num1 value:"
#define QUESTION2_INPUT2_MESSAGE "Please enter num2 value:"
#define QUESTION2_OUTPUT_MESSAGE "After swapping:"

//Q3//
#define QUESTION3_INPUT1_MESSAGE "Please enter an integer:"
#define QUESTION3_OUTPUT_MESSAGE "Output:"

//Q4//
#define QUESTION4_INPUT1_MESSAGE "Please enter an integer:"
#define QUESTION4_OUTPUT1_MESSAGE "in binary is a palindrome"
#define QUESTION4_OUTPUT0_MESSAGE "in binary is not a palindrome."

//Q5//
#define QUESTION5_INPUT1_MESSAGE "Please enter an integer:"
#define QUESTION5_OUTPUT1_MESSAGE "Output of Q5:"


void bin2hexanddec(char *bin_str)
{
	int dec_input = 0;
    int i;

    for(i = 0; i < MAX_SIZE_INPUT; i++)
    {
        if(bin_str[i] == '\0')
        {
            break;
        }
        if(bin_str[i] != '0' && bin_str[i] != '1')
        {
            *bin_str = '\0';
            printf("%s\n", QUESTION1_ERROR_MESSAGE);
            return;
        }
        
        dec_input = dec_input * 2 + (bin_str[i] - '0');
    }

    printf("%s %d\n",QUESTION1_OUTPUT_MESSAGE_DECIMAL, dec_input);
    printf("%s 0x%X\n",QUESTION1_OUTPUT_MESSAGE_HEXADECIMAL, dec_input);

}

void swap(int* xp, int* yp)
{
	*xp ^= *yp;
    *yp ^= *xp;
    *xp ^= *yp;
    printf("%s num1=%d, num2=%d\n", QUESTION2_OUTPUT_MESSAGE, *xp, *yp);

}

int minPowerOf2(int num)
{
	if(num == 0)
    {
        return 1;
    }
    num = num - 1;
    int i=1;
    for (i = 1; i < sizeof(int) * 8; i = i << 1)
    {   
        num = num | num >> i;
        //printf("num = %d or hex_num = %X and i = %d \n", num,num,i);
    }
    // num |= num >> 1;
    // num |= num >> 2;
    // num |= num >> 4;
    // num |= num >> 8;
    // num |= num >> 16;
    return num+1;
    
}

int isPalindrome(int num)
{
    int bin_len = sizeof(int) * 8;
    int msb =0;
    for(int i = bin_len -1 ; i >= 0; i--)
    {
        if(num & (1 << i))
        {
            msb=i;
            break;
        }
    }
    for (int i = 0; i < msb; i++)
    {
        if((num & (1 << i)) != ((num & (1 << (msb - i))) >> (msb - i)))
        {
            return 0;
        }
    }
    return 1;
}

int swap_even_odd(int num)
{
	int even_mask = 0xAAAAAAAA;
    int odd_mask = 0x55555555;
    int even_bits = num & even_mask;
    int odd_bits = num & odd_mask;
    even_bits >>= 1;
    odd_bits <<= 1;
    return even_bits | odd_bits;
}


int main()
{
    int question;
    char input[MAX_SIZE_INPUT];
    int num1, num2;
    do
    {
        printf("%s\n", ENTERING_QUESTION);
        scanf("%d", &question);
        switch(question)
        {
            case 0:
                return 0;
            case 1:
                do
                {
                    printf("%s\n", QUESTION1_INPUT_MESSAGE);
                    scanf("%s",input);
                    bin2hexanddec(input);
                } while (*input == '\0');
                break;
            case 2:
                
                printf("%s\n", QUESTION2_INPUT1_MESSAGE);
                scanf("%d", &num1);
                printf("%s\n", QUESTION2_INPUT2_MESSAGE);
                scanf("%d", &num2);
                swap(&num1, &num2);
                break;
            case 3:
                printf("%s\n", QUESTION3_INPUT1_MESSAGE);
                scanf("%d", &num1);
                printf("%s %d\n", QUESTION3_OUTPUT_MESSAGE, minPowerOf2(num1));
                break;
            case 4:
                printf("%s\n", QUESTION4_INPUT1_MESSAGE);
                scanf("%d", &num1);
                if(isPalindrome(num1))
                {
                    printf("%d %s\n",num1, QUESTION4_OUTPUT1_MESSAGE);
                }
                else
                {
                    printf("%d %s\n",num1, QUESTION4_OUTPUT0_MESSAGE);
                }
                break;
            case 5:
                printf("%s\n", QUESTION5_INPUT1_MESSAGE);
                scanf("%d", &num1);
                printf("%s %d\n", QUESTION5_OUTPUT1_MESSAGE, swap_even_odd(num1));
                break;
        }
    } while (question != 0);
    
    
    
	return 0;
}