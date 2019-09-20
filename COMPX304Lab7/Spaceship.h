/**
* @author Panos Patros
**/

typedef struct Spaceship_struct *Spaceship;

typedef struct Spaceship_struct {
	char *name;
	int health_points;
	int attack_points;
	int defense_points;
} Spaceship_struct;

int
init_spaceship(Spaceship self, char *name);

void
attack_spaceship(Spaceship self, Spaceship underAttack);

int
calculate_attack_power_spaceship(Spaceship self);

int
is_destroyed_spaceship(Spaceship self);

void
print_spaceship(Spaceship self);

void
free_spaceship(Spaceship self);
