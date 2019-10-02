/*#include <sys/types.h>
#include <dirent.h>

int main() {
	DIR *opendir(const char *name);
	DIR *fdopendir(int fd);
}
*/
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
DIR *dir;
struct dirent* dp;
//dp = (dirent) malloc(sizeof(dirent));
char buff[1000];
//strcpy(buff, argv[0]);
//dir = opendir(buff);
int errno = 0;
char *name = "";

    struct stat sb;
//Segmentation fault
  dirp = opendir(".");
while (dirp) {
    errno = 0;
    if ((dp = readdir(dirp)) != NULL) {printf("HI\n");
        if (strncmp(dp->d_name, name, 6) == 0) {
            printf("Directory name: %s\n", dp->d_name);
        }printf("Directory name: %s\n", dp->d_name);
    } else {
        if (errno == 0) {
	    //printf("%s", dirp);
            closedir(dirp);
            //return NOT_FOUND;
        }
        //return READ_ERROR;
    //return;
    }
    //Update dirp to do something else lol
    closedir(dirp);
}
   if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

   if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

   printf("File type:                ");

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

   printf("I-node number:            %ld\n", (long) sb.st_ino);

   printf("Mode:                     %lo (octal)\n",
            (unsigned long) sb.st_mode);

   printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
            (long) sb.st_uid, (long) sb.st_gid);

   printf("Preferred I/O block size: %ld bytes\n",
            (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
            (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
            (long long) sb.st_blocks);

   printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));

   //dirp = opendir(".");



   exit(EXIT_SUCCESS);
}

