#include "Spaceship.h"

typedef struct BattleSimulation_struct *BattleSimulation;

typedef struct BattleSimulation_struct {
	Spaceship s1;
	Spaceship s2;
	int rounds;
	int battleOver;
	int maxRounds;
} BattleSimulation_struct;

int initializeBattle(BattleSimulation battle, int maxRounds, int battleNum);

void free_battlesim(BattleSimulation self);
