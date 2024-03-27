#include "city_data.h"
#include "vector.h"
#include "data.h"

int main(){
	struct DataCity** cities = readDataFromCSV();
	struct Vector* regions = VectorCreate();
	for(int i = 0; i < CITY_NUMBER; i++){
		if(VectorFindData(regions, cities[i]->region) != -1){
			regions->data[i].sum += cities[i]->population;
			regions->data[i].frequency += 1;
		}else{
			struct Data* d = DataCreate(cities[i]->region, cities[i]->population);
			VectorAppend(regions, d);
			free(d);
		}
	}

	FILE* output = fopen("populacao_regiao.csv","w+");
	fprintf(output, "regiao,população media\n");
	for(int i = 0; i < regions->size; i++){
		fprintf(output,"%s,%lf\n", regions->data[i].name,
				regions->data[i].sum/(double)regions->data[i].frequency);
	}
	fclose(output);
}


