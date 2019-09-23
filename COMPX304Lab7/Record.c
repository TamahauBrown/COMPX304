#include <stdio.h>
#include <stdlib.h>
#include "Record.h"

int initializeRecord(Record self, BattleSimulation sim, int s1Hp, int s2Hp){
    self->sim = sim;
    printf("1"); fflush(stdout);
    self->s1Health = s1Hp;
    printf("2"); fflush(stdout);
    self->s2Health = s2Hp;
}

int addResult(Record self, BattleSimulation sim, int result, int rounds){
    self->sim = sim;
    self->result = result;
    self->roundsLasted = rounds;
}

void setNextValue(Record r1, Record r2){
    r1->next = r2;
    printf("Next location: %p from %p\n", r1->next, r1);
}

void free_record(Record self){
    free_battlesim(self->sim);
	free(self);
}
