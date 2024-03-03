// Implement a function "double atof2(char* number)" equivalent to the atof function from the standard C library
// How to use:
// $ make 2.exe
// $ ./2.out x qt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double atof2(char* number);

int main(){
    char* numbers[] = {"1.0", "1.10000000001", "1.21", "1.321", "1.4321", "21.4321", "321.4321", "4321.4321", "-1.0", "0"};
    for(int i = 0; i < sizeof(numbers)/sizeof(char*); i++){
       printf("%l;\n", atof2(numbers[i])); 
    }
}

double atof2(char* number){
    char* dot_ptr = strchr(number, '.');
    double decimal_part = 0, integer_part = atoll(number);
    if(dot_ptr){
        decimal_part = atoll(dot_ptr + 1);
        while(decimal_part >= 1){
            decimal_part /= 10;
        }
    }
    return integer_part + decimal_part;
}

