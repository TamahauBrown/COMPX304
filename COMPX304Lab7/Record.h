#include "BattleSimulation.h"

typedef struct record_struct *Record;

typedef struct record_struct {
	Record next;
	BattleSimulation sim;
	int result;
	int s1Health;
	int s2Health;
	int roundsLasted;
} record_struct;

//int initializeRecord(Record self, BattleSimulation sim, Spaceship s1, Spaceship s2);
//Makes the first one, make 2nd one null
int initializeRecord(Record self, BattleSimulation sim, Spaceship s1, Spaceship s2);

int addResult(Record self, BattleSimulation sim, int result, int rounds);

void setNextValue(Record r1, Record r2);

void free_record(Record self);

void printRounds(Record self);
