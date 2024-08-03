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
    printf("%s 0x%x",QUESTION1_OUTPUT_MESSAGE_HEXADECIMAL, dec_input);

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
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    return num+1;
    
}

int isPalindrome(int num)
{
	//Question 4
}

int swap_even_odd(int num)
{
	//Question 5
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
                break;
            case 5:
                break;
        }
    } while (question > 5 || question <= 0);
    
    
    
	return 0;
}