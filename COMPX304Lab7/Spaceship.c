/**
* @author Panos Patros
**/

#include "Spaceship.h"
#include <stdio.h> /*printf*/
#include <stdlib.h> /*rand*/
#include <string.h> /*strncpy, strlen*/

int
init_spaceship(Spaceship self, char *name){
	int name_length = strlen(name);
	self->name = malloc(name_length + 1);
	if(self->name == NULL){
		/*Malloc failed*/
		return -1;
	}
	strncpy(self->name, name, name_length);

	self->health_points = rand()%21 + 80;
	self->attack_points = rand()%11 + 10;
	self->defense_points = rand()%6 + 5;

	return 0;
}


/////////////////////////////////////////////////////////////


void
attack_spaceship(Spaceship self, Spaceship underAttack){
	int damage = calculate_attack_power_spaceship(self);
	int num = 0;
	//Do damage
	if(damage > (underAttack)->defense_points) {
		num = damage - (underAttack)->defense_points;
		(underAttack)->health_points =  (underAttack)->health_points - num;
	}
	//printf("\n %s did %d damage to %s \n %s Health: %d \n", self->name, num, underAttack->name, underAttack->name, (underAttack)->health_points);
}


/////////////////////////////////////////////////////////////


int
calculate_attack_power_spaceship(Spaceship self){
        int damage = 0;

	//Making it the that it gets full damage
	int hitChance = rand()%100;

	//This is what happens when gets full damage
	if(hitChance > 49) {
		damage = self->attack_points;
	}
	//Otherwise does half the damage
	else
	{
		damage = self->attack_points/2;
	}
	return damage;
}

int
is_destroyed_spaceship(Spaceship self){
       //Check if spaceship is destroyed, the battle ends and declares it has been destroyed
	if(self->health_points <= 0) 
	{
		 printf("Spaceship %s has been destroyed \n", self->name);
		 return 1;
	}
	return 0;
}

void
print_spaceship(Spaceship self){
	printf("%s: %d (HP), %d (AP), %d (DP)\n", self->name, self->health_points, self->attack_points, self->defense_points);
}

void
free_spaceship(Spaceship self){
	free(self->name);
	free(self);
}
