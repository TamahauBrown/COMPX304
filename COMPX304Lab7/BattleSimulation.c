/**
* @author Panos Patros
**/

#include <stdio.h>
#include <stdlib.h>
#include "BattleSimulation.h"


int initializeBattle(BattleSimulation battle, int maxRounds, int battleNum){

	printf("\nBattle: %d\n", battleNum);
	battle->s1 = (Spaceship) malloc(sizeof(Spaceship_struct));
	if(battle->s1 == NULL){
		printf("Malloc failed for s1!\n");
		return 1;
	}

	battle->s2 = (Spaceship) malloc(sizeof(Spaceship_struct));
	if(battle->s2 == NULL){
		printf("Malloc failed for s2!\n");
		return 1;
	}


	//Create USS Enterprise
	init_spaceship(battle->s1, "USS Enterprise");

	//Create a Borg Cube
	init_spaceship(battle->s2, "A Borg Cube");
	battle->maxRounds = maxRounds;

	while(battle->rounds < battle->maxRounds && battle->battleOver != 1) {
			attack_spaceship(battle->s1, battle->s2);

			battle->battleOver = is_destroyed_spaceship(battle->s2);
			if(battle->battleOver == 1) {
                battle->winner = 1;
				break;
			}

			attack_spaceship(battle->s2, battle->s1);
			battle->battleOver = is_destroyed_spaceship(battle->s1);
			if(battle->battleOver == 1) {
                battle->winner = 2;
				break;
			}
			battle->rounds++;
	}
	if(battle->rounds >= battle->maxRounds)
	{
		//printf("Draw");
	}
	//printf("\nS1 HP: %d \nS2 HP: %d\nRounds: %d\n",battle->s1->health_points, battle->s2->health_points,battle->rounds);
}

void
free_battlesim(BattleSimulation self){
	free_spaceship(self->s1);
	free_spaceship(self->s2);
	free(self);
}
