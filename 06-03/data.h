#ifndef DATA_H
#define DATA_H

struct Data {
	char name[32];
	double sum;
	int frequency;
};

struct Data* DataCreate(char* name, int sum){
	struct Data* d = (struct Data*) malloc(sizeof(struct Data));
	strcpy(d->name, name);
	d->sum = sum;
	d->frequency = 1;
	return d;
}

#endif
