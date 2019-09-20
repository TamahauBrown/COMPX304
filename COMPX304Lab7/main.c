/**
* @author Panos Patros
**/

#include <stdio.h>
#include <stdlib.h>
#include "BattleSimulation.h"

int
main(){
int i = 0;
	while(i < 100) {
		BattleSimulation battle;

		battle = (BattleSimulation) malloc(sizeof(BattleSimulation_struct));
		if(battle == NULL){
			printf("Malloc failed for s1!\n");
			return 1;
		}
		//Print info
		//print_spaceship(s1);
		//print_spaceship(s2);

		initializeBattle(battle, 30, i);
		i++;
		
	}
}
