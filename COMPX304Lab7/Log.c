#include <stdio.h>
#include <stdlib.h>
#include "Log.h"

int getRecord(Log self, Record rec){
    self->records = rec;
}
int displayLogs(Log self, int loops){
    printf("Health of the ships: \n USS Enterprise's HP: %d \n A Borg Cube's HP: %d \n Result: ", self->records->s1Health,
           self->records->s2Health);
           if(self->records->result == 1) { printf("USS Enterprise won\n"); }
           else { printf("A Borg Cube won\n"); }
           printRounds(self->records);
           //printf("Rounds lasted: %d\n", self->records->roundsLasted);
}

void free_log(Log self)
{
    free(self);
    free_record(self->records);
}
