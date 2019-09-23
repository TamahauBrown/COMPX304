#include "Spaceship.h"

typedef struct BattleSimulation_struct *BattleSimulation;

/*
    If winner == 1 then S1 Wins
    If winner == 2 then S2 Wins
*/

typedef struct BattleSimulation_struct {
	Spaceship s1;
	Spaceship s2;
	int rounds;
	int battleOver;
	int maxRounds;
	int winner;
} BattleSimulation_struct;

int initializeBattle(BattleSimulation battle, int maxRounds, int battleNum);

int createShips();

void free_battlesim(BattleSimulation self);
