// Implement a function "char* strrchr(char* str, char c)" equivalent to the strrchr function from the standard C library
// How to use:
// $ make 3.exe
// $ ./3.out

#include <stdio.h>
#include <stdlib.h>

char* strrchr2(char* str, char c);

int main(){
    char* strs[] = {"abcd", "abcda", "bcd"};
    for(int i = 0; i < sizeof(strs)/sizeof(char*); i++){
        char* ptr = strrchr2(strs[i],'a');
        if(ptr){
            printf("'%s' - the last occurrence of 'a' is at index %ld\n", strs[i], ptr - strs[i]);
        }else{
            printf("'%s' - Does not contain the character 'a'\n", strs[i]);
        }
    }
}

char* strrchr2(char* str, char c){
    char* ptr = NULL;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == c) ptr = str + i;
    }
    return ptr;
}
