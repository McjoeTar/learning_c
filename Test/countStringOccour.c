#include <stdio.h>

int str_comp(char* str1,char* str2){
    int max1=0,max2=0;
    int occur1[26]={0},occur2[26]={0};
    while (*str1 != '\0') {  // Correct null terminator check
    if (*str1 >= 'a' && *str1 <= 'z') {
        occur1[*str1 - 'a']++;  // Correct indexing for lowercase letters
    } else if (*str1 >= 'A' && *str1 <= 'Z') {
        occur1[*str1 - 'A']++;  // Correct indexing for uppercase letters
    }
    str1++;  // Move to the next character in the string

    }
    while (*str2 != '\0') {  // Correct null terminator check
        if (*str2 >= 'a' && *str2 <= 'z') {
            occur2[*str2 - 'a']++;  // Correct indexing for lowercase letters
        } else if (*str2 >= 'A' && *str2 <= 'Z') {
            occur2[*str2 - 'A']++;  // Correct indexing for uppercase letters
        }
        str2++;
    }
    for(int i=0;i<26;i++){
        max1=(occur1[i]>max1)?occur1[i]:max1;
        max2=(occur2[i]>max2)?occur2[i]:max2;
    }
    if(max1>max2){
        return 1;
    }
    else if(max1<max2){
        return -1;
    }
    return 0;
}


void k_cyc(char* s, int c){
    for(int i =0;s[i]!='\0';i++){
        printf("%d\n",s[i]);
        printf("%d\n",s[i]+(c%26));
        printf("%d\n",s[i]+(c%26)>'z');
        s[i]=(s[i]+(c%26)>'z')?s[i]+(c%26)-26:(s[i]+(c%26)<'a')?s[i]+(c%26)+26:s[i]+(c%26);
        printf("%c\n",s[i]);
    }
}

int unique(char s[]){
    int counter=0;
    int asciiArr[256]={0};
    for(int i=0;s[i];i++){
        if(!asciiArr[s[i]]){
            counter++;
            asciiArr[s[i]]++;
        }
    }
    return counter;
}
void unique_sort(char* s[]){
    char* tmp;
    int len=0;
    for(int i=0;s[i];i++){
        printf("%s\n",s[i]);
        len++;
        printf("%d\n",len);
    }
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
int main() {
    
    char s1[] = "deep";
    char s2[] = "shlomo";
    printf("%d\n",unique(s1));
    printf("%d\n",unique(s2));
    char* s3[] = {"shlomo","deep",NULL};
    printf("%s, ",s3[0]);
    printf("%s\n",s3[1]);
    unique_sort(s3);
    printf("%s, ",s3[0]);
    printf("%s\n",s3[1]);
    return 0;
}