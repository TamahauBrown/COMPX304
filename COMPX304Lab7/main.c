/**
* @author Panos Patros
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Log.h"

int
main(){
    Log log;
    Record lastRecord;
	Record currentRecord;
	int i = 0;
	srand(time(NULL));
	log = (Log) malloc(sizeof(record_struct));
	while(i < 100) {
		BattleSimulation battle;

		battle = (BattleSimulation) malloc(sizeof(BattleSimulation_struct));
        currentRecord = (Record) malloc(sizeof(record_struct));

		//if(i > 0) {*(currentRecord) = *(Record)(currentRecord+i);}
        	//currentRecord = (currentRecord+i);
		if(battle == NULL){
			printf("Malloc failed for s1!\n");
			return 1;
		}
		createShips(battle);
		initializeRecord(currentRecord, battle, battle->s1,battle->s2);

		//Print info
		//print_spaceship(battle->s1);
		//print_spaceship(battle->s2);

		initializeBattle(battle, 10, i);

		//This line breaks the loop
		addResult(currentRecord, battle, battle->winner, battle->rounds);

		if(i > 0) {
                	setNextValue(lastRecord, currentRecord);
                	//free_record(lastRecord);
                	//lastRecord = (Record) malloc(sizeof(record_struct));
		}
		else { getRecord(log, currentRecord); }

		//This method is breaking
		lastRecord = currentRecord;
		i++;
	}
	displayLogs(log, 100);
	free_log(log);
}
