/**
** @Author Panos Patros
** 
** Code that contains numerous vulnerabilities 
**/

#include<stdio.h>
#include<string.h>

typedef struct {
	char username[8];
	char pin[8];
	int isAdmin;
	int pinChecked;
} AuthorizationRecord;

int
getAuthorizationLevel(){
	AuthorizationRecord authRec;
	
	printf("Username: ");
	scanf("%s", authRec.username);

	if(strncmp(authRec.username, "admin", 5)){
		authRec.isAdmin = 1;
	} else {
		authRec.isAdmin = 0;
	}
	
	printf("Pin: ");
	
	scanf("%s", authRec.pin);
	
	if(strncmp(authRec.pin, "1234", 4)){
		authRec.pinChecked = 1;
	} else {
		authRec.pinChecked = 0;
	}

	printf("%u \n %u\n", authRec.isAdmin, authRec.pinChecked);

	if(authRec.pinChecked){
		if(authRec.isAdmin){
			return 2;
		}
		return 1;
	}
	return 0;
}

int
main(){
	int authorizationLevel;

	authorizationLevel = getAuthorizationLevel();

	if (authorizationLevel == 1) {
		printf("Access Granted.\n");
	} else if (authorizationLevel == 2) {
		printf("Priviliged Access Granted!!\n");
	} else {
		printf("Access Denied!\n");
	}

	return 0;
}
