#include "city_data.h"
#include "vector.h"
#include "data.h"

int main(){
	struct DataCity** cities = readDataFromCSV();
	struct Vector* states = VectorCreate();
	for(int i = 0; i < CITY_NUMBER; i++){
		if(VectorFindData(states, cities[i]->state) != -1){
			states->data[i].sum += cities[i]->population;
			states->data[i].frequency += 1;
		}else{
			struct Data* d = DataCreate(cities[i]->state, cities[i]->population);
			VectorAppend(states, d);
			free(d);
		}
	}

	FILE* output = fopen("populacao_estado.csv","w+");
	fprintf(output, "estado,população media\n");
	for(int i = 0; i < states->size; i++){
		fprintf(output,"%s,%lf\n", states->data[i].name,
				states->data[i].sum/(double)states->data[i].frequency);
	}
	fclose(output);
}


