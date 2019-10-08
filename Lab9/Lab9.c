#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int
main(int argc, char *argv[])
{

DIR *dirp;
DIR *homeDir;
DIR *dir;
struct dirent* dp;
char buff[1000];
struct stat sb;
char *name = ".";
char directory[1000] = "/home/tmmb1/300Level/";
char *homeLoc = "/home/tmmb1/300Level/";

//Gets all the files in the directory
dirp = opendir("/home/tmmb1/300Level");
homeDir = opendir("/home/tmmb1/300Level");

printf("Current files in this directory: \n");
while (dirp) {
    if ((dp = readdir(dirp)) != NULL) {
        //printf("Directory name: %s\n", dp->d_name);
	if (strncmp(dp->d_name, name, 1) != 0){ 
		printf("Directory name: %s\n", dp->d_name);
		char * str3 = (char *) malloc(1 + strlen(directory)+ strlen(dp->d_name));
      		strcpy(str3, directory);
      		strcat(str3, dp->d_name);
      		printf("%s\n", str3);

		   //Did not input a value for the file
	   //if (argc != 2) {
	        //fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
	        //exit(EXIT_FAILURE);
	   //}
	   //No such file
	   if (stat(str3, &sb) == -1) {
	        perror("stat");
	        exit(EXIT_FAILURE);
	   }
	int *lastEdit = ctime(&sb.st_mtime);
	//Trying to get it to check if last edit was in the last 6 months
	if(lastEdit < 262800) {
	   printf("File type:                %s\n", str3);
	
	   switch (sb.st_mode & S_IFMT) {
		    case S_IFBLK:  printf("block device\n");            break;
		    case S_IFCHR:  printf("character device\n");        break;
		    case S_IFDIR:  printf("directory\n");               break;
		    case S_IFIFO:  printf("FIFO/pipe\n");               break;
		    case S_IFLNK:  printf("symlink\n");                 break;
		    case S_IFREG:  printf("regular file\n");            break;
		    case S_IFSOCK: printf("socket\n");                  break;
		    default:       printf("unknown?\n");                break;
	    }

	   printf("Last status change:       %s", ctime(&sb.st_ctime));
	    printf("Last file access:         %s", ctime(&sb.st_atime));
	    printf("Last file modification:   %s", ctime(&sb.st_mtime));

	   //dirp = opendir(".");

	}

	   //exit(EXIT_SUCCESS);
	}
    }
    else { break; }
}
}
//closedir(dirp);



