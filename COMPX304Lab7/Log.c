#include <stdio.h>
#include <stdlib.h>
#include "Log.h"

int getRecord(Log self, Record rec){
    self->records = rec;
}
int displayLogs(Log self, int loops){
    printf("Health of the ships: \n %s HP: %d \n %s HP: %d \n Result: ", self->records->sim->s1->name, self->records->s1Health, self->records->sim->s2->name,
           self->records->s2Health);
           if(self->records->result == 1) { printf("USS Enterprise won\n"); }
           else { printf("A borg cube won\n"); }
           printf("Rounds lasted: %d\n", self->records->roundsLasted);
}

void free_record(Log self, Record rec);
