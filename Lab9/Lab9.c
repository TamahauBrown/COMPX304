#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int process(char *directory)
{
DIR *dirp;
DIR *homeDir;
DIR *dir;
struct dirent* dp;
char buff[1000];
struct stat sb;

char *name = ".";
char *homeLoc = "/home/tmmb1/300Level";
//Gets all the files in the directory
dirp = opendir(directory);
 time_t now = time(0);


while (dirp) {
    if ((dp = readdir(dirp)) != NULL) {
        //printf("Directory name: %s\n", dp->d_name);
	if (strncmp(dp->d_name, name, 1) != 0){ 
		printf("Directory name: %s\n", dp->d_name);
		char * str3 = (char *) malloc(1 + strlen(directory)+ strlen(dp->d_name));
		strcpy(str3, directory);
		strcat(str3, "/");
      		strcat(str3, dp->d_name);
      		printf("%s\n", str3);

	   //No such file
	   if (stat(str3, &sb) == -1) {
	        perror("stat");
	        exit(EXIT_FAILURE);
	   }

	   double difference = difftime(now, sb.st_mtime);
	   //printf("The time difference is %lf\n", difference);
	   //Checks it has been less than 6 months
	   if((difference < 15778476 && S_ISREG(sb.st_mode)) || (S_ISDIR(sb.st_mode) && difference < 15778476 * 2)) {
	   printf("File type:                %s\n", str3);
	
	  /* switch (sb.st_mode & S_IFMT) {
		    case S_IFBLK:  printf("block device\n");            break;
		    case S_IFCHR:  printf("character device\n");        break;
		    case S_IFDIR:  printf("directory\n");               break;
		    case S_IFIFO:  printf("FIFO/pipe\n");               break;
		    case S_IFLNK:  printf("symlink\n");                 break;
		    case S_IFREG:  printf("regular file\n");            break;
		    case S_IFSOCK: printf("socket\n");                  break;
		    default:       printf("unknown?\n");                break;
	    }*/
	
	    if(S_ISDIR(sb.st_mode)) { process(str3); }
	    if((sb.st_mode & S_IROTH) && S_ISREG(sb.st_mode)) { 
		printf("Others have permission to read this file \n"); 
            }
	    if((sb.st_mode & S_IXOTH) && S_ISREG(sb.st_mode)) { 
		printf("Others have permission to execute this file \n");
	    }
	   //figure out permission type
	   //int permission = chmod (str3, sb.st_mode);
	   //printf("Status: 		     %o\n",  sb.st_mode);
	   printf("Last status change:       %s", ctime(&sb.st_ctime));
	   printf("Last file access:         %s", ctime(&sb.st_atime));
	   printf("Last file modification:   %s", ctime(&sb.st_mtime));
	   //dirp = opendir(directory);
	}
	}
	   
    }
    else { break; }
}
}

int
main(int argc, char *argv[])
{
printf("Current files in this directory: \n");
process("/home");
}
//closedir(dirp);

