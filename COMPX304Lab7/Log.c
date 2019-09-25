#include <stdio.h>
#include <stdlib.h>
#include "Log.h"

int getRecord(Log self, Record rec){
    self->records = rec;
}
int displayLogs(Log self, int loops){
    for(int i = 0; i < loops; i++) {
    printf("Battle: %d\n", i);
    printf("\nHealth of the ships: \n USS Enterprise's HP: %d \n A Borg Cube's HP: %d \n Result: ", self->records->s1Health, self->records->s2Health);
           if(self->records->result == 1) { printf("USS Enterprise won\n"); }
           else { printf("A Borg Cube won\n"); }
           printRounds(self->records);
	   Record n = self->records->next;
	   if(i > 0) {
	   free_record(self->records); }
	   self->records = n;
    }
}

void free_log(Log self)
{
    free(self);
}
