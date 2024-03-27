#ifndef VECTOR_H
#define VECTOR_H
#include "data.h"

struct Vector {
	struct Data* data;
	int size;
	int max_size;
};

void VectorAppend(struct Vector* v, struct Data* d){
	if(v->size == v->max_size){
		v->max_size = v->max_size?v->max_size*2:1;
		v->data = (struct Data*) realloc(v->data, v->max_size*sizeof(struct Data));
	}
	memcpy(v->data+v->size, d, sizeof(struct Data));
	v->size++;
}

struct Vector* VectorCreate(){
	struct Vector* v = (struct Vector*) malloc(sizeof(struct Vector));
	v->data = NULL; 
	v->size = 0;
	v->max_size = 0;
	return v;	
}

int VectorFindData(struct Vector* v,  char* name){
	for(int i = 0; i < v->size; i++){
		if(!strcmp(v->data[i].name, name)){
			return i;
		}
	}
	return -1;
}

#endif
