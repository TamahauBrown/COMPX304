/**
* @author Panos Patros
**/

#include <stdio.h>
#include <stdlib.h>
#include "Record.h"

int
main(){
    Record lastRecord;
int i = 0;
	while(i < 100) {
        Record currentRecord;
		BattleSimulation battle;

		battle = (BattleSimulation) malloc(sizeof(BattleSimulation_struct));
        currentRecord = (Record) malloc(sizeof(record_struct));
		//if(i > 0) {*(currentRecord) = *(Record)(currentRecord+i);}
        //currentRecord = (currentRecord+i);
		if(battle == NULL){
			printf("Malloc failed for s1!\n");
			return 1;
		}
        printf("record"); fflush(stdout);
		initializeRecord(currentRecord, battle, battle->s1->health_points, battle->s2->health_points);
		printf("record"); fflush(stdout);
		//Print info
		//print_spaceship(s1);
		//print_spaceship(s2);

		//initializeBattle(battle, 10, i);

		//This line breaks the loop
		//addResult(currentRecord, battle, battle->winner, battle->rounds);

		if(i > 0) {
                setNextValue(lastRecord, currentRecord);
                //free_record(lastRecord);
                //lastRecord = (Record) malloc(sizeof(record_struct));
		}

		lastRecord = currentRecord;

		//free_record(currentRecord);
		i++;
	}
}
