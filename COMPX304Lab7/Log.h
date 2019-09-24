#include "Record.h"

typedef struct log_struct *Log;

typedef struct log_struct {
	Record records;
} log_struct;

int getRecord(Log self, Record rec);
//int initializeRecord(Record self, BattleSimulation sim, Spaceship s1, Spaceship s2);
//Makes the first one, make 2nd one null
int displayRecords(Record rec, int loops);

void free_log(Log self, Record rec);
