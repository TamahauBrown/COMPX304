/**
* @author Panos Patros
**/

#include <stdio.h>
#include <stdlib.h>
#include "Record.h"

int
main(){
    Record currentRecord;
    Record lastRecord;
int i = 0;
	while(i < 100) {
		BattleSimulation battle;

		battle = (BattleSimulation) malloc(sizeof(BattleSimulation_struct));
		currentRecord = (Record) malloc(sizeof(record_struct));
		lastRecord = (Record) malloc(sizeof(record_struct));
		if(battle == NULL){
			printf("Malloc failed for s1!\n");
			return 1;
		}

		printf("Record: %p", currentRecord);
		initializeRecord(currentRecord, battle, battle->s1->health_points, battle->s2->health_points);
		if(i > 0) {
                setNextValue(lastRecord, currentRecord);
		}
		//Print info
		//print_spaceship(s1);
		//print_spaceship(s2);

		initializeBattle(battle, 30, i);

		lastRecord = currentRecord;

		i++;
	}
}
