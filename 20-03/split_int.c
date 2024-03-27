// How to use:
// $ make
// $./split_int.out

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int verifyListInt(const char *s){
    int searching_for_number_begining = 1;
    int size = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(searching_for_number_begining){
            if(isdigit(s[i])){
                size++;
                searching_for_number_begining = 0;
            }
        }else{
            if(!isdigit(s[i])){
                searching_for_number_begining = 1;
            }
        }
    }
    return size;
}

int* splitInt(const char *s, int *size){
    *size = verifyListInt(s);
    if(size == 0) return NULL;
    int* list_int = (int*) malloc((*size)*sizeof(int));
    int current_number_idx = 0;
    int searching_for_number_begining = 1;
    for(int i = 0; s[i] != '\0'; i++){
        if(searching_for_number_begining){
            if(isdigit(s[i])){
                searching_for_number_begining = 0;
                list_int[current_number_idx++] = atoi(s + i);
            }
        }else{
            if(!isdigit(s[i])){
                searching_for_number_begining = 1;
            }
        }
    }
    return list_int;
}

int main(){
    char ent[100];
    scanf("%[^\n]s", ent);
    int size;
    int *ent_int = splitInt(ent, &size);
    if(ent_int == NULL){
        printf("String inválida\n");
        return 1;
    }
    printf("Size: %d\n", size);
    for(int i = 0; i < size; i++){
        printf("%d ", ent_int[i]);
    }
    printf("\n");
    return 0;
}
