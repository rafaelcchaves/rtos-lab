#ifndef CITYDATA
#define CITYDATA 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define index_state  3
#define index_city   4
#define index_region  5
#define index_population  6
#define index_size  7
#define CITY_NUMBER 5570

struct DataCity {
	char state[16];  
	char city[32];
      	char region[32];
	int population;
	char size[32];
};

struct DataCity* getDataCityFromLine(char* line){
	struct DataCity* datacity = (struct DataCity*) malloc(sizeof(struct DataCity));
	char* ptr = strtok(line, ";");
	int i = 0;
	while(ptr){
		
		if(i == index_state){
			strcpy(datacity -> state, ptr);
		}
		if(i == index_city){
			strcpy(datacity -> city, ptr);
		}
		if(i == index_region){
			strcpy(datacity -> region, ptr);
		}
		if(i == index_population){
			datacity -> population = atoi(ptr);
		}
		if(i == index_size){
			strcpy(datacity -> size, ptr);
		}
		ptr = strtok(NULL, ";");
		i++;
	}
	return  datacity;
}

void printData(struct DataCity* datacity){
	printf("State: %s\n", datacity->state);
	printf("City: %s\n", datacity->city);
	printf("Region: %s\n", datacity->region);
	printf("Population: %d\n", datacity->population);
	printf("Size: %s\n", datacity->size);
}

struct DataCity** readDataFromCSV(){
	FILE* file = fopen("dados_municipios.csv","r");
	char line[1024] = {0};	
	struct DataCity** cities = (struct DataCity**) calloc(CITY_NUMBER, sizeof(struct DataCity*));
	for(int i = 0; i <= CITY_NUMBER; i++){
		fgets(line, sizeof(line), file);
		if(i){
			cities[i - 1] = getDataCityFromLine(line);
		}
	}
	fclose(file);
	return cities;
}
	
#endif 
